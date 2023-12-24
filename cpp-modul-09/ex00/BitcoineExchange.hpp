#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "main.h"

#ifndef NEGATIVE_
#define NEGATIVE_     402
#endif
#ifndef BADE_INPUT_
#define BADE_INPUT_   404
#endif
#ifndef LARGE
#define LARGE         501
#endif
#ifndef DEFAULT
#define DEFAULT         1
#endif


typedef struct t_data_input {
  std::string   date;
  long          dateInDecimal;
  double         value;
  int           type;
  std::string   fullDate;
} t_data_input;

class BitcoineExchange {
    private :
      int mapSize;
      std::string fileName;
      std::map<long, t_data_input> dataContainer;
      std::map<long, t_data_input> database;
      std::ifstream fileObj;

      std::string parseDate(std::string & line, int counter, int isdb);
      std::string parseValue(std::string & line, int counter, int isdb);
      long dateToDecimal(std::string  & str);
      bool isCorrectLine(std::string & str, int isdb);
      bool checkPipe(std::string & str);
      bool checkDate(std::string & str);
      bool checkCharcters(std::string & str);
      bool checkDateRange(std::string & date);
    public :
      BitcoineExchange();
      BitcoineExchange(BitcoineExchange const &src);
      BitcoineExchange &operator=(BitcoineExchange const &src);
      ~BitcoineExchange();
      void parseDataBase(std::string & file);
      BitcoineExchange(std::string file);
      void open(std::string file);
      void parse(int isdb,  std::map<long, t_data_input> & bitcoin);
      void push(t_data_input & data,  std::map<long, t_data_input> & bitcoin, int isbtc);
      void display();
      void getPriceOfDay(BitcoineExchange & bitcoin);
      std::map<long, t_data_input> getDatabase();
  };

#endif