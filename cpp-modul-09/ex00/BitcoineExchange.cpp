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


bool BitcoineExchange::isCorrectLine(std::string & str, int isdb) {
  size_t i = 0;
  int numberPipe  = 0;
  int numberMoins = 0;
  int foundError = 0;
  while (i < str.length()) {
    if (!isdb && str[i] == '|')
      numberPipe++;
    else if (!isdb && str[i] == '-')
      numberMoins++;
    else if (!isdb && !std::isdigit(str[i]))
      foundError++;
    i++;
  }
  if (numberMoins > 2 || numberPipe > 1 || foundError > 0)
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
  return (std::stod(tmp));
}

std::string BitcoineExchange::parseValue(std::string & line, int counter, int isdb) {
  std::string date = "";
  size_t i;
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
    if (counter > 0) {
      data.date = this->parseDate(line, counter, isdb);
      data.dateInDecimal = dateToDecimal(data.date);
      value = this->parseValue(line, counter, isdb);
      data.type = DEFAULT;
      if (value == "") {
          data.type = BADE_INPUT_;
          data.value = 0;
      }else {
        double value_ = std::stod(value);
        if (value_ > 1000 && !isdb)
          data.type = LARGE;
        else if (value_ < 0)
          data.type = NEGATIVE_;
        else
          data.value = value_;
      }
      this->push(data);
    }
    counter++;
  }
}

void BitcoineExchange::push(t_data_input &  data) {
  this->dataContainer.push_back(data);
}

void BitcoineExchange::display() {
  std::vector<t_data_input>::iterator start = this->dataContainer.begin();
  while (start != this->dataContainer.end()) {
    t_data_input data = *start;
    std::cout << "Date  : " << data.date << std::endl;
    std::cout << "Value : " << data.value << std::endl;
    std::cout << "TYPE : " << data.type << std::endl;
    std::cout << "_____" << std::endl;
    start++;
  }
}

int loweBownRetrunCompar(const t_data_input& a, const t_data_input& b) {
  return a.dateInDecimal < b.dateInDecimal;
}

void BitcoineExchange::getPriceOfDay(BitcoineExchange & bitcoin) {
  std::vector<t_data_input>::iterator __unused coinIteStart = bitcoin.dataContainer.begin();
  std::vector<t_data_input>::iterator __unused inputStart = this->dataContainer.begin();
        std::sort(bitcoin.dataContainer.begin(), bitcoin.dataContainer.end(), loweBownRetrunCompar);
  t_data_input data;
  while (inputStart != this->dataContainer.end()) {
    data = *inputStart;
    if (data.type == NEGATIVE_)
      std::cout << "Error: not a positive number." << std::endl;
    else if (data.type == BADE_INPUT_)
      std::cout << "Error: bad input => " << data.date << std::endl;
    else if (data.type == LARGE)
      std::cout << "Error: too large a number."  << std::endl;
    else {
        std::vector<t_data_input>::iterator lowerBound = std::lower_bound(
        bitcoin.dataContainer.begin(), bitcoin.dataContainer.end(), data, loweBownRetrunCompar);

        if (lowerBound != bitcoin.dataContainer.end()) {
          t_data_input result = *lowerBound;
          std::cout << data.date << " => " << data.value << " = " << data.value * result.value << std::endl;
        }
    }
    inputStart++;
  }
}
