#include <iostream>
#include <list>
#include <map>
#include <set>

using namespace std;

int main() {
  int n;
  cin>>n;
  map <int, int> order; 
  list <int> sportsman;
  set <int> set_;
  int before_, after_;
  int item = 100001;

  for (int i =0; i<n; i++){
    cin>>before_>>after_;
    if(!set_.count(after_)){
      after_ = item;
    } 
    if(!order.count(after_)){
      order[after_] = before_;
    } else{
      order[before_] = order[after_];
      order[after_] = before_;
    }
    set_.insert(before_);
  }
  int temp;
  for (int i = 0; i<order.size(); i++){
    temp = order[item];
    sportsman.push_front(temp);
    item = temp;
  }
  for (auto i : sportsman){
    cout<<i<<" ";
  }
  

}