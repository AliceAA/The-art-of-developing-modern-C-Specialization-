#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>
using namespace std;

template <typename V>
V Sqr (V one);

template <typename First, typename Second>
pair<First, Second> Sqr ( pair<First, Second> p);

template <typename T>
vector<T>  Sqr (vector<T> vi);

template <typename Key, typename Value>
map<Key, Value> Sqr  (  map<Key, Value> m);



template <typename V>
V Sqr (V one){
  return one*one;
}

template <typename First, typename Second>
pair<First, Second>  Sqr ( pair<First, Second> p) {
  return make_pair(p.first*p.first, p.second*p.second);
}

template <typename T>
vector<T>  Sqr (  vector<T> vi) {
  vector<T> sqr;
  for (auto i:vi){
    sqr.push_back(Sqr(i));
  }
  return sqr ;
}

template <typename Key, typename Value>
map<Key, Value>  Sqr ( map<Key, Value> m) {
  map<Key, Value> sqr;
  for (auto i:m){
    sqr[i.first] = Sqr(i.second);
  }
  return sqr ;
}

/*
int main (){
  vector<int> v = {1, 2, 3};
  cout << "vector:";
  for (int x : Sqr(v)) {
    cout << ' ' << x;
  }
  cout << endl;

  map<int, pair<int, int>> map_of_pairs = {{4, {2, 2}}, {7, {4, 3}}};
  cout << "map of pairs:" << endl;
  for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
}}*/
// vector: 1 4 9
// map of pairs:
// 4 4 4
// 7 16 9