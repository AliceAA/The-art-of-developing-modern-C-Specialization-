//#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include<iterator>
#include<set>
# include "profile.h"

#include <bits/stdc++.h> 

using namespace std;



class RouteManager {
public:
  void AddRoute(int start, int finish) {
    route[start].insert(finish);
    route[finish].insert(start);
  }

  int FindNearestFinish(int start, int finish) const {
    int result1 = abs(start - finish);

    if (route.count(start) < 1) {
        return result1;
    }
    if (start == finish){
			return 0;
		}

    auto it = route.at(start).lower_bound(finish);

    if(it==(route.at(start).end())){
      return min(result1,abs(finish-*(--it)));
    } else if (it==(route.at(start).begin())){
      return min(result1, abs(finish-*(it)));
    }

    if(result1>abs(finish-*(it))){
      result1 = abs(finish-*(it));
    }
    return min(result1, abs(finish-*(--it)));
  }
private:
  map<int, set<int> > route;
};


int main() {
  
  RouteManager routes;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    
    string query_type;
    cin >> query_type;
    int start, finish;
    cin >> start >> finish;
    if (query_type == "ADD") {
      routes.AddRoute(start, finish);
    } else if (query_type == "GO") {
      cout << routes.FindNearestFinish(start, finish) << "\n";
    }
  }

  return 0;
}