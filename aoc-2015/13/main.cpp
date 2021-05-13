#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>

using std::string;
using std::tuple;
using std::map;

void star1(const std::string &filename);
map< tuple<string, string>, int> getHappinessMap (const string&); // or pass stream ?
std::pair< tuple<string, string>, int> getHappinessPair (const string &s);
std::vector<string> tokenize (const string &s);
void print(std::vector <string> s) ;

int main() {
    std::cout << "Hello, World!" << std::endl;

    // check tokenize
    auto t = tokenize("Alice would gain 54 happiness units by sitting next to Bob.");
    print(t);
    // Star1
    return 0;
}


void star1(const std::string &filename) {

    // Get the Happiness Scores Map by passing filename
    // Get the list of names

    // Get total happiness score from optimal arrangement

    // Print score


}

map< tuple<string, string>, int> getHappinessMap (const string &filename) {
    std::ifstream myFile(filename);
    string readBuffer;
    map< tuple<string, string>, int> happinessScores;

    while (std::getline(myFile, readBuffer)) {
        // Pass line and get the pair from readBuffer
        auto currentPair = getHappinessPair (readBuffer);
        // Add the pair to happinessScores
    }

    // return happinessScores map
}

std::pair<tuple<string, string>, int > getHappinessPair (const string &s) {
    std::vector <string> tokens = tokenize (s);

    string name1, name2, diff;

    int score;

    name1 = tokens.front();
    name2 = tokens.back();
    name2.pop_back(); // to remove the period

    diff = tokens[2];

    score = std::stoi(tokens[3]);

    if ( diff == "lose")
        score *= (-1);

    return std::make_pair( std::make_tuple(name1, name2) , score);
}

std::vector<string> tokenize (const string &s) {
    std::vector<string> tokens;
    std::istringstream iss (s);
    string word;
    while (std::getline(iss, word, ' ')) {
        tokens.push_back(word);
    }
    return tokens;
}

void print(std::vector <string> v) {
    for( const auto &x: v) {
        std::cout << x << " ";
    }
}