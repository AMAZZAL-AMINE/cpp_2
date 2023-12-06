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

    void createPairs(std::vector<int> & vec, std::vector<std::vector<int> > & newData, int index) {
      if (index >= vec.size() - 1)
        return;
      int  first = vec[index];
      int  secnd = vec[index * 1];
      std::vector<int>  temp;
      temp.push_back(first);
      temp.push_back(secnd);
      std::sort(temp.begin(), temp.end());
      newData.push_back(temp);
      createPairs(vec, newData, index * 2);
      // mergePairs(newData);
    }

    void mergePairs(std::vector<std::vector<int> > & newData) {
      std::vector<int> temp;
      std::vector<int> next;

      std::vector<std::vector<int> >::iterator parrentStart = newData.begin();
      for(; parrentStart != newData.end(); parrentStart++) {
          if (parrentStart + 1 == newData.end())
            break;
          std::vector<int> & temp = *parrentStart;
          std::vector<int> & next = *(parrentStart + 1);
          if (temp[1] > next[0]) {
            std::swap(temp[1], next[0]);
            newData.erase(parrentStart + 1);
          }
      }
    }

    void merge() {
        std::cout << "\n";
        if (this->data.size() % 2 != 0) {
          this->remain.push_back(this->data.back());
          this->data.erase(--this->data.end());
        }
        std::cout << "STACK BEFOR : ";
        this->displayNumbers();
        turnVectorTopairs(this->data, 1);
        std::cout << "STACK AFTER : ";
        this->displayNumbers();
        std::cout << "MAINCHIN : ";
        for(int i=0; i < this->mainChine.size(); i++)
          std::cout << mainChine[i] << " ";
        std::cout << "\n";

        std::cout << "PEND : ";
        for(int i=0; i < this->pend.size(); i++)
          std::cout << this->pend[i] << " ";
        std::cout << "\n";

    }


    void turnVectorTopairs(std::vector<int> & vec, int size) {
      if (size * 2 > vec.size())
        return ;
      //save the last elemnt if the size if odd 
      std::vector<std::pair<std::vector<int>, std::vector<int> > > pairs;
      std::vector<int> tmp;
      //push the odd umbers to tempory 
      if (vec.size() % (size * 2) != 0) {
        for(int i = vec.size() - (vec.size() % 2); i < vec.size(); i++)
          tmp.push_back(vec[i]);
        vec.erase(vec.end() - (vec.size() % (size * 2)), vec.end());
      }

      //fill pairs
      for(int count = 0; count < vec.size(); count+= size*2) {
        std::vector<int> first, secnd;
        //   0 4 1 11 5 9 10 21 2555 23 75 26
        for(int i = count; i < count + size; i++)
          first.push_back(vec[i]);
        for(int i = count + size; i < count + size * 2; i++)
          secnd.push_back(vec[i]);
        if (first.back() > secnd.back())
          std::swap(first, secnd);
        pairs.push_back(std::make_pair(first, secnd));
      }

      //clear stsack
      vec.clear();
      //push back to stack  with new ordered numbers
      for (size_t i = 0; i < pairs.size(); i++)
      {
        std::vector<int>& subvector = pairs[i].first;
        std::vector<int>& ssubvector = pairs[i].second;
        for (size_t j = 0; j < size; j++)
          vec.push_back(subvector[j]);
        for (size_t j = 0; j < size; j++)
          vec.push_back(ssubvector[j]);
      }
      // this->displayNumbers();
      turnVectorTopairs(vec, size * 2);
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
  fja.displayNumbers();
  return 0;
}