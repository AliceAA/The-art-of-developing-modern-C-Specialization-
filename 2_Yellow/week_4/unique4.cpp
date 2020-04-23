#include <vector>
#include <set>
#include<string>
#include<algorithm>
#include <iostream>
#include <sstream>
using namespace std;


template <typename T>
void RemoveDuplicates(vector<T>& elements);


template <typename T>
void RemoveDuplicates(vector<T>& elements){
  sort(elements.begin(), elements.end()); 
  auto last = std::unique(elements.begin(), elements.end());
    // v сейчас содержит {1 2 3 4 5 6 7 x x x x x x}, где 'x' обозначает неопределённый элемент
    elements.erase(last, elements.end()); 

}
/*
int main() {
  vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
  RemoveDuplicates(v1);
  for (int x : v1) {
    cout << x << " ";
  }
  cout << endl;
  
  vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
  RemoveDuplicates(v2);
  for (const string& s : v2) {
    cout << s << " ";
  }
  cout << endl;
  return 0;
}
*/