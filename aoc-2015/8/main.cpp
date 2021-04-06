#include <iostream>
#include <regex>
#include <fstream>
#include <vector>

struct Token {
    Token(const std::string &s):_word(s) {};

    std::string _word;
    std::string _data;
    std::string _data2;

    // get string literal count
    int getLiteralCount () const;
    void decodeString() ;
    // get string chars in memory count
    int getMemoryCount() const;
    int getMatches ( const std::string &s, std::regex re) const;
    void encodeString ()  ;
    int getEncodedCount() const ;
};

int Token::getLiteralCount() const{
    return _word.length();
}
void Token::decodeString() {
    std::string d;

    for ( size_t i = 1 ; i < _word.length() - 1 ; ++i) {
        char c;
        if (_word[i] == '\\') {
            ++i;
            if ( _word[i] == '\\') {
                c = '\\';
            }
            else if (_word[i] == '\"') {
                c = '\"';
            }
            else if (_word[i] == 'x' ) {
                ++i;
                std::string temp = _word.substr(i, 2);
                c = std::stoi(temp, 0, 16);
                ++i;
            }
        }
        else {
            c = _word[i];
        }
        d+=c;

    }
    _data = d;
}
int Token::getMemoryCount() const {
    return _data.length();
}
int Token::getMatches ( const std::string &s, std::regex re) const{
    auto words_begin = std::sregex_iterator (_word.begin(), _word.end(), re);
    auto words_end = std::sregex_iterator();
    auto count = std::distance(words_begin, words_end);
    return count;
}
using std::string;
void Token::encodeString() {
    string r ;
    r = r + _word[0] + "\\\"";
    for ( size_t i = 1 ; i < _word.length()-1 ; ++i ) {
        char c = _word[i];
        if ( c == '\\' ) {
            r = r + c + c ;
            ++i;
            char c2 = _word[i];
            if (  c2 == '\"' ) {
                    r = r + "\\" + c2;
            }
            if (c2 == 'x') {
                r = r + c2;
            }
            if ( c2 == '\\') {
                r = r + c2 + c2;
            }
        }
        else {
            r += c;
        }
    }
    r = r + "\\\"" + _word[_word.length() - 1];
    _data2 = r;
}

int Token::getEncodedCount() const {
    return _data2.length();
}

int main() {
    std::ifstream myFile ("input");
    std::string readBuffer;
    std::vector <Token> vecToken;
    while (getline(myFile, readBuffer)) {
        vecToken.push_back(Token{readBuffer});
    }
    int star1 = 0, star2 = 0;
    for ( auto &t : vecToken) {
        t.decodeString();
        star1 += ( t.getLiteralCount() - t.getMemoryCount());
    }
    for (auto &t : vecToken) {
        t.encodeString();
        star2 += t.getEncodedCount() -  t.getLiteralCount();
    }
    std::cout << "Star 1: " <<  star1 << " Star 2: " << star2 << std::endl;


    return 0;
}
