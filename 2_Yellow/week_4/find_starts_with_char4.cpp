 #include <vector>
#include <set>
#include<string>
#include<algorithm>
#include <iostream>
#include <sstream>
using namespace std;
#include <bits/stdc++.h> 


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix){

  auto it1 = partition_point(range_begin, range_end, [prefix](const auto& el) {return (el[0] < prefix);});
  auto it2 = partition_point(range_begin, range_end, [prefix](const auto& el) {return (el[0] <= prefix);});
  

  return make_pair(it1,it2);
    }

int main() {
  const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};
  
  const auto m_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
  for (auto it = m_result.first; it != m_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  
  const auto p_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
  cout << (p_result.first - begin(sorted_strings)) << " " <<
      (p_result.second - begin(sorted_strings)) << endl;
  
  const auto z_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
  cout << (z_result.first - begin(sorted_strings)) << " " <<
      (z_result.second - begin(sorted_strings)) << endl;
  
  return 0;
}
