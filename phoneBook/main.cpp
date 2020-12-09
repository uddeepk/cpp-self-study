#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;
    map <string , string> phoneBook;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max() , '\n');
    for (int i = 0 ; i < n ; i++) {
      string name ;
      string phoneNumber;
      cin >> name >> phoneNumber;
      cin.ignore(numeric_limits<streamsize>::max() , '\n');
      phoneBook[name] = phoneNumber; //or we can use insert
    }
    string query;
    vector <string> queries;
    while ( cin >> query) {
        queries.push_back(query);
    }
    for( auto it = queries.begin() ; it != queries.end() ; ++it) {
        auto it2 = phoneBook.find(*it);
        if(it2 == phoneBook.end()) {
            cout << "Not found" << endl;
        }
        else {
            cout << it2->first << " " << it2->second <<endl;
        }
    }
    return 0;
}