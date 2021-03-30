#include <iostream>
#include <string>
#include <fstream>

bool niceRule1 ( const std::string &s ) ;
bool niceRule2 ( const std::string &s ) ;
bool niceRule3 ( const std::string &s ) ;

bool niceRuleNew1 ( const std::string &s);
bool niceRuleNew2 ( const std::string &s);

bool isNice (const std::string &s);
bool isNice2 (const std::string &s);

int main() {
    std::ifstream myFile ("input");
    std::string readBuffer;
    int star1 = 0, star2 = 0;
    while (getline(myFile, readBuffer)) {
        if (isNice(readBuffer))
            ++star1;
        if (isNice2(readBuffer))
            ++star2;
    }
    std::cout << "Star 1:" << star1 << "\n";
    std::cout << "Star 2:" << star2 << "\n";
    return 0;
}
bool niceRule1 ( const std::string &s ) {
    int vowels = 0;
    for (auto c : s) {
        switch (c) {
        case 'a' : case 'e' : case 'i': case 'o': case 'u' :
            ++vowels;
            break;
        }
        if (vowels >= 3)
            return true;
    }
    return false;
}

bool niceRule2 ( const std::string &s )  {
    // atleast one letter appears twice in a row.
    if ( s.length() == 1)
        return false;
    for ( size_t position = 0 ; position < s.length() - 1; ++position) {
        if(s[position] == s[position + 1])
            return true;
    }
    return false;
}
bool niceRule3 ( const std::string &s) {
    return ( s.find("ab") == std::string::npos &&
             s.find("cd") == std::string::npos &&
             s.find("pq") == std::string::npos &&
             s.find("xy") == std::string::npos );//&& s.find)
}

bool isNice(const std::string &s) {
    return niceRule3(s) && niceRule2(s) && niceRule1(s);
}
bool isNice2( const std::string &s) {
    return niceRuleNew1(s) && niceRuleNew2(s);
}
bool niceRuleNew1(const std::string &s) {
    // atleast one letter appears twice in a row.
    if ( s.length() == 1)
        return false;
    for ( size_t position = 0 ; position < s.length() - 3; ++position) {
        std::string needle { s[position] , s[position+1]};
        if ( s.find(needle, position + 2) != std::string::npos)
            return true;
    }
    return false;
}

bool niceRuleNew2(const std::string &s) {
    // atleast one letter appears twice in a row.
    if ( s.length() == 1)
        return false;
    for ( size_t position = 0 ; position < s.length() - 2; ++position) {
        if(s[position] == s[position + 2])
            return true;
    }
    return false;
}
