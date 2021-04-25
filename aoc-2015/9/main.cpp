#include <iostream>
#include <map>
#include <tuple>
#include <sstream>
#include <exception>

std::map < std::tuple < std::string, std::string> , int> getDistanceBetweenCities ();

std::pair <std::tuple <std::string, std::string>, int> processFlightData (std::string);


int main() {
    auto x = processFlightData("London to Dublin = 464");

    std::cout << std::get<0> (x.first) << std::endl;
//    x.first.swap();

    return 0;
}

std::map<std::tuple<std::string, std::string>, int> getDistanceBetweenCities() {
    return std::map<std::tuple<std::string, std::string>, int>();
}

std::pair<std::tuple<std::string, std::string>, int> processFlightData(std::string flight) {
    std::stringstream ss(flight);
    std::string departureCity, arrivalCity , readBuffer, readBuffer2;
    int distance;
    ss >> departureCity >> readBuffer >> arrivalCity >> readBuffer2 >> distance;
    if (readBuffer != "to" || readBuffer2 != "=") {
        throw std::runtime_error("function processFlightData: Incorrect Input");
//        exit(1);
    }

    return std::make_pair(std::make_tuple (departureCity, arrivalCity ) , distance);
}
