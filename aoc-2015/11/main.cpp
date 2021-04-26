#include <iostream>
#include "password.hpp"


int main() {
    std::cout << "Hello, World!" << std::endl;
    Password p ("tzzzzzz");
    std::cout << p.hasStraight() << "\n";
    std::cout << p.isNotConfusing() << "\n";
    std::cout << p.hasTwoPairs() << "\n";
    p.incrementPassword();
    std::cout << p._password << "\n";
    return 0;
}
