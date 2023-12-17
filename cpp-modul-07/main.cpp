
//ex01
#include "iter.hpp"

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}
//ex02
#include "Array.hpp"

int main()
{
    try
    {
        Array<std::string> arr(5);
        arr[0] = "rida";
        arr[5] = "OUALI";

        std::cout << "arr: " << arr[0] << std::endl;
        std::cout << "arr: " << arr[4] << std::endl;

        int * a = new int();
        std::cout << "display *a: " << *a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Array<std::string> arr(5);
        arr[0] = "RIDA";
        arr[4] = "ouali";

        std::cout << "arr: " << arr[0] << std::endl;
        std::cout << "arr: " << arr[4] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}