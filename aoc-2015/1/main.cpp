#include <iostream>
#include <fstream>

int main() {
    std::ifstream infile;
    infile.open("input");
    char c;
    int floor = 0;
    int numberIn = 0;
    while( infile >> c )  {
        numberIn++;
        if(c == '(') {
            floor++;
        }
        else if (c ==')'){
            floor--;
        }
        if(floor == -1)
            break;
    }
    std::cout << "The character position is " << numberIn << std::endl;
    std::cout << floor << std::endl;
    infile.close();
    return 0;
}
