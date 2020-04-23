#include <vector>
#include<algorithm>
#include <iostream>
using namespace std;


void PrintVectorPart(const vector<int>& numbers){
  auto res = find_if(numbers.begin(), numbers.end(),[](const int& n){return n<0;} );
  for(auto it = res; it!=numbers.begin();){
    cout<<*(--it)<<" ";
  }
}

int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}


