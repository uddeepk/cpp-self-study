//
// Created by uddeepk on 5/12/21.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include <ranges>
#include <algorithm>
#include <limits>
#include "Solution.hpp"
using std::tuple;
using std::string;
using std::map;

Solution::Solution(const std::string &filename) {
    _happinessMap = getHappinessMap(filename);
    std::ranges::sort(_names);
}

map< tuple<string, string>, int> Solution::getHappinessMap (const string &filename) {
    std::ifstream myFile(filename);
    string readBuffer;
    map< tuple<string, string>, int> happinessScores;

    while (std::getline(myFile, readBuffer)) {
        // Pass line and get the pair from readBuffer
        auto currentPair = getHappinessPair (readBuffer);
        // Add the pair to happinessScores
        happinessScores.insert(currentPair);
    }

    // return happinessScores map
    return happinessScores;
}

std::pair<tuple<string, string>, int> Solution::getHappinessPair(const string &s) {
    std::vector <string> tokens = tokenize (s);

    string name1, name2, diff;

    int score;

    name1 = tokens.front();
    name2 = tokens.back();
    name2.pop_back(); // to remove the period

    // add names to vector of names here because it'll be easier
    std::vector names {name1, name2};
    addNames(names);

    diff = tokens[2];

    score = std::stoi(tokens[3]);

    if ( diff == "lose")
        score *= (-1);

    return std::make_pair( std::make_tuple(name1, name2) , score);
}

void Solution::addNames(const std::vector<string> &names) {
    for (const auto &c: names) {
        if(std::ranges::find(_names, c) == _names.end())
            _names.push_back(c);
    }
}

int Solution::calculateScore(std::vector <std::string> v) {
    int score = 0;
//    std::cout << v.size() << "***";
    for( int i = 0 ; i < v.size() ; ++i) {
        auto myTuple = std::make_tuple(v[0], v[1]);
        score += _happinessMap[myTuple];
//        std::cout << _happinessMap[myTuple] << " ";
        auto myTupleRev = std::make_tuple(v[1], v[0]);
        score += _happinessMap[myTupleRev];
//        std::cout << _happinessMap[myTupleRev]<< " ";
        std::rotate(v.begin(), v.begin() + 1, v.end());

    }
//    std::cout << "\n";
    return score;
}

int Solution::maxScore() {
    int max = std::numeric_limits<int>::min();
    do {
        int score = calculateScore(_names);
//        std::cout << score << " ";
        if (score > max )
            max = score;
    }
    while (std::next_permutation(_names.begin() + 1, _names.end()));
    return max;
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
