#include <vector>
#include <set>
#include<string>
#include<algorithm>
#include <iostream>
#include <sstream>
using namespace std;
#include <bits/stdc++.h> 


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
    
    string operand = "=";
    string prev_operand = "=";
    for(auto i = 0; i < n; ++i){
    cin>>operand>>x;
    if ((operand=="*"||operand=="/")&&(prev_operand=="+"||prev_operand=="-")){
      expression.push_front("(");
      expression.push_back(")");
    }
    expression.push_back(" ");
    expression.push_back(operand);
    expression.push_back(" ");
    expression.push_back(to_string(x));
    prev_operand = operand;
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
  char operand = '=';
  char prev_operand = '=';
  int m;
  for (int i = 0; i<n; i++){
    cin>>operand>>m;
    if ((operand=='*'||operand=='/')&&(prev_operand=='+'||prev_operand=='-')){
      res = "("+res+") "+operand+" "+to_string(m);
    } else
    {res = res+" "+operand+" "+to_string(m);}
    prev_operand = operand;

  } 
  cout<<res;
  return 0;
}

*/