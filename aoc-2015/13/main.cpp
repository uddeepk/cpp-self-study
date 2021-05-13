#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <ranges>
#include <algorithm>
#include "Solution.hpp"

using std::string;
using std::tuple;
using std::map;

void star1(const std::string &filename);
map< tuple<string, string>, int> getHappinessMap (const string&); // or pass stream ?
std::pair< tuple<string, string>, int> getHappinessPair (const string &s);
//std::vector<string> tokenize (const string &s);
void print(std::vector <string> s) ;
void print(std::pair<tuple<string, string>, int> p);

int main() {
//    std::cout << "Hello, World!" << std::endl;
//
//    string testS = "Alice would gain 54 happiness units by sitting next to Bob.";
//    string testS2 = "Alice would lose 79 happiness units by sitting next to Carol.";
//    // check tokenize
//    auto t = tokenize("Alice would gain 54 happiness units by sitting next to Bob.");
//    print(t);
//
//    // check pair
//    auto p = getHappinessPair(testS);
//    print (p);
//
//    auto t2 = tokenize(testS2);
//    print(t2);
//
//    auto p2 = getHappinessPair(testS2);
//    print(p2);
//    // Star1
//
//    for (const auto &c: t) {
//        if(std::ranges::find(t2, c) == t2.end())
//            t2.push_back(c);
//    }
//
//    print(t2);
//
//    std::ranges::sort(t2);
//
//    print(t2);
//    std::next_permutation(t2.begin(), t2.end()-1);
//    print (t2);

//    Solution soln("test.txt");

//    print(soln._names);
//    std::cout << soln.calculateScore(soln._names) << "\n";

//    std::cout << soln.maxScore() << "\n";

    Solution mySoln ("input");
    std::cout << "Star1: " << mySoln.maxScore();
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

        happinessScores.insert(currentPair);
    }

    // return happinessScores map
    return happinessScores;
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
//
//std::vector<string> tokenize (const string &s) {
//    std::vector<string> tokens;
//    std::istringstream iss (s);
//    string word;
//    while (std::getline(iss, word, ' ')) {
//        tokens.push_back(word);
//    }
//    return tokens;
//}

void print(std::vector <string> v) {
    for( const auto &x: v) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

void print(std::pair<tuple<string, string>, int> p) {
    std::cout << std::get<0> (p.first) << "," << std::get<1>( p.first) << ":" << p.second << "\n";
}
/*
void Solution::addNames(const std::vector<string> &names) {
    for (const auto &c: names) {
        if(std::ranges::find(_names, c) == _names.end())
            _names.push_back(c);
    }
}
 */

