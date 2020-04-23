#include <vector>
#include<string>
#include<algorithm>
#include <iostream>
#include <sstream>
using namespace std;



vector<string> SplitIntoWords(const string& s){
  istringstream is(s);
  vector<string> result;
  string temp;
  auto res = s.begin();
  auto prev = s.begin();

  while(getline(is, temp, ' ')){
    //res = find_if(res; s.end();[](const auto& n){return n==" ";} );
    
    result.push_back(temp);

    //prev = res;
  }
  return result;
}

/*
int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = words.begin(); it != words.end(); ++it) {
    if (it != words.begin()) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}*/