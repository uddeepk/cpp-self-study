#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

//WAP to find if 2 arrays, and 2 vectors are equal

bool test (string a []  , string b[]  , string * ae , string *be) {
  auto ita = a;//begin(a);
  auto itae = ae;//end (a);
  auto itb = b;//begin(b);
  auto itbe = be;//end(b);
  if( (itae-ita) == (itbe-itb) ) { //means size not equal. could only use pointers... is there another way ?
    while ( ita != itae && itb != itbe) {
      if( *ita != *itb) {
	return false;
      }
      ++ita;
      ++itb;
    }
    return true;
  }
  
  return false;
}
int main () {
  string sarr1 [6] = { "aaa" , "bbb" , "ccc" , "ddd" , "eee" , "fff" };
  string sarr2 [6] = { "aaaa" , "bbb" , "ccc" , "ddd" , "eee" , "fff" };

  vector <string> svec1 = { "abc", "def" , "ghi" , "jkl","mno", "pqr"};
  vector <string> svec2 = {"abc", "def" , "ghi" , "jkl","mno", "pqr"};

  //cout << (sarr1 == sarr2) << endl; // does direct comparison between arrays not work ?
  // Looked up and it doesn't work for arrays, thus we have to check each element of the array individually
  //cout << checkArrEqual(sarr1, sarr2)  <<endl; //coutldn't figure out how to pass array to a function
  //Reading found out have to send the size too
  //bool checkArrEquals;
  //if(size(sarr1) !=  size(sarr2)) {
  //}
  //cout << sarr1.sizeof() << endl;// notice array.size, and size(array) do not work ???
  cout << test(sarr1 , sarr2 , end(sarr1) , end(sarr2)) <<endl; //screw arrayws......!!
  cout << (svec1 == svec2) << endl;
  return 0;
}
