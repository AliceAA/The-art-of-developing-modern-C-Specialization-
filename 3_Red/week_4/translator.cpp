#include "test_runner.h"
#include <string>
#include<iostream>
#include <vector>
#include<queue>
#include <set>

using namespace std;

class Translator {
public:
  void Add(string_view source, string_view target){
    source= *data.insert(string(source)).first;
    target= *data.insert(string(target)).first;

    forward[source] = target;
    backward[target] = source;
  }
  string_view TranslateForward(string_view source) const{
    if(!forward.count(source)){
      return "";
    }
    return forward.at(source);
  }
  string_view TranslateBackward(string_view target) const{
    if(!backward.count(target)){
      return "";
    }
      return backward.at(target);
  }

private:
  map <string_view, string_view> forward;
  map <string_view, string_view> backward;
  string all;
  set<string> data;

};

void TestSimple() {
  Translator translator;
  translator.Add(string("okno"), string("window"));
  translator.Add(string("stol"), string("table"));

  //cout<<translator.TranslateForward("okno")<<endl<<endl;
  ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
  ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
  ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSimple);
  return 0;
}