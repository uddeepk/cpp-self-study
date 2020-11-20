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
bool landing ( int a , int b , std::vector<int> n) {
    n[1] = a;
    n[2] = b;
    for( int i = 0 ; i < n.size() && n[i]!=99 ; i=i+4) {
        switch( n[i]) {
            case 1:
                n[n[i+3]] = n[n [i+1]] + n[n[i+2]];
                break;
            case 2:
                n[n[i+3]] = n[n [i+1]] * n[n[i+2]];
                break;
        }
    }
    return(n[0] == 19690720);
}
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
    for(int i = 0 ; i<= 99 ;++i) {

        for(int j = 0 ; j<=99 ; ++j) {

            if(landing( i , j , numbers)) {
                std::cout<<( i*100 + j) <<std::endl;
            }
        }
    }

    //std::cout << numbers[0] << std::endl;
    infile.close();
    return 0;
}
