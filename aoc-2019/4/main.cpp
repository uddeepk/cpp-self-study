#include <iostream>
#include <vector>

using std::cout; using std::endl;
using std::vector;

vector <int> pairs (int n) {
    vector<int> v;
    while(n>=10) {
        int r = n%100;
        n /=10;
        v.insert(v.begin(),r);
    }
    return v;
}
bool checkAdjacent ( vector<int> v) {
    for(int i: v) {
        if((i/10) == (i%10))
            return true;
    }
    return false;
}
bool meetsCriteria (int n) {
    vector <int> p = pairs(n);

    bool neverDecrease = true;
    for ( int i: p) {
        if((i/10)>(i%10)){
            return false;
        }
    }
    if(!checkAdjacent(p))
        return false;

    return true;
}
int main() {
    int a = 0;
    for(int i = 382345 ; i <= 843167 ; i++) {
        if(meetsCriteria(i))
            a++;
    }
    cout << a << endl;
    return 0;
}
