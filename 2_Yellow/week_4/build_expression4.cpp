#include <vector>
#include <set>
#include<string>
#include<algorithm>
#include <iostream>
#include <sstream>
using namespace std;
#include <bits/stdc++.h> 

int main(){
    string res;
    int x;
    cin>>x;
   
    int n;
    std::cin>>n;

    deque<string> expression;
    expression.push_back(to_string(x));
    
    string operand;
    for(auto i = 0; i < n; ++i){
        expression.push_front("(");
        expression.push_back(")");
        std::cin>>operand>>x;
        expression.push_back(" ");
        expression.push_back(operand);
        expression.push_back(" ");
        expression.push_back(to_string(x));
    }
    for(auto it = expression.begin(); it != expression.end(); ++it){
        cout<<(*it);
    };
}


/*
int main() {
  int x, n;
  cin>>x;
  cin>>n;
  if (n==0){
    cout<<x;
    return 0;
  }

  string res = to_string(x);
  char operand;
  int m;
  for (int i = 0; i<n; i++){
    cin>>operand>>m;
    res = "("+res+") "+operand+" "+to_string(m);

  } 
  cout<<res;
  return 0;
}*/

