#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>
using namespace std;


template<typename Key, typename Value>
Value &GetRefStrict( map<Key, Value> &dict, Key key_one);

template<typename Key, typename Value>
Value &GetRefStrict ( map<Key, Value> &dict, Key key_one){
   if (dict.find(key_one) == dict.end()){
     throw  runtime_error("");
   } else{
     return dict.at(key_one);
   }
 }

/*
int main ( ){
  map<int, string> m = {{0, "value"}};
  string& item = GetRefStrict(m, 0);
  item = "newvalue";
  cout << m[0] << endl; // выведет newvalue
}
*/