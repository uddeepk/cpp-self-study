#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using std::vector;
using namespace std;
vector<int> getSides ( string a) {
    vector<int> l;
    int temp = 0;
    for(int i = 0 ; i <= a.size() ; i++) { // Read char at each position
        if(a[i] >= '0' && a[i] <= '9' ) {
            temp = temp*10 + (a[i] - '0');
        }
        if(a[i] == 'x' ) {
            l.push_back(temp);
            temp = 0;
        }
    }
    l.push_back(temp);
    return l;
}

int getProduct ( vector<int> l) {
    int product = 1;
    for(int i : l) {
        product*=i;
    }
    return product;
}
int getPerimeter(vector <int> l) {
    // sort and then return a value ?
    for(int i = 1 ; i <= 2 ; ++i){
        //SUre sort
        if(l[i] < l [i-1]) {
            int temp = l[i-1];
            l[i-1] = l[i];
            l[i] = temp;
        }
    }
    return (2*(l[0] + l[1]));
}
int getRibbon(vector<int> l) {
    return (getPerimeter(l) + getProduct(l));
}
int getSmallestSide(vector<int> vars) {
    int min = vars[0];
    for(int b:vars) {
        if(b<min) {
            min = b;
        }
    }
    return min;
}
int getWrappingPaper(string a) {
    vector<int> l;
    int temp = 0;
    for(int i = 0 ; i <= a.size() ; i++) { // Read char at each position
        if(a[i] >= '0' && a[i] <= '9' ) {
            temp = temp*10 + (a[i] - '0');
        }
        if(a[i] == 'x' ) {
            l.push_back(temp);
            temp = 0;
        }
    }
    l.push_back(temp);
    vector<int> sides;
    sides.push_back(l[0]*l[1]);
    sides.push_back(l[1]*l[2]);
    sides.push_back(l[0]*l[2]);
    return (2*(sides[0]+sides[1]+sides[2]) + getSmallestSide(sides));
}
int main() {
    //Get input
    ifstream myFile;
    string s = "" ;
    myFile.open("input");
    int totalWrappingPaper = 0;
    int totalRibbon = 0;
    vector<int> sides;
    while ( myFile >> s ) {  // Loop till end of file. Should i get line instead ??
        // Use s somehow. Refer to method
        totalWrappingPaper += getWrappingPaper(s) ;
        sides = getSides(s);
        totalRibbon += getRibbon(sides);
    }
    cout<< totalWrappingPaper << " "<< totalRibbon << endl;
    myFile.close();
    return 0;
}
