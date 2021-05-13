//
// Created by uddeepk on 5/12/21.
//

#ifndef INC_13_SOLUTION_HPP
#define INC_13_SOLUTION_HPP

#include <map>
#include <vector>
#include <tuple>
class Solution {
public:
    Solution(const std::string &filename);
    int maxScore ();

    void addSelf();
private:
    std::map<std::tuple<std::string, std::string>, int> _happinessMap;
    std::vector <std::string> _names {};

    std::pair<std::tuple<std::string, std::string>, int> getHappinessPair(const std::string &s);
    std::map< std::tuple<std::string, std::string>, int> getHappinessMap (const std::string &filename);

    void addNames(const std::vector<std::string> &names);

    int calculateScore (std::vector <std::string> v);


};
std::vector<std::string> tokenize (const std::string &s);


#endif //INC_13_SOLUTION_HPP
