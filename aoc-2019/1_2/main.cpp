#include <iostream>
#include <fstream>
/*
 * AOC 2019 #1 Part 2
 * Try recursion ?
 */
int getFuel( int mass) {
    if((mass /3 -2 ) <= 0  ) {
        return 0;
    }
    else {
        return ((mass/ 3 - 2) + getFuel(mass/ 3 - 2));
    }
}
int main() {
    std::ifstream infile;
    infile.open("input");
    int mass = 0;
    int totalFuel = 0;
    //int fuelForFuel = 0;
    int fuelForMass = 0;
    while ( infile >> mass ){
        //fuelForMass = (mass/3) -2 ;
        totalFuel +=  getFuel(mass);
    }
    std::cout << "Total fuel is " << totalFuel << std::endl;
    infile.close();
    return 0;
}
