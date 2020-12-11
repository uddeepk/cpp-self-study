#include <iostream>
#include "md5.h"
#include <map>
#include <sstream>
using std::cout; using std::endl;
using namespace std;


int main(int argc, char *argv[])
{
    cout << "md5 of 'grape': " << md5("grape") << endl;
    // Iterating so that I can get all the different output
    //ostringstream oss;
    string test = "yzbqklnj";
    map < string , string> m;
    for ( int i = 0 ; i < 1000000 ; ++i) {
        string num = to_string(i);
        string zeroes;
        if(num.length() == 6 ) {
            zeroes = "";
        }
        else {
            zeroes = (6-num.length() , '0');
        }
        //cout << test + zeroes + num << endl;
        string x = test + zeroes + num;
        m.insert( { x , md5(x)});
    }
    for ( auto it = m.begin() ; it != m.end () ; ++it ) {
        if(it->second.substr(0 , 5) == "00000") {
            cout << "star 1 : " << it->first << " \nYay!!" << endl;
            break;
        }
    }
    // Notice that when searched for six zeroes it is not in the star1 map. so
    m.clear();
    for ( int i = 1000000 ; i < 10000000 ; ++i) {
        string num = to_string(i);
        string zeroes;
        if(num.length() == 7 ) {
            zeroes = "";
        }
        else {
            zeroes = (7-num.length() , '0');
        }
        //cout << test + zeroes + num << endl;
        string x = test + zeroes + num;
        m.insert( { x , md5(x)});
    }

    for ( auto it = m.begin() ; it != m.end () ; ++it ) {
        if(it->second.substr(0 , 6) == "000000") {
            cout << "star 2 : " << it->first << " \nYay!!" << endl;
            break;
        }
    }
    //cout << m.begin()->first << endl;
    return 0;
}