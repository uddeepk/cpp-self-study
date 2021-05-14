#include <iostream>
#include <sstream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <fstream>

struct Reindeer {
    Reindeer(const std::string &s);

    int calculateDistance (int t) const;
    int distanceFlownInCycle () const;
    int distanceFlown(int t) const;
    std::string _name = "noname";
    int _flightSpeed = -1;
    int _flightTime = -1;
    int _restTime = -1;
    int _cycleTime = -1;

    friend std::ostream& operator<< ( std::ostream&os, const Reindeer &r);
};
std::vector<std::string> tokenize(const std::string &s);

using std::string;

Reindeer::Reindeer(const string &s) {
    std::vector<std::string> tokens = tokenize(s);

    _name = tokens[0];
    _flightSpeed = std::stoi(tokens[3]);
    _flightTime = std::stoi(tokens[6]);
    _restTime = std::stoi(tokens[13]);
    _cycleTime = _flightTime + _restTime;
}

std::ostream &operator<<(std::ostream& os, const Reindeer &r) {
    os << r._name << " " << r._flightSpeed << "km/s " << r._flightTime << "s " << r._restTime << "s "
    << r._cycleTime << "s.";
    return os;
}

int Reindeer::distanceFlownInCycle() const {
    return _flightTime * _flightSpeed;
}

int Reindeer::calculateDistance(int t) const{
    int distance = 0;
    int numberOfCycles = t / _cycleTime;
    distance = numberOfCycles * distanceFlownInCycle();
    t %= _cycleTime;
    if ( t >= _flightTime)
        distance += distanceFlownInCycle();
    else
        distance += distanceFlown(t);
    return distance;
}

int Reindeer::distanceFlown(int t) const {
    return t * _flightSpeed;
}

std::vector<Reindeer> getVecReindeer (std::istream& is) ;
template <typename T>
void print(const std::vector<T> &v) {
    for ( const auto &x : v) {
        std::cout << x << "\n";
    }
}
int main() {
//    std::cout << "Hello, World!" << std::endl;
//
//    std::string s1 = "Comet can fly 14 km/s for 10 seconds, but then must rest for 127 seconds.";
//    std::string s2 = "Dancer can fly 16 km/s for 11 seconds, but then must rest for 162 seconds.";
//    Reindeer comet (s1);
//    Reindeer dancer {s2};
//    std::cout << comet << "\n";
//    std::cout << dancer << "\n";
//
//    // get input from file
//    // Testing
//    std::istringstream iss (s1 + "\n" + s2);
//    std::vector<Reindeer> vecReindeer = getVecReindeer(iss);
//
//    print(vecReindeer);

//    std::cout << comet.calculateDistance(1000) << "\n";

    std::ifstream myFile("input");

    std::vector<Reindeer> vecReindeer = getVecReindeer(myFile);

    std::vector<int> d;
    int time = 2503;
    ////// Calculating distance
    std::ranges::transform(vecReindeer, std::back_inserter(d),
                                       [&] (const Reindeer &r) -> int {
        return r.calculateDistance(time); // change this for time
    });

//    print(d);

    std::cout << " star1: " << std::ranges::max(d);
    //////
    return 0;
}

std::vector<string> tokenize(const string &s) {
    std::vector<string> tokens;
    std::istringstream iss (s);
    string word;
    while (std::getline(iss, word, ' ')) {
        tokens.push_back(word);
    }
    return tokens;
}

std::vector<Reindeer> getVecReindeer(std::istream &is) {
    if ( !is) {
        std::cerr << "Input Error!";
        std::exit(-1);
    }
    string readBuffer;
    std::vector <Reindeer> v;
    while (std::getline(is, readBuffer)) {
        v.emplace_back(readBuffer);
    }
    return v;
}
