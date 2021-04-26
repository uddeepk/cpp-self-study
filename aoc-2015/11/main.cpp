#include <iostream>
#include "password.hpp"


int main() {
    std::cout << "Hello, World!" << std::endl;
    Password p ("hxbxwxba"); // star1
    Password p2( "hxbxxyzz");

    std::cout << "star1: " << p.getNextPassword() << "\n";
    std::cout << "star2: " << p2.getNextPassword() << "\n";
    return 0;
}
