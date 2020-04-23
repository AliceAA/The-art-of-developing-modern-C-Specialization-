#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
  __uint32_t n, r;
  __uint16_t w, h;
  __uint64_t d;
  __uint64_t total = 0;
  //cout<<((numeric_limits<__uint32_t>::max())>1'000'000'000'000);
  //cout<<((numeric_limits<__int64_t>::max()));//>1'000'000'000'000'000'000
  cin>>n>>r;
  for (__uint32_t i; i<n;i++){
    cin>>w>>h>>d;
    total+=w*h*d;
  }

  cout<<r*total;

}