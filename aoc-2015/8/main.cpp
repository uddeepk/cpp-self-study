#include <iostream>
#include <regex>
#include <fstream>
#include <vector>

struct Token {
    Token(const std::string &s):_word(s) {
        std::string d;

        for ( size_t i = 1 ; i < s.length() - 1 ; ++i) {
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
//                std::cout << c ;
            }
            else {
                c = _word[i];
            }
//            if(!std::isspace(c)) {
//                d += c;
//            }
            d+=c;

        }
        _data = d;
    };

    std::string _word;
    std::string _data;
    std::string _data2;

    // get string literal count
    int getLiteralCount () const;
    // get string chars in memory count
    int getMemoryCount() const;
    int getMatches ( const std::string &s, std::regex re) const;
    void addCharacters ()  ;
    int getCount() const {
        return _data2.length();
    };
};

int Token::getLiteralCount() const{
    return _word.length();
}

int Token::getMemoryCount() const {
//    std::regex backslash ("[\\\\]{2}" );
//    std::regex dQuotes ( "\\\\\"");
//    std::regex hex ( "\\\\x[0-9a-f]{2}");
//    std::regex words_regex("\\\\\"|\\\\\\\\|\\\\x[0-9a-f]{2}");
//
//    int backslashCount = getMatches(_word, backslash);
//    int dQuotesCount = getMatches(_word, dQuotes);
//    int hexCount = getMatches(_word, hex);
//
//    int memChars = _word.length() - (backslashCount + dQuotesCount + 3 * hexCount + 2);
//
//    return memChars;
    return _data.length();
}
int Token::getMatches ( const std::string &s, std::regex re) const{
    auto words_begin = std::sregex_iterator (_word.begin(), _word.end(), re);
    auto words_end = std::sregex_iterator();
    auto count = std::distance(words_begin, words_end);
    return count;
}
using std::string;
void Token::addCharacters() {
    string r ;
    r = r + _word[0] + "\\\"";
//    std::cout << r << std::endl;
    for ( size_t i = 1 ; i < _word.length()-1 ; ++i ) {
        char c = _word[i];

        string temp ;
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

//            r += c2;
        }
        else {
            r += c;
        }

    }
    r = r + "\\\"" + _word[_word.length() - 1];
    _data2 = r;
}
int main() {
//    const std::string s = "Q\\x89uick brouicwn fouicx.";
//
//    std::regex words_regex("\\\\x[0-9a-f]{2}|uic");
//    auto words_begin =
//            std::sregex_iterator(s.begin(), s.end(), words_regex);
//    auto words_end = std::sregex_iterator();
//
//    std::cout << "Found "
//              << std::distance(words_begin, words_end)
//              << " words:\n";
//
//    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
//        std::smatch match = *i;
//        std::string match_str = match.str();
//        std::cout << match_str << '\n';
//    }
//    Token("adc\\x41t");
//    return 0;
    std::ifstream myFile ("input");
    std::string readBuffer;
    std::vector <Token> vecToken;
    while (getline(myFile, readBuffer)) {
        vecToken.push_back(Token{readBuffer});
    }
    int star1 = 0, star2 = 0;
    for ( auto t : vecToken) {
        star1 += ( t.getLiteralCount() - t.getMemoryCount());
    }
    for (auto &t : vecToken) {
        t.addCharacters();
//        std::cout << t._data2 << "\n";
        star2 += t.getCount() -  t.getLiteralCount();
    }
    std::cout << star1 << " " << star2 << std::endl;
    auto x = Token ("\"\\\\\\x27\"");//"a\\\"aa\\\"aaa");
    x.addCharacters();
    std::cout << x.getLiteralCount() << " " << x._data2.length() << std::endl;
    std::cout << x._data2 << std::endl;

    return 0;
}
