//
// Created by uddeepk on 5/12/21.
//
#include <sstream>
#include <fstream>
#include "Solution.hpp"
using std::tuple;
using std::string;
using std::map;

Solution::Solution(const std::string &filename):happinessMap(getHappinessMap(filename)) {

}

map< tuple<string, string>, int> Solution::getHappinessMap (const string &filename) {
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

std::pair<tuple<string, string>, int> Solution::getHappinessPair(const string &s) {
    std::vector <string> tokens = tokenize (s);

    string name1, name2, diff;

    int score;

    name1 = tokens.front();
    name2 = tokens.back();
    name2.pop_back(); // to remove the period

    // add names to vector of names here because it'll be easier
    diff = tokens[2];

    score = std::stoi(tokens[3]);

    if ( diff == "lose")
        score *= (-1);

    return std::make_pair( std::make_tuple(name1, name2) , score);
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
