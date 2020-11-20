#include <iostream>
#include <vector>
#include <fstream>
#include <string>
class Wire  {
public:
    int x , y ;

public:
    Wire( int x1 , int y1) {
        x = x1;
        y = y1;
    }
};
class Steps {
public:
    int x , y , steps1 , steps2;

public:
    Steps(int x1 , int y1, int s1 , int s2) {
        x = x1;
        y = y1;
        steps1 = s1;
        steps2 = s2;
    }
};
void lay( std::string d , std::vector<Wire> &w) {

    char c ;
    int p;
    int x = 0 , y = 0;
    for(int i = 0; i < d.length() ; i++) {
        c = d.at(i);
        ++i;
        p = 0;
        while (d.at(i)!=',' ) {
            p = p*10 + (d.at(i)-'0');

            ++i;
            if( i >= d.length())
                break;
        }
        switch (c) {
            case 'R':
                for(int q = 0 ; q < p ; ++q) {
                    ++x;
                    w.emplace_back(Wire(x , y));
                }
                break;
            case 'L':
                for(int q = 0 ; q < p ; ++q ) {
                    --x;
                    w.emplace_back(Wire(x , y));
                }
                break;
            case 'U':
                for(int q = 0 ; q < p ; ++q ) {
                    ++y;
                    w.emplace_back(Wire(x , y));
                }
                break;
            case 'D':
                for(int q = 0 ; q < p ; ++q) {
                    --y;
                    w.emplace_back(Wire(x,y));
                }
                break;
            default:
                break;
        }

    }

}
int closest(std::vector <Wire> m ) {
    int min = abs(m[0].x) + abs(m[0].y) ;
    for(Wire i:m) {
        if(min > (abs(i.x) + abs(i.y)))
            min = abs(i.x) + abs(i.y);
    }
    return min;
}
int main() {
    std::ifstream infile;
    infile.open("input");
    // create a vector each to store the points that it passes
    // check each point for intersection.
    //vector of wire positions ??
    std::vector<Wire> wire1;
    std::vector<Wire> wire2;

    char fileInput , direction;

    std::string d = "" ;
    std::getline(infile,d);

    lay(d , wire1);

    std::getline(infile,d);

    lay( d , wire2);

    std::vector<Wire> matches;

    for(int i = 0; i < wire1.size() ; ++i) {
        for(int j = 0 ; j < wire2.size() ; ++j) {
            if(wire1[i].x == wire2[j].x && wire1[i].y == wire2[j].y) {
                //std::cout << i.x << " " << i.y << std::endl;
                matches.emplace_back(Wire(i+1 , j+1));
            }
        }
    }

    //find and display shortest distance of the matches. in terms of taxicab geometry
    //abs(x) + abs(y) ??

    std::cout << closest(matches) << std::endl;

    infile.close();
    return 0;
}
