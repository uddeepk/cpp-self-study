//
// Created by uddeepk on 4/25/21.
//

#ifndef INC_11_PASSWORD_HPP
#define INC_11_PASSWORD_HPP
#include <string>

class Password {
public:
    Password();
    Password(const std::string &s);
    std::string getNextPassword();
private:
    std::string _password;
    bool hasStraight () const;
    bool isNotConfusing() const ;
    bool hasTwoPairs() const;
    void incrementPassword();
};


#endif //INC_11_PASSWORD_HPP
