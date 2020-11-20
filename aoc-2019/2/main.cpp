#include <iostream>
#include <fstream>
#include <vector>
/*
 * Advent of code 2019 Day 2
 * This is the program to take input
 *
 * My thought is to input everything into a vector.
 * Not deal with trying to read and write to a same fil because it gives errors.
 * My concern is that if the vector will be too large.
 */
int main() {
    std::ifstream infile;
    infile.open("input");
    std::vector <int> numbers;
    int a = 0;
    // placing the value inside input into an array numbers
    while (infile >> a) {
        numbers.push_back(a);
        if(infile.peek() == ',')
            infile.ignore();
    }
    //because i do not want to change the input file.
    numbers [1] = 12;
    numbers [2] = 2;

    for( int i = 0 ; i < numbers.size() && numbers[i]!=99 ; i=i+4) {
        switch( numbers[i]) {
            case 1:
                numbers[numbers[i+3]] = numbers[numbers [i+1]] + numbers[numbers[i+2]];
                break;
            case 2:
                numbers[numbers[i+3]] = numbers[numbers [i+1]] * numbers[numbers[i+2]];
                break;
        }
    }

    /*for(int i : numbers )
        std::cout<< i << std::endl;*/
    std::cout << numbers[0] << std::endl;
    infile.close();
    return 0;
}
