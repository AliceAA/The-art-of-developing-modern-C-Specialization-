#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
  __int64_t n, temp;
  __int64_t n_greater = 0;
  __int64_t average = 0;
  vector <__int64_t> numbers;

  //cout<<((numeric_limits<__int64_t>::max())>1000000000000);
  cin>>n;

  for (__int64_t i = 0; i<n;i++){
    cin>>temp;
    average+=temp;
    numbers.push_back(temp);
  }
  average/=static_cast<int>(numbers.size());

  for (__int64_t i = 0; i<n;i++){
    if(numbers[i]>average){n_greater+=1;}
  }
  cout<<n_greater<<endl;

  for (__int64_t i = 0; i<n;i++){
    if(numbers[i]>average){cout<<i<<" ";}
  }
}