#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = "") {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

//bool IsPalindrom(const string& str) {}

void TestDiv() {
  AssertEqual(IsPalindrom(""), true);
  AssertEqual(IsPalindrom("j"), true);
  AssertEqual(IsPalindrom("qwerttrewq"), true);

  AssertEqual(IsPalindrom("wa sitacaroracatisaw"), false);
  AssertEqual(IsPalindrom("qwewqr"), false);
  AssertEqual(IsPalindrom("aqwwq"), false);

  AssertEqual(IsPalindrom("qwerewq"), true);
  AssertEqual(IsPalindrom("qwertyuiytrewq"), false);
  AssertEqual(IsPalindrom(".9 n n 9."), true);

  AssertEqual(IsPalindrom("777777"), true);
  AssertEqual(IsPalindrom("AdfAfdA"), true);
  AssertEqual(IsPalindrom("  )))  "), true);
    AssertEqual(IsPalindrom(" "), true);
  AssertEqual(IsPalindrom("      "), true);

  AssertEqual(IsPalindrom("7.77777"),false);
  AssertEqual(IsPalindrom("qqqQ"), false);
  AssertEqual(IsPalindrom("baobab"), false);
  AssertEqual(IsPalindrom("baobao"), false);
  AssertEqual(IsPalindrom(" )))  "), false);
  AssertEqual(IsPalindrom("777778"), false);

}

int main() {
  TestRunner tr;
  tr.RunTest(TestDiv, "TestDiv");
  return 0;
}