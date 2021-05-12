#include <iostream>
using std::string;
#include <vector>
#include <algorithm>
using std::vector;
#include <sstream>
#include <numeric>
#include <fstream>
using std::cout;
using std::endl;
#include <regex>

int sumInLine(const string &s);
void star1 ( const string &filename);
//void star2 (const string &filename);
string removeRed (string s);

std::string gimmeStartCurly ( string s );
std::string gimmeEndCurly ( string s );


int main() {
//    std::cout << sumInLine("{\"a\":2,\"b\":4}") << std::endl;
    star1("input");
    /*
    cout << sumInLine << removeRed("asdf{{\"d\":\"red\"},\"e\":[1,2,3,4],\"f\":5}x") << "\n";
    cout << sumInLine (removeRed("asdf{{\"d\":\"red\"},\"e\":[1,2,3,4],\"f\":5}x")) << "\n";
    cout << sumInLine ( removeRed ( "{\"c\": 42,\"a\":\"blue\", \"b\":\"red\"}")) << "\n";
    cout << sumInLine ( removeRed ( "{\"c\":\"red\",\"a\":\"violet\", \"b\":168}")) << "\n";
    */
    return 0;
}

int sumInLine( const string &s) {
    vector <int> numbers;
    std::istringstream iss(s);
    while ( !iss.eof() ) {
        int n = 0;
        iss >> n;
//        std::cout << n << " ";
        if ( iss.bad() || iss.fail()) {
            iss.clear();
            iss.ignore(1);
        }
        else {
            numbers.push_back(n);
        }

    }
    return std::accumulate(std::begin(numbers), std::end(numbers), 0);
}

void star1(const string &filename) {
    std::ifstream myFile(filename);
    int s1 = 0, s2 = 0;
    string line;
    while ( std::getline(myFile, line)) {
        s1 += sumInLine(line);
        //string line2 = removeRed(line);
        //cout << line2;
        //s2 += sumInLine(line2);
    }
    std::cout << "Star 1: " << s1 << "\n";
    //std::cout << "Star 2: " << s2 << "\n";
}

string removeRed(string s) {
//    std::regex e ("(\\{.*\":\"red\".*\\})") ;
    std::regex e(":\"red\"");
    std::smatch sm;
    string refined ;

//    std::regex_iterator<std::string::iterator> rit ( s.begin(), s.end(), e);
//    std::regex_iterator<std::string::iterator> rend;

//    while ( rit != rend) {
//        refined += rit->prefix().str();
//        s = rit->suffix().str();
//        rit =
//    }
    while ( std::regex_search (s, sm, e)) {
        // refined = string from the beginning to '{'
        refined += gimmeStartCurly(sm.prefix().str()) ;//+ "}" ;
        //cout << sm.prefix().str() << "\n";
        // s = get from suffix start to appropriate '}'
        s = gimmeEndCurly(sm.suffix().str());
    }
    /*
    while (std::regex_search (s,sm,e)) {
        refined += sm.prefix().str();
        s = sm.suffix().str();
        cout << sm.size();
    }*/
    refined += s;
    return refined;
}

std::string gimmeStartCurly ( string s ) {
    int oppCurly = 0;
    string rets;
    for ( auto rc = s.rbegin() ; rc != s.rend() ; ++rc) {
        if ( *rc == '}')
            ++oppCurly;
        if ( *rc == '{') {
            if (oppCurly == 0) {
                //std::copy(rc, s.rend(), rets.begin());
                //++rc;
                rets = string(rc, s.rend());
                //rets = string(s.begin(), rc.base() );
                //std::copy(s.begin(), rc.base() + 1, rets.begin());
                break;
            } else
                --oppCurly;
        }
    }
    std::reverse(rets.begin(), rets.end());
    return rets;
}

std::string gimmeEndCurly ( string s ) {
    int oppCurly = 0;
    string rets;
    for ( auto rc = s.begin() ; rc != s.end() ; ++rc) {
        if ( *rc == '{')
            ++oppCurly;
        if ( *rc == '}') {
            if (oppCurly == 0) {
                //++rc;
                //std::copy(rc, s.end(), rets.begin());
                rets = string (rc, s.end());
                break;
            } else
                --oppCurly;
        }
    }
    //std::reverse(rets.begin(), rets.end());
    return rets;
}