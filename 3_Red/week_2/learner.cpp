

#include <algorithm>
#include <string>
#include <vector>
#include<set>
#include<iostream>
#include<sstream>

using namespace std;

class Learner {
 private:
  vector<string> dict;
  set<string> my_set;

 public:
  int Learn(const vector<string>& words) {
    int prev = my_set.size();
    copy(words.begin(), words.end(),inserter(my_set, my_set.end()));

    int newWords = my_set.size()-prev;

    return newWords;
  }

  vector<string> KnownWords() {
    vector<string> v(my_set.begin(), my_set.end());
    return v;
  }
};

int main() {
  Learner learner;
  string line;
  while (getline(cin, line)) {
    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word) {
      words.push_back(word);
    }
    cout << learner.Learn(words) << "\n";
  }
  cout << "=== known words ===\n";
  for (auto word : learner.KnownWords()) {
    cout << word << "\n";
  }
}