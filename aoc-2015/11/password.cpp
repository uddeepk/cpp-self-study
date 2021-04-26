//
// Created by uddeepk on 4/25/21.
//

#include "password.hpp"
#include <regex>
#include <iostream>
using std::string;

Password::Password(const string &s): _password(s) {

}

bool Password::hasStraight() const{
    for ( size_t i = 0 ; i < _password.length() - 2 ; ++ i ) {
        char c = _password[i];
        if ( _password[i+1] == (c+1) && _password[i+2] == (c+2))
            return true;
    }
    return false;
}

bool Password::isNotConfusing() const {
    std::regex e ("(i|o|l)");
    std::smatch sm;
    if (std::regex_search(_password, sm, e ) ) {
        return false;
    }
    return true;
}

bool Password::hasTwoPairs() const {
    string temp {_password};
    std::regex e ( "(aa|bb|cc|dd|ee|ff|gg|hh|ii|jj|kk|ll|mm|nn|oo|pp|qq|rr|ss|tt|uu|vv|ww|xx|yy|zz)");
    std::smatch sm;

    int pairs = 0;

    while ( std::regex_search(temp, sm, e)) {
        temp = sm.suffix();
//        std::cout << sm.str();
        ++pairs;
    }
    return pairs >= 2;
}

void Password::incrementPassword() {
    int carryover = 0;
    for ( auto rit = _password.rbegin() ; rit != _password. rend() ; ++rit) {
        if ( rit == _password.rbegin()) {
            (*rit)++;
        }
        else {
            *rit += carryover;
            carryover = 0;
        }
        int p = *rit - 'a';
        if(p >= 26 ) {
            *rit = 'a' + p % 26;
            ++carryover;
        }

    }
}