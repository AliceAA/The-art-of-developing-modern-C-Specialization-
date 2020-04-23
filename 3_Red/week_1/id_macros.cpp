#include <string>
#include <vector>
using namespace std;



#define f2(lineno)          var_##lineno
#define f(lineno)           f2(lineno)
#define UNIQ_ID                         f(__COUNTER__)


int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
}