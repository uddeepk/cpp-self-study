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

    // Part2
    void update();
    void fly();
    void addPoint();

    std::string _name = "noname";
    int _flightSpeed = -1;
    int _flightTime = -1;
    int _restTime = -1;
    int _cycleTime = -1;

    // FOr part2
    int _flightTimeLeft ;
    int _restingTimeLeft ;
    int _distance;
    int _points = 0;

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

    // Part 2
    _flightTimeLeft = _flightTime;
    _restingTimeLeft = 0;
    _distance = 0;
}

std::ostream &operator<<(std::ostream& os, const Reindeer &r) {
    os << r._name << " " << r._flightSpeed << "km/s " << r._flightTime << "s " << r._restTime << "s "
    << r._cycleTime << "s " << r._distance << "km " << r._points << "points ";
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

void Reindeer::update() {
    if ( _flightTimeLeft > 0) {
        fly();
        if ( _flightTimeLeft == 1) {
            _restingTimeLeft = _restTime;
        }
        --_flightTimeLeft;
        return;
    }

    if ( _restingTimeLeft > 0) {
        // Do nothing

        if (_restingTimeLeft == 1)
            _flightTimeLeft = _flightTime;
        --_restingTimeLeft;
    }
}

void Reindeer::fly() {
    _distance += _flightSpeed; // Updating distance by 1 tick
}

void Reindeer::addPoint() {
    ++_points;
}
std::vector<Reindeer> getVecReindeer (std::istream& is) ;
template <typename T>
void print(const std::vector<T> &v) {
    for ( const auto &x : v) {
        std::cout << x << "\n";
    }
}

void star2 (std::vector <Reindeer> &v);
int getMaxDistance (const std::vector <Reindeer> &v);

template <typename MyFunction>
int getMax(const std::vector<Reindeer> &v, MyFunction f) {
    std::vector<int> data ;
    std::ranges::transform(v, std::back_inserter(data), f);
    return std::ranges::max(data);
}

int getPoints(const Reindeer &r);

int main() {

    std::ifstream myFile("input");

    std::vector<Reindeer> vecReindeer = getVecReindeer(myFile);
    std::vector<Reindeer> vecReindeer2 = vecReindeer;

    std::vector<int> d;
    int time = 2503;
    ////// Calculating distance
    std::ranges::transform(vecReindeer, std::back_inserter(d),
                                       [&] (const Reindeer &r) -> int {
        return r.calculateDistance(time); // change this for time
    });

    std::cout << " star1: " << std::ranges::max(d);
    std::cout << "\n";
    //////

    // Star 2

    int n = 2503;
    while ( n-- > 0 ) {
        star2(vecReindeer2);

    }
    std::cout << "star2: " << getMax(vecReindeer2, getPoints);

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

void star2(std::vector<Reindeer> &v) {
    // update all
    std::ranges::for_each(v, [] (Reindeer &r) {
        r.update();
    });

    // give point if max
    //   1. get max
    auto max = getMaxDistance(v);

    std::ranges::for_each(v, [=] (Reindeer &r) {
        if ( r._distance == max)
            r.addPoint();
    });
}

int getMaxDistance(const std::vector<Reindeer> &v) {
    return std::ranges::max_element(v, [] (const Reindeer &lhs, const Reindeer &rhs) {
        return lhs._distance < rhs._distance;
    })->_distance;
}

int getPoints(const Reindeer &r) {
    return r._points;
}

