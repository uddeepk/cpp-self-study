#include <iostream>

int sumOfDigits (int a) {
    int s = 0;
    while ( a > 0) {
        s += (a % 10);
        a = (a / 10);
    }
    return s;
}

int main() {
    // Read input
    std::cout << "Enter a non-negative number :" << std::endl;
    //Declare number for input, sum of digits, and n as number of iterations
    int number = 0, sum = 0, n = 0;
    if (std::cin >> number ) { //checking validity of input
        if(number >= 0) { //if input is valid, ie >= 0
            sum = number;
            while(sum >= 10) { //loop only until sumofdigits is less than 10
                sum = sumOfDigits(sum);
                n++;
            }
        }
        else {

            std::cerr << "Error! Invalid input. Please enter a non-negative number." << std::endl;
            return -1;
        }
    }
    else {
        // std::cout << 5/10 << std::endl;
        std::cerr << "Error! Invalid input. Please enter a number."<<std::endl;
        return -1;
    }
    std::cout << number << " -> " << n << std::endl;
    return 0;
}
