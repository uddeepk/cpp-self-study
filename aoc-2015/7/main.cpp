#include <iostream>
#include <map>
#include <sstream>
#include <exception>
#include <fstream>
#include <vector>

struct Gate {
    // lhs, rhs, operator, and variable to hold result

};
using std::map;
using std::string;
using std::vector;

std::istream  &star1(std::istream &is, std::map <std::string, unsigned short> & m) ;
bool getValue ( unsigned short &n, std::map <std::string, unsigned short> & m , const std::string &s) ;
bool isNumber (const std::string &s);
int main() {
    map <string, unsigned short> vars ;

    std::ifstream myFile ("input");
    // Parse Input ?

    star1(myFile, vars);
    myFile.close();

    std::cout << "Star 1 = " << vars["a"] << "\n";
    auto s1 = vars["a"];

    vars.clear();
    vars["b"] = s1;
    myFile.open ("input");
    // Parse Input ?

    star1(myFile, vars);
    myFile.close();
    std::cout << "Star 2 = " << vars["a"];

    return 0;
}
std::istream &star1(std::istream &is, std::map <std::string, unsigned short> & m) {
    string inputLine;
    vector <string> myStack;
    while (getline(is, inputLine)) {
        myStack.push_back(inputLine);
    }
//    while (getline (is, inputLine)) {
    while (!myStack.empty()) {
        for (auto it = myStack.begin() ; it != myStack.end(); ++it) {
            std::istringstream iss(*it);
            // lhs
            string readBuffer;
            iss >> readBuffer;
            unsigned short lhs, rhs, result;
            if (readBuffer == "NOT") {
                // Perform operation for Not
                iss >> readBuffer;
                if( !getValue(rhs, m, readBuffer))
                    continue;
                result = ~rhs;
                iss >> readBuffer;
            } else {
                if (!getValue(lhs, m, readBuffer))
                    continue;
                // check assignment ? or loop ?
                iss >> readBuffer;
                if (readBuffer == "->") {
                    result = lhs;
                } else {
                    // readBuffer has operator
                    string myOperator = readBuffer;
//                std::cout << myOperator ;
                    iss >> readBuffer;
                    if(!getValue(rhs, m, readBuffer))
                        continue;
                    if (myOperator == "AND")
                        result = lhs & rhs;
                    else if (myOperator == "OR") {
                        result = lhs | rhs;
//                    std::cout << result << std::endl;
                    } else if (myOperator == "LSHIFT")
                        result = lhs << rhs;
                    else if (myOperator == "RSHIFT")
                        result = lhs >> rhs;
                    else {
                        std::cerr << "Error with operator " << std::endl;
                        throw std::runtime_error("Operator input");
                    }
                    iss >> readBuffer;
                }

            }
            iss >> readBuffer; // varname
            string varName = readBuffer;
//        std::cout << lhs << " " << rhs ;
            if (m.find(varName) != m.end()) {
                m[varName] = result;
            } else {
                m.insert(std::pair<string, unsigned short>{varName, result});
//            std::cout << varName ;//<< m[varName] ;
            }
            inputLine = "";
            myStack.erase(it);
            break;
        }
    }
    return is;
}


bool getValue (  unsigned short &n, std::map <std::string, unsigned short> & m , const std::string &s) {
    if (m.find(s) != m.end()) {
        n = m[s];
        return true;
    }

    if ( isNumber(s)) {
        n = static_cast <unsigned short> (std::stoul (s));
        return true;
    }
    return false;
}

bool isNumber (const std::string &s) {
    for (const auto &c : s) {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}