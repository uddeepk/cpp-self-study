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
int main() {
    // Get input
    ifstream myFile ;
    char c ;
    myFile.open("input");
    // Use vector or an output file that I read everytime ??
    vector<Home> visitedHome;
    int y = 0 , x = 0;  // can i declare a vector for the instructions. i refers to santa, the other refer
    // to robo-santa. and then use even odd check for which one to modify.
    visitedHome.push_back(Home( x , y ));
    while( myFile >> c) {
        switch(c) {
            case '^':
                ++y;
                break;
            case 'v':
                --y;
                break;
            case '<':
                --x;
                break;
            case '>':
                ++x;
                break;
        }
        if(!checkVisited( x , y , visitedHome)) {
            visitedHome.push_back(Home(x , y ));
        }
    }
    cout << visitedHome.size() << endl;
    myFile.close();
    return 0;
}
