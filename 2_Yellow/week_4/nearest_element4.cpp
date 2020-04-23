 #include <vector>
#include <set>
#include<string>
#include<algorithm>
#include <iostream>
#include <sstream>
using namespace std;
#include <bits/stdc++.h> 


set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border){
  // set<int>::const_iterator —
  // тип итераторов для константного множества целых чисел
  if(numbers.size()==0){return end(numbers);}

  auto it = numbers.lower_bound( border);
  if((*it)==border||it==numbers.begin()){return it;}
  if(it==numbers.end()){return prev(it);}

  //cout<<border-(*it)<<"  < "<<border-*(prev(it))<<"        :"<<border<<endl;
  if ((*it)-border<border-*(prev(it))){return it;}
  else {return prev(it);}
}
/*
int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;
      
  set<int> empty_set;
  
  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
*/