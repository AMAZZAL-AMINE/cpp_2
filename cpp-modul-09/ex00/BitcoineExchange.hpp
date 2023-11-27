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
  float         value;
  int           type;
} t_data_input;

class BitcoineExchange {
    private :
      std::string fileName;
      std::multiset<t_data_input> dataContainer;
      std::ifstream fileObj;
      std::string parseDate(std::string & line, int counter, int isdb);
      std::string parseValue(std::string & line, int counter, int isdb);
      long dateToDecimal(std::string  & str);
      bool isCorrectLine(std::string & str, int isdb);
    public :
      BitcoineExchange();
      BitcoineExchange(BitcoineExchange const &src);
      BitcoineExchange &operator=(BitcoineExchange const &src);
      ~BitcoineExchange();
      BitcoineExchange(std::string file);
      void push_to_vector(std::multiset<double> & set, BitcoineExchange & bitcoin);
      void open(std::string file);
      void parse(int isdb);
      void push(t_data_input & data);
      void display();
      void getPriceOfDay(BitcoineExchange & bitcoin);
  };

#endif