//
// Created by uddeepk on 5/12/21.
//

#ifndef INC_13_SOLUTION_HPP
#define INC_13_SOLUTION_HPP

#include <map>
#include <vector>
#include <tuple>
#include <string>

class Solution {
public:
    Solution(const std::string &filename);

private:
    std::map<std::tuple<std::string, std::string>, int> happinessMap;
    std::vector <std::string> names;

    std::pair<std::tuple<std::string, std::string>, int> getHappinessPair(const std::string &s);
    std::map< std::tuple<std::string, std::string>, int> getHappinessMap (const std::string &filename);



};
std::vector<std::string> tokenize (const std::string &s);


#endif //INC_13_SOLUTION_HPP
