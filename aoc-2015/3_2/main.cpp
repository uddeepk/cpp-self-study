#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Home {
public:
    int e , n , presents = 0 ;
public:
    Home(int e1 , int n1 ) {
        n = n1;
        e = e1;
        presents = 1;
    }
    void visit()
    {
        ++presents;
    }
};
bool checkVisited( int x1 , int y1 , vector<Home> &H ) {
    for(int i = 0 ; i < H.size() ;  ++i ){
        if(x1 == H[i].e && y1 == H[i].n) {
            H[i].visit();
            return true;
        }
    }
    return false;
}

void enterHome ( int &x1 , int &y1 , char direction, vector<Home> &vH ) {
    switch(direction) {
        case '^':
            ++y1;
            break;
        case 'v':
            --y1;
            break;
        case '<':
            --x1;
            break;
        case '>':
            ++x1;
            break;
    }
    if(!checkVisited( x1 , y1 , vH)) {
        vH.push_back(Home(x1 , y1 ));
    }
}
int main() {
    // Get input
    ifstream myFile ;
    char c ;
    myFile.open("input");
    // Use vector or an output file that I read everytime ??
    vector<Home> visitedHome;
    int ySanta = 0 , xSanta = 0 , yRobot=0 , xRobot = 0;  // can i declare a vector for the instructions. i refers to santa, the other refer
    // to robo-santa. and then use even odd check for which one to modify.
    visitedHome.push_back(Home( xSanta , ySanta )); //first House Santa
    visitedHome[0].visit(); // Robosanta dropping present
    for (int i = 1; myFile >> c ; ++i) {  //using i to count odd input for santa, and even for robo-santa

        if( i%2 == 0 ) {
            enterHome(xSanta , ySanta, c , visitedHome);
        }
        else {
            enterHome( xRobot , yRobot , c , visitedHome);
        }

    }
    cout << visitedHome.size() << endl;
    myFile.close();
    return 0;
}

