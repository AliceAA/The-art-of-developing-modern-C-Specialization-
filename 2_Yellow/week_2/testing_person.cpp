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
/*
class Person {
public:
  // Р’С‹ РјРѕР¶РµС‚Рµ РІСЃС‚Р°РІР»СЏС‚СЊ СЃСЋРґР° СЂР°Р·Р»РёС‡РЅС‹Рµ СЂРµР°Р»РёР·Р°С†РёРё РєР»Р°СЃСЃР°,
  // С‡С‚РѕР±С‹ РїСЂРѕРІРµСЂРёС‚СЊ, С‡С‚Рѕ РІР°С€Рё С‚РµСЃС‚С‹ РїСЂРѕРїСѓСЃРєР°СЋС‚ РєРѕСЂСЂРµРєС‚РЅС‹Р№ РєРѕРґ
  // Рё Р»РѕРІСЏС‚ РЅРµРєРѕСЂСЂРµРєС‚РЅС‹Р№
  void ChangeFirstName(int year, const string& first_name) {
  }
  void ChangeLastName(int year, const string& last_name) {
  }
  string GetFullName(int year) {
  }
};
*/
void TestDiv() {
  Person p1;
  Person p2;
  AssertEqual(p1.GetFullName(2019), "Incognito");
  p1.ChangeLastName(2000, "A");
  p2.ChangeFirstName(2000, "A2");
  AssertEqual(p1.GetFullName(2019), "A with unknown first name");
  AssertEqual(p2.GetFullName(2019), "A2 with unknown last name");

  AssertEqual(p1.GetFullName(1933), "Incognito");
  AssertEqual(p2.GetFullName(486), "Incognito");

  p1.ChangeFirstName(2010, "B");
  p2.ChangeLastName(2010, "B2");

  AssertEqual(p1.GetFullName(2019), "B A");
  AssertEqual(p2.GetFullName(2019), "A2 B2");

  AssertEqual(p1.GetFullName(2009), "A with unknown first name");
  AssertEqual(p2.GetFullName(2009), "A2 with unknown last name");

  AssertEqual(p1.GetFullName(1933), "Incognito");
  AssertEqual(p2.GetFullName(486), "Incognito");

  p1.ChangeLastName(1000, "C");
  p2.ChangeFirstName(2100, "C2");
  p1.ChangeFirstName(1010, "D");
  p2.ChangeLastName(2110, "D2");

  AssertEqual(p1.GetFullName(133), "Incognito");
  AssertEqual(p2.GetFullName(486), "Incognito");

  AssertEqual(p1.GetFullName(1009), "C with unknown first name");
  AssertEqual(p1.GetFullName(1049), "D C");
  AssertEqual(p1.GetFullName(2001), "D A");
  AssertEqual(p1.GetFullName(2049), "B A");



}

int main() {
  TestRunner tr;
  tr.RunTest(TestDiv, "TestDiv");
  return 0;
}