#include "BitcoineExchange.hpp"

BitcoineExchange::BitcoineExchange() {this->mapSize = 0;}
BitcoineExchange::BitcoineExchange(BitcoineExchange const __unused &src){
  *this = src;
}
BitcoineExchange & BitcoineExchange::operator=(BitcoineExchange const __unused &src){
  if (this != &src) {
    this->fileName = src.fileName;
    this->dataContainer = src.dataContainer;
  }
  return *this;
}
BitcoineExchange::~BitcoineExchange() {}

BitcoineExchange::BitcoineExchange(std::string fileName) {
  this->mapSize = 0;
  this->open(fileName);
}

void BitcoineExchange::open(std::string fileName) {
  this->fileObj.open(fileName);
  if (!this->fileObj)
    throw std::string("Exception Error : fail to open file");
}

std::string BitcoineExchange::parseDate(std::string & line, int counter, int isdb) {
  std::string date = "";
  size_t i = 0;

  if (counter == 0 && (!isdb && line != "date | value"))
    throw std::string("Exeption Error : input file must start with : date | value");
  while (i < line.length() && counter >= 0) {
    if (!isdb && (line[i] == ' ' || line[i] == '|'))
      break;
    else if (isdb && line[i] == ',')
      break;
    else 
      date += line[i];
    i++;
  }
  return date;
}

bool BitcoineExchange::checkPipe(std::string & str) {
  int pipePosition = -1;
  int numberPipe  = 0;
  size_t i = -1;

  while (++i < str.length()) {
    if (str[i] == '|' ) {
      pipePosition = i;
      numberPipe++;
    }
  }
  if (numberPipe != 1 || pipePosition != 11)
    return 1;
  return 0;
}

bool BitcoineExchange::checkDate(std::string & str) {
  int moinsPosition = 0;

  size_t i = -1;

  while (++i < str.length() && str[i] != '|') {
    if (str[i] == '-')
      moinsPosition++;
    if (str[i] == '-' && moinsPosition == 1 && i != 4)
      return 1;
    if (str[i] == '-' && moinsPosition == 2 && i != 7)
      return 1;
  }
  if (moinsPosition != 2)
    return true;
  //check the - in the value (if it is a nigative number)
  i = str.length();
  while (--i && str[i] != '|')
    if ((str[i] == '-' || str[i] == '+') && ((i-1 > 0 && str[i-1] != ' ') || (str[i + 1] && !std::isdigit(str[i+1]))))
      return true;
  i = -1;
  moinsPosition = 0;
  //check spaces same as -
  while (++i < str.length()) {
    if (str[i] == ' ')
      moinsPosition++;
    if (str[i] == ' ' && moinsPosition == 1 && i != 10)
      return 1;
    else if (str[i] == ' ' && moinsPosition == 2 && i != 12)
      return 1;
  }
  if (moinsPosition != 2)
    return true;
  return false;
}

bool BitcoineExchange::checkCharcters(std::string & str) {
  size_t count = -1;
  while (++count < str.length()) {
    if (str[count] != '+' && str[count] != '-' && !std::isdigit(str[count]) && str[count] != ' ' && str[count] != '|' && str[count] != '.')
      return true;
    if (str[count] == '+' && count != 13)
      return true;
  }
  return false;
}


int toInt(std::string str) {
  int count = 0;
  int res = 0;
  while (str[count] != '\0') {
    if (std::isalpha(str[count])) {
      std::cout << "Invalid input" << std::endl;
      return -1;
    }
    res = res * 10 + str[count] - '0';
    count++;
  }
  return res;
}

bool BitcoineExchange::checkDateRange(std::string & date) {
  size_t count = 0;
  std::string year, month, day;

  while (count < date.length() && date[count] != '-')
    year += date[count++];
  count++;
  while (count < date.length() && date[count] != '-')
    month += date[count++];
  count++;
  while (count < date.length() && date[count] != ' ')
    day += date[count++];
  int _year, _month, _day;
  _year = toInt(year) ;
  _month = toInt(month);
  _day = toInt(day);

  if (year.length() != 4 || _year < 2009)
    return 1;
  if (month.length() != 2 || _month > 12 || _month < 1)
    return 1;
  if (day.length() != 2 || _day > 31 || _day < 1)
    return 1;
  return false;
}

bool BitcoineExchange::isCorrectLine(std::string & str, int __unused isdb) {
  if (!isdb && checkPipe(str))
    return 1;
  else if (!isdb && this->checkDate(str))
    return 1;
  else if (!isdb && this->checkCharcters(str))
    return 1;
  else if (!isdb && this->checkDateRange(str))
    return 1;
  return 0;
}

long BitcoineExchange::dateToDecimal(std::string  & str) {
  std::string tmp = "";
  size_t i = 0;
  while (i < str.length()) {
    if (str[i] != '-')
      tmp += str[i];
    i++;
  }
  return (std::strtod(tmp.c_str(), NULL));
}

std::string BitcoineExchange::parseValue(std::string & line, int counter, int isdb) {
  std::string date = "";
  size_t i;
  if (!isdb && this->isCorrectLine(line, isdb))
    return "";
  if (isdb)
    i = line.find(",");
  else
    i = line.find("|");
  if (i  > line.length())
    return "";
  i++;
  while (i < line.length() && counter >= 0) {
    date += line[i];
    i++;
  }
  return date;
}

void BitcoineExchange::parse(int isdb, std::map<long, t_data_input> & bitcoin) {
  t_data_input data;
  std::string value;
  std::string line;
  int counter = 0;
  if (this->fileObj.peek() == std::ifstream::traits_type::eof())
    throw std::string("Execption Error :  cannot reade from empty input");
  while (std::getline(this->fileObj, line)) {
    if (counter == 0 && (!isdb && line != "date | value"))
      throw std::string("Exeption Error : input file must start with : date | value");
    else if (counter == 0 && (isdb && line != "date,exchange_rate"))
      throw std::string("Exeption Error : input file must start with : date | value");
    if (counter > 0 && !line.empty()) {
      data.fullDate = line;
      data.date = this->parseDate(line, counter, isdb);
      value = this->parseValue(line, counter, isdb);
      data.type = DEFAULT;
      if (value == "") {
        data.type = BADE_INPUT_;
        data.value = 0;
      }else {
        try
        {
          data.dateInDecimal = dateToDecimal(data.date);
          double value_ = std::strtod(value.c_str(), NULL);
          if (value_ > 1000 && !isdb)
            data.type = LARGE;
          else if (value_ < 0)
            data.type = NEGATIVE_;
          else
            data.value = value_;
        }
        catch(const std::invalid_argument & e) {
          data.type = BADE_INPUT_;
        }
      }
      this->push(data, bitcoin, isdb);
    }
    counter++;
  }
 if ((!isdb && counter == 1))
  throw std::string("Ops, Can't search using undfined date or value");
}

void BitcoineExchange::push(t_data_input &  data,  std::map<long, t_data_input> & bitcoin, int isbtc) {
  if (isbtc)
    this->dataContainer[data.dateInDecimal] = data;
  else {
    if (data.type == DEFAULT) {
      std::map<long, t_data_input>::iterator result = bitcoin.lower_bound(data.dateInDecimal);
      if (result != bitcoin.end()) {
        if (result != bitcoin.begin() && result->second.dateInDecimal != data.dateInDecimal )
          --result;
        t_data_input result_ = result->second;
        std::cout << data.date << " => " << data.value << " = " << data.value * result_.value << std::endl;
      }else {
        t_data_input result_ = bitcoin.rbegin()->second;
        std::cout << data.date << " => " << data.value << " = " << result_.value * data.value  << std::endl;
      }
    }else if (data.type == NEGATIVE_)
      std::cout << "Error: not a positive number." << std::endl;
    else if (data.type == BADE_INPUT_)
      std::cout << "Error: bad input => " + data.fullDate << std::endl;
    else if (data.type == LARGE)
      std::cout << "Error: too large a number." << std::endl;
  }
}


void checkDataBase(std::string & line) {
  int countPoint = 0;
  for(size_t i = 0; i < line.length(); i++) {
    if (line[i] == ',') {
      if (i != 10)
        throw std::string("Exeption Error : you are not allowed to change the date format");
    }
    else if (line[i] == '.')
      countPoint++;
    else if (line[i] == '-') {
      if (i != 4 && i != 7)
        throw std::string("Exeption Error : you are not allowed to change the date format");
    }else if (!std::isdigit(line[i]))
      throw std::string("Exeption Error : you are not allowed to change the date format");
  }
  if (countPoint > 1)
    throw std::string("Exeption Error : you are not allowed to change the date format");
}

void BitcoineExchange::parseDataBase(std::string & file) {
  std::string line;
  std::ifstream filedb;
  filedb.open(file);
  if (filedb.peek() == std::ifstream::traits_type::eof())
    throw std::string("Exception Error : fail to open file");
  while (std::getline(filedb, line)) {
    if (line.empty())
      throw std::string("Exeption Error : please check the database file");
    if (line == "date,exchange_rate")
      continue;
    t_data_input data;
    checkDataBase(line);
    data.date = this->parseDate(line, 0, 1);
    data.value = std::stod(this->parseValue(line, 0, 1));
    data.dateInDecimal = dateToDecimal(data.date);
    this->database[data.dateInDecimal] = data;
  }
}

std::map<long, t_data_input> BitcoineExchange::getDatabase() {
  return this->database;
}
