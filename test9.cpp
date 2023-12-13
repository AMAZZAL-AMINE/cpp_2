#include <iostream>
#include <vector>

int comparizonCound = 0;

int compare(const std::vector<int> & a, const  std::vector<int> & b) {
  comparizonCound++;
  return (a.back() < b.back());
}


std::vector<int> jacobsthalGenerator(int max) {
  std::vector<int> J;
  int count = 0;
  J.push_back(0);
  J.push_back(1);
  while(count < max) {
     int re = J[count - 1] + (2 * J[count - 2]);
      if (re > 0)
        J.push_back(re);
    count++;
  }
  return J;
}

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
      if (vec.size() % (size * 2) != 0) {
        int sizeLop = vec.size() - size;
        tmp.insert(tmp.begin(), vec.end() - size, vec.end());
        vec.erase(vec.end() - size, vec.end());
        // for(int i  =0; i < tmp.size(); i++)
        //   std::cout << tmp[i] <<  " " ;
        // std::cout << "\n";
      }

      // spit the numbers into pairs as size * 2
      int count = 0;
      while (count < vec.size()) {          
        std::vector<int> first, secnd;
        int index = count - 1;
        while(++index < count + size)
          first.push_back(vec[index]);
        index = (count + size) - 1;
        while(++index < count + (size * 2))
          secnd.push_back(vec[index]);
        if (first.back() > secnd.back()) {
          comparizonCound++;
          std::swap(first, secnd);
        }
        pairs.push_back(std::make_pair(first, secnd));
        count += size * 2;
      }

      vec.clear();
      //// Merge pairs in ou collection again 
      for (size_t i = 0; i < pairs.size(); i++) {
        std::vector<int>& subvector = pairs[i].first;
        std::vector<int>& ssubvector = pairs[i].second;
        for (size_t j = 0; j < size; j++)
          vec.push_back(subvector[j]);
        for (size_t j = 0; j < size; j++)
          vec.push_back(ssubvector[j]);
      }
      //recursive 
      mergeAndSortPairs(vec, size * 2);
      //split the collection to parts
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
      //push to pend and mainchine
      std::vector<std::vector<int> >::iterator halfStart = halfers.begin();
      int index = 0;
      for(; halfStart != halfers.end(); halfStart++) {
        if (index % 2 != 0)
            mainChine.push_back(*halfStart);
        else
          pendchine.push_back(*halfStart);
        index++;
      }
      if (tmp.size() > 0)
        pendchine.push_back(tmp);
      //jacobsthal generator 
      std::vector<int> __unused jacobsthal = jacobsthalGenerator(pendchine.size());

      // sort the numbers using lower_bound
      if (pendchine.size() > 0) {
        mainChine.insert(mainChine.begin(), pendchine.front());
        for(int count  = 1; count <  pendchine.size(); count++) {
          std::vector<int>  penTmp = pendchine[count];
          std::vector<std::vector<int> >::iterator postion = lower_bound(mainChine.begin(), mainChine.end(), penTmp, compare);
          mainChine.insert(postion, penTmp);
        }
      }
      vec.clear();

      //push back the mainchine toe our collection
      if (mainChine.size() > 0) {
        for(std::vector<std::vector<int> >::iterator start = mainChine.begin(); start != mainChine.end(); start++) {
          std::vector<int> mainTemp = *start;
          for(int i = 0; i < mainTemp.size(); i++)
            vec.push_back(mainTemp[i]);
        }
      }
      // this->displayNumbers(vec);
      // std::cout << "\n";
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
  std::cout << "FINAL RESULT : ";
  fja.displayNumbers();
  std::cout << "\n";
  std::cout << "CONPARIZION : " << comparizonCound << "\n";
  return 0;
}
