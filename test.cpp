#include <multiset>
#include <iostream>

typedef struct t_data {
  int a;
} t_data;

bool operator<(const t_data& lhs, const t_data& rhs) {
  return lhs.a < rhs.a;
}


int main() {
  std::multiset<t_data> gg;
  t_data dd;
  dd.a = 55555;
  gg.insert(dd);
  std::multiset<t_data, int>::iterator start = gg.begin();
  while (start != gg.end()) {
    t_data s = *start;
    std::cout << s.a << std::endl;
    start++;
  }
  return 0;
}
