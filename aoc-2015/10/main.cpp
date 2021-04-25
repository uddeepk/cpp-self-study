#include <iostream>
#include <regex>

std::string lookAndSay (  std::string s) ;

using std::string;

int main() {
    std::string testString {"3113322113"};
    for ( int i = 0 ; i < 40; ++i) {
        testString = lookAndSay(testString);
    }
    std::cout << "Star 1: " << testString.length() << "\n";
    for ( int i = 0 ; i < 10; ++i) {
        testString = lookAndSay(testString);
    }
    std::cout << "Star 2: " << testString.length() << "\n";
    return 0;
}

string lookAndSay ( std::string s) {
    std::string retStr;
    std::regex e ("(1+|2+|3+|4+|5+|6+|7+|8+|9+)");

    std::regex_iterator<std::string::iterator> rit ( s.begin(), s.end(), e);
    std::regex_iterator<std::string::iterator> rend;
    while ( rit != rend) {
        retStr += std::to_string(rit->str().length()) + rit->str()[0];
        ++rit;
    }
    return retStr;
}