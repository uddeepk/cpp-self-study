#include <iostream>
#include <sstream>
#include <vector>

struct Reindeer {
    Reindeer(const std::string &s);

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
    << r._cycleTime << "s." << "\n";
    return os;
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    std::string s1 = "Comet can fly 14 km/s for 10 seconds, but then must rest for 127 seconds.";

    Reindeer comet (s1);
    std::cout << comet;
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