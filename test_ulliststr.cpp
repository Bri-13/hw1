#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
using namespace std;

int main(int argc, char* argv[])
{
  ULListStr test;
  //cout << "Pushing back" << endl;
  test.push_back("a");
  //cout << "Pushing back" << endl;
  test.push_back("there");
  test.push_front("hey");
  test.push_front("ho");
  cout << test.get(0) << endl;
  cout << test.get(1) << endl;
  cout << test.get(2) << endl;
  cout << test.get(3) << endl;
  //<< test.get(1) << " " << test.get(2);
  cout << "back: " << test.back() << endl;
  cout << "front: " << test.front() << endl;
  test.pop_back();
  cout << "back: " << test.back() << endl;

}
