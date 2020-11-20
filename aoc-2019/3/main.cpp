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

std::vector<Wire> laywire( std::string d , std::vector<Wire> w ) {
    char c ;
    int p;
    int x = 0 , y = 0;
    for(int i = 0; i < d.length() ; i++) {
        c = d.at(i);
        ++i;
        p = 0;
        while (d.at(i)!=',' ) {
            p = p*10 + ('0'-d.at(i));
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
        }

    }
    return w;
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
    //std::cout << d << std::endl;
    wire1 = laywire( d , wire1 );

    std::getline(infile,d);
    wire2 = laywire( d , wire2);


    for(Wire i:wire1) {
        for(Wire j:wire2) {
            if(i.x == j.x && i.y == j.y) {
                std::cout << i.x << " " << i.y << std::endl;
            }
        }
    }
    //std::cout << wire1[1].x << std::endl;

    infile.close();
    return 0;
}
