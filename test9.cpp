#include <iostream>
#include <vector>

class FJA {
  private :
    std::vector<int> data;
    std::vector<std::vector<int> > newData;
    std::vector<int> remain;
    std::vector<int> mainChine;
    std::vector<int> pend;
    std::vector<int>::iterator getBeginOfStack;
    std::vector<std::pair<std::vector<int>, std::vector<int> > > pairs;
  public :
    void setNumbers(std::string str) {
      int count = 0;
      int result = 0;
      int mes = 1;
      if (str[0] == '-')
        mes = -1;
      while (str[count]) {
        result = (result * 10) + (str[count] - 48);
        count++;
      }
      this->data.push_back(result * mes);
    }

    void displayNumbers() {
      for(std::vector<int>::iterator start = this->data.begin(); start < this->data.end(); start++) {
        std::cout << *start << " ";
      }
      std::cout << ";\n";
    }
    void displayNumbers(std::vector<int> & gg) {
      for(std::vector<int>::iterator start = gg.begin(); start < gg.end(); start++) {
        std::cout << *start << " ";
      }
    }

    void merge() {
      mergeAndSortPairs(this->data, 1);
    }

    void mergeAndSortPairs(std::vector<int> & vec, int size) {
      if (size * 2 > vec.size())
        return ;

      std::vector<std::pair<std::vector<int>, std::vector<int> > > pairs;

      std::vector<int> tmp;
      //push the odd umbers to tempory 
      if (vec.size() % 2 != 0) {
        int sizeLop = vec.size() - vec.size() % 2;
        for(; sizeLop != vec.size(); sizeLop++)
          tmp.push_back(vec[sizeLop]);
        vec.erase(vec.end() - (vec.size() % (size * 2)), vec.end());
      }
      // this->remain = tmp;
      int count = 0;
      while (count < vec.size()) {          
        std::vector<int> first, secnd;
        for(int i = count; i < count + size; i++)
          first.push_back(vec[i]);
        for(int i = count + size; i < count + (size * 2); i++)
          secnd.push_back(vec[i]);
        if (first.back() > secnd.back())
          std::swap(first, secnd);
        pairs.push_back(std::make_pair(first, secnd));
        count += size * 2;
      }

      vec.clear();
      //// Merge sorted pairs
      for (size_t i = 0; i < pairs.size(); i++) {
        std::vector<int>& subvector = pairs[i].first;
        std::vector<int>& ssubvector = pairs[i].second;
        for (size_t j = 0; j < size; j++)
          vec.push_back(subvector[j]);
        for (size_t j = 0; j < size; j++)
          vec.push_back(ssubvector[j]);
      }
      mergeAndSortPairs(vec, size * 2);
      std::vector<std::vector<int> > halfers;
      for(int count = 0; count < vec.size(); count += size * 2) {
        std::vector<int> f,s;
        for(int i = count; i < count + size; i++)
          f.push_back(vec[i]);
        for(int i = count + size; i < count + (size * 2); i++)
          s.push_back(vec[i]);
        halfers.push_back(f);
        halfers.push_back(s);
      }

      std::vector<std::vector<int> > mainChine;
      std::vector<std::vector<int> > pendchine;
      //push to ped and mainchine
      std::vector<std::vector<int> >::iterator halfStart = halfers.begin();
      int index = 0;
      for(; halfStart != halfers.end(); halfStart++) {
        if (index % 2 != 0)
            mainChine.push_back(*halfStart);
        else
          pendchine.push_back(*halfStart);
        index++;
      }
      if (tmp.size() > 0) {
        pendchine.push_back(tmp);
        std::cout << "PUSHED THE REMAIN TO THE TEMP" << std::endl;
      }
      
      // pendchine.push_back(tmp);
      this->displayNumbers(vec);
      std::cout << "\n";
      this->displayChineAndPend(mainChine, pendchine);
    }

    void displayChineAndPend(std::vector<std::vector<int> > & chine, std::vector<std::vector<int> > & pend) {
      std::vector<std::vector<int> >::iterator chineStart = chine.begin();
      std::vector<std::vector<int> >::iterator pendStart = pend.begin();
      std::cout << "MAINCHINE : ";
      for(; chineStart != chine.end(); chineStart++) {
        std::vector<int> & temp = *chineStart;
        for(std::vector<int>::iterator start = temp.begin(); start != temp.end(); start++)
          std::cout << *start << " ";
      }
      std::cout << "\n";
      std::cout << "PEND      : ";
      for(; pendStart != pend.end(); pendStart++) {
        std::vector<int> & temp = *pendStart;
        for(std::vector<int>::iterator start = temp.begin(); start != temp.end(); start++)
          std::cout << *start << " ";
      }
      std::cout << "\n";
    }
};


int main(int argc, char **argv) {
  int count = 1;
  FJA fja;
  while (argv[count]) {
    fja.setNumbers(argv[count]);
    count++;
  }
  fja.merge();
  // fja.displayNumbers();
  return 0;
}
