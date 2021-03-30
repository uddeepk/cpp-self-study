#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <string>

struct LightGrid {
    LightGrid(int );
    std::vector<std::vector<bool>> _bulbs;
    std::vector<std::vector<int>> _brightness;
//    std::map <std::tuple <int,int>, bool> _bulbs;
    void turnOn  (int bi, int bj, int ei, int ej) ;//(std::tuple <int, int> start, std::tuple <int, int> end );
    void turnOff (int bi, int bj, int ei, int ej) ;
    void toggle (int bi, int bj, int ei, int ej) ;
    int star1 () const;
    int star2 () const;
    void executeNext(std::string);
};

void LightGrid::turnOn (int bi, int bj, int ei, int ej) {
    for ( ; bi <= ei ; ++bi) {
        for ( int col = bj ; col <= ej ; ++col) {
            _bulbs[bi][col] = true;
            ++_brightness[bi][col];
        }
    }
}
void LightGrid::turnOff (int bi, int bj, int ei, int ej) {
    for ( ; bi <= ei ; ++bi) {
        for ( int col = bj ; col <= ej ; ++col) {
            _bulbs[bi][col] = false;
            if(_brightness[bi][col] > 0 )
                --_brightness[bi][col];
        }
    }
}
void LightGrid::toggle (int bi, int bj, int ei, int ej) {
    for ( ; bi <= ei ; ++bi) {
        for ( int col = bj ; col <= ej ; ++col) {
            _bulbs[bi][col] = !(_bulbs[bi][col]);
            _brightness[bi][col] += 2;
        }
    }
}

int LightGrid::star1 () const {
    int lit = 0 ;
    for ( auto row : _bulbs) {
        for ( auto bulb : row ) {
            if (bulb)
                ++lit;
        }
    }
    return lit;
}
int LightGrid::star2 () const {
    int lit = 0 ;
    for ( auto row : _brightness) {
        for ( auto bulb : row ) {
            lit += bulb;
        }
    }
    return lit;
}
void LightGrid::executeNext(std::string s) {
    std::istringstream iss (s);
    std::string readBuf, action;
    iss >> action;
//    iss >> action;
    if(action == "turn" ) {
        iss >> readBuf;
        action += " " + readBuf;
    }
    int bi, bj, ei, ej;
    iss >> readBuf;
    //Split the numbers
//    iss >> readBuf;
    std::string::size_type sz;   // alias of size_t
    auto posn = readBuf.find(",");
    bi = std::stoi(readBuf.substr(0, posn), &sz);
    bj = std::stoi(readBuf.substr(posn + 1),  &sz);

    iss >> readBuf; // eat "through"

    iss >> readBuf;
    //Split the numbers
//    iss >> readBuf;
//    std::string::size_type sz;   // alias of size_t
    posn = readBuf.find(",");
    ei = std::stoi(readBuf.substr(0, posn), &sz);
    ej = std::stoi(readBuf.substr(posn + 1),  &sz);

    if(action == "toggle")
        toggle(bi, bj, ei, ej);
    else if (action == "turn on")
        turnOn(bi, bj, ei, ej);
    else if (action == "turn off")
        turnOff(bi, bj, ei, ej);
    else
        exit(1);
}

LightGrid::LightGrid(int d):_bulbs(d, std::vector <bool> (d, 0)),
                            _brightness(d, std::vector <int> (d, 0)) {
//    _bulbs = <std::vector<
}

using std::vector;

void testCase () ;

int main() {
    std::cout << "Hello, World!" << std::endl;
//    testCase();
    std::ifstream myFile ("input");
    LightGrid l1(1000);
    std::string readBuf;
    while (getline(myFile, readBuf)) {
        l1.executeNext(readBuf);
    }
    std::cout << l1.star1() << std::endl;
    std::cout << l1.star2() << std::endl;
    return 0;
}

void testCase () {
    LightGrid l1 {10};
//    vector<vector<bool>> myTestVec (9, vector<bool>(9, 0)) ;
//    l1._bulbs = myTestVec;
    l1.turnOn(0, 0, 8, 8);
//    l1.executeNext("");
    std::cout << l1.star1() << std::endl;
}