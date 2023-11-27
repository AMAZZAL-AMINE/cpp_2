#include "BitcoineExchange.hpp"

BitcoineExchange::BitcoineExchange() {}
BitcoineExchange::BitcoineExchange(BitcoineExchange const __unused &src){}
BitcoineExchange & BitcoineExchange::operator=(BitcoineExchange const __unused &src){return *this;}
BitcoineExchange::~BitcoineExchange() {}

BitcoineExchange::BitcoineExchange(std::string fileName) {
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
  while (i < line.length() && counter > 0) {
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
    if (str[count] != '+' && str[count] != '-' && !std::isdigit(str[count]) && str[count] != ' ' && str[count] != '|')
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

  if (year.length() != 4 || _year > 2023 || _year < 2000)
    return 1;
  if (month.length() != 2 || _month > 31 || _month < 1)
    return 1;
  if (day.length() != 2 || _day > 12 || _day < 1)
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
  while (i < line.length() && counter > 0) {
      date += line[i];
    i++;
  }
  return date;
}

void BitcoineExchange::parse(int isdb) {
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
          double value_ = std::stod(value);
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
      this->push(data);
    }
    counter++;
  }
 if ((!isdb && counter == 1) || this->dataContainer.size() == 0)
  throw std::string("Ops, Can't search using undfined date or value");
}

void BitcoineExchange::push(t_data_input &  data) {
  this->dataContainer.insert(data);
}

void BitcoineExchange::display() {
  std::multiset<t_data_input>::iterator start = this->dataContainer.begin();
  while (start != this->dataContainer.end()) {
    std::cout << "Date  : " << start->date << std::endl;
    std::cout << "Value : " << start->value << std::endl;
    std::cout << "TYPE : " << start->type << std::endl;
    std::cout << "_____" << std::endl;
    start++;
  }
}

int loweBownRetrunCompar(const t_data_input& a, const t_data_input& b) {
  return a.dateInDecimal < b.dateInDecimal;
}

bool operator<(const t_data_input& lhs, const t_data_input& rhs) {
  return lhs.dateInDecimal < rhs.dateInDecimal;
}

void BitcoineExchange::getPriceOfDay(BitcoineExchange  & bitcoin) {
  (void)bitcoin;
  std::multiset<t_data_input>::iterator __unused inputStart = this->dataContainer.begin();
  t_data_input data;
  while (inputStart != this->dataContainer.end()) {
    data = *inputStart;
    if (data.type == NEGATIVE_)
      std::cout << "Error: not a positive number." << std::endl;
    else if (data.type == BADE_INPUT_)
      std::cout << "Error: bad input => " << data.fullDate << std::endl;
    else if (data.type == LARGE)
      std::cout << "Error: too large a number."  << std::endl;
    else {
        std::multiset<t_data_input>::iterator lowerBound = std::lower_bound(
        bitcoin.dataContainer.begin(), bitcoin.dataContainer.end(), data, loweBownRetrunCompar);

        if (lowerBound != bitcoin.dataContainer.end()) {
          t_data_input result = *lowerBound;
          std::cout << data.date << " => " << data.value << " = " << data.value * result.value << std::endl;
        }else {
          t_data_input result = *bitcoin.dataContainer.rbegin();
          std::cout << data.date << " => " << data.value << " = " << data.value * result.value << std::endl;
        }
    }
    inputStart++;
  }
}
