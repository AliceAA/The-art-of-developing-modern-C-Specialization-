#include <vector>
#include <set>
#include<string>
#include<algorithm>
#include <iostream>
#include <sstream>
using namespace std;
#include <bits/stdc++.h> 


template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
  if (range_end-range_begin<2){return;}

  vector<typename RandomIt::value_type> elements(range_begin, range_end);

  int half_size = elements.size() / 2;
  //vector<typename RandomIt::value_type> lhs(range_begin, range_begin+half_size);//
  //vector<typename RandomIt::value_type> rhs(range_begin+half_size, range_end);//
	auto left_iter1 = elements.begin();
	auto right_iter2 = elements.end();
	auto left_iter2 = left_iter1 + half_size;
	auto right_iter1 = left_iter1 +  half_size;

  MergeSort(left_iter1, left_iter2);
  MergeSort (right_iter1, right_iter2);

  merge(left_iter1, left_iter2, right_iter1, right_iter2, range_begin);//
}


int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}



