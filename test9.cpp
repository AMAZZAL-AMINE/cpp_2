#include <iostream>
#include <vector>
#include <queue>

int comparizonCound = 0;

int compare(const std::vector<int> & a, const  std::vector<int> & b) {
  comparizonCound++;
  return (a.back() < b.back());
}


std::vector<int> jacobsthalGenerator(int max) {
  std::vector<int> J;
  int count = 2;
  int result = 0;
  J.push_back(0);
  J.push_back(1);
  while (result <= max) {
    int re = J[count - 1] + (2 * J[count - 2]);
    J.push_back(re);
    result = re;
    count++;
  }
  J.erase(J.begin());
  J.erase(J.begin());
  return J;
}

class FJA {
  private :
    std::vector<int> data;
    std::queue<int> queue;
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
      mergeAndSortPairsVector(this->data, 1);
    }

    void mergeAndSortPairsVector(std::vector<int> & vec, int size) {
      if (size * 2 > vec.size())
        return ;

      std::vector<std::pair<std::vector<int>, std::vector<int> > > pairs;

      std::vector<int> tmp;
      //push the odd umbers to tempory 
      if (vec.size() % (size * 2) != 0) {
        int sizeLop = vec.size() - size;
        tmp.insert(tmp.begin(), vec.end() - size, vec.end());
        vec.erase(vec.end() - size, vec.end());
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
        comparizonCound++;
        if (first.back() > secnd.back()) {
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
      mergeAndSortPairsVector(vec, size * 2);
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
      //jacobsthal generator 
      std::vector<int> penTmp;
      std::vector<int> __unused jacobsthal = jacobsthalGenerator(pendchine.size());
      if (tmp.size() > 0) 
        pendchine.push_back(tmp);
    //push the remain to the pendchin
      int i = 0;
      int amin = 0;
      int prev = 0;
      while (i < jacobsthal.size())
      {
        int jacob = jacobsthal[i];

        while (jacob > prev)
        {
          if (jacob - 1 < pendchine.size())
          {
            if (jacob - 1 == 0)
            {
              mainChine.insert(mainChine.begin(), pendchine[0]);
              amin++;
            }
            else
            {
              std::vector<int> original = pendchine[jacob - 1];
              std::vector<std::vector<int> >::iterator position = lower_bound(mainChine.begin(), mainChine.begin() + jacob + amin - 1, original, compare);
              mainChine.insert(position, original);
              amin++;
            }
            jacob--;
          }
          else
            jacob = pendchine.size();
        }
        prev = jacobsthal[i];
        i++;
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
    }
    
};

int main(int argc, char **argv) {
  int count = 1;
  FJA fja;
  while (argv[count]) {
    fja.setNumbers(argv[count]);
    count++;
  }
  std::cout << "Before: ";
  fja.displayNumbers();
  double VectorStart = std::clock();
  fja.merge();
  double VectorEnd = std::clock();
  std::cout << "After: ";
  fja.displayNumbers();
  std::cout << "\n";
  std::cout << "Time to process a range of " << "5" << " elements with std::vecotr : 0.0" << VectorEnd - VectorStart << " us\n";
  // std::cout << "CONPARIZION : " << comparizonCound << "\n";
  return 0;
}
