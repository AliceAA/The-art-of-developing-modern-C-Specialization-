#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <bits/stdc++.h> 
#include <limits>

#include <tuple>
#include <algorithm>
using namespace std;
/*
enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  __int64_t population;
};
*/


bool operator<(const Region& lhs, const Region& rhs) {
  return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
      tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
  int n = 0;
  map<Region, int> regcount;
  for (const Region& region : regions) {
    n = max(n, ++regcount[region]);
  }
  return n;
}

// bool operator== (const Region& lhs, const Region& rhs){
//   return (lhs.std_name==rhs.std_name 
//     && lhs.parent_std_name==rhs.parent_std_name 
//     && lhs.population==rhs.population
//     && lhs.names.size()==rhs.names.size()
//     && std::equal(lhs.names.begin(), lhs.names.end(), rhs.names.begin()));
// }

// int FindMaxRepetitionCount(const vector<Region>& regions){
//   if (regions.size()==0){
//     return 0;
//   } else{
//     int n = 0;
//     for(const auto& item : regions){
//       int rep = count(regions.begin(), regions.end(),item);
//       if(n < rep){
//         n = rep;
//       }
//     }
//     return n;
//   }
// };
/*
int main() {
  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      },
  }) << endl;
  
  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Toulouse",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          31
      },
  }) << endl;
  
  return 0;
}
*/