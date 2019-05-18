
#include "V5Library.h"


EXPORTED char* (*hello)();

int main()
{
  V5Library lib("libtestLib");
    
  hello = (char* (*)())lib.GetFunction("hello");

  std::cout << hello() << std::endl;

  return 0;
}
