#include <iostream>

#include "Solution.hpp"

int main() {
    Solution mySoln ("input");
    std::cout << "Star1: " << mySoln.maxScore();
    std::cout << "\n";
    mySoln.addSelf();
    std::cout << "Star2: " << mySoln.maxScore();
    return 0;
}