#include <iostream>
#include <map>
#include <tuple>
#include <sstream>
#include <exception>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits>

std::map < std::tuple < std::string, std::string> , int> getDistanceBetweenCities (std::vector <std::string> &);
std::pair <std::tuple <std::string, std::string>, int> processFlightData (std::string);
void recordCity(std::vector <std::string> & , std::string, std::string);
int getShortestPath(std::vector <std::string> cities, std::map < std::tuple <std::string, std::string>, int> ,
                    std::map <std::vector <std::string>, int> &) ;
int getRouteDistance (std::vector<std::string> cities, std::map<std::vector<std::string>, int> &routes,
                      std::map<std::tuple<std::string, std::string>, int> flights);
int computeRouteDistance (std::vector<std::string> cities, std::map<std::tuple<std::string, std::string>, int> flights);
template <typename T>
void print ( const std::vector <T> &v);

using std::cout;
int main() {
//    auto x = processFlightData("London to Dublin = 464");
//
//    std::cout << std::get<0> (x.first) << std::endl;
////    x.first.swap();
//    std::vector <std::string> test { "xxx", "yy" , "zsdfs"};
//    std::next_permutation(std::begin(test), std::end(test));
//    std::cout << test[1] ;

    std::vector<std::string> cities ;

    auto flights = getDistanceBetweenCities(cities);
    std::map <std::vector <std::string>, int> routes;
//    print(cities);
//    cout << flights[std::make_tuple("Dublin", "Belfast")];
    cout << getShortestPath(cities, flights, routes);

    return 0;
}

// Returns a map of different binary flight information and a vector of a ll cities.
std::map<std::tuple<std::string, std::string>, int> getDistanceBetweenCities( std::vector <std::string> &v) {
    std::string fileName = "test.txt";
    std::ifstream myFile (fileName);

    std::map<std::tuple<std::string, std::string>, int> routeDists;

    std::string readBuffer;
    while ( std::getline (myFile, readBuffer )) {
        auto flightData = processFlightData(readBuffer);
        // Now making another pair that is the
        std::string city1 = std::get<0>(flightData.first),
                city2 = std::get<1>(flightData.first);
        recordCity(v, city1, city2);
        routeDists.insert(flightData);
    }
    return routeDists;
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

void recordCity(std::vector<std::string> &v, std::string s1, std::string s2) {
    if (std::find(std::begin(v), std::end(v), s1) == std::end(v))
        v.push_back(s1);
    if (std::find(std::begin(v), std::end(v), s2) == std::end(v))
        v.push_back(s2);
}

int getShortestPath(std::vector<std::string> cities, std::map<std::tuple<std::string, std::string>, int> flights,
                    std::map<std::vector<std::string>, int> &routes) {
    int shortestPath = INT32_MAX;
    do {
        int routeDistance = getRouteDistance( cities, routes, flights);
        if ( routeDistance < shortestPath)
            std::swap(routeDistance, shortestPath);
    } while ( std::next_permutation(std::begin(cities), std::end (cities)));
    return shortestPath;
}
template<typename T>
void print(const std::vector<T> &v) {
    for ( auto x : v) {
        std::cout << x << "\n";
    }
}

int getRouteDistance(std::vector<std::string> cities, std::map<std::vector<std::string>, int> &routes,
                     std::map<std::tuple<std::string, std::string>, int> flights) {
    if ( routes.find(cities) != std::end(routes) )
        return routes[cities];
    std::reverse(std::begin(cities), std::end(cities));
    if ( routes.find(cities) != std::end(routes) )
        return routes[cities];
    //
    int distance = computeRouteDistance( cities, flights);
    routes.insert( std::make_pair (cities, distance));
    return distance;
}

int computeRouteDistance(std::vector<std::string> cities, std::map<std::tuple<std::string, std::string>, int> flights) {
    int d = 0;
    for ( auto it = std::begin(cities) ; it != std::end(cities) - 1 ; ++it) {
        auto r1 = std::make_tuple(*it, *(it + 1));
        auto r2 = std::make_tuple(*(it+1), *it);

        if ( flights.find(r1) != flights.end())
            d += flights[r1];
        else
            d += flights[r2];
    }
    return d;
}



