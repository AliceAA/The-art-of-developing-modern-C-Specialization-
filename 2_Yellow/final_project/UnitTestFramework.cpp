// #include "condition_parser.h"
// #include "token.h"
// #include <map>
// #include "date.h"
// #include <iostream>


using namespace std;


// template<class T, class U>
// void AssertEqual(const T& t, const U& u,
//     const string& hint)
// {
//   if (t != u) {
//     ostringstream os;
//     // os << "Assertion failed: " << t << " != " << u
//     //   << " hint: " << hint;
//     throw runtime_error(os.str());
//   }
// }


// class TestRunner {
// public:
//   template <class TestFunc>
//   void RunTest(TestFunc func, const string& test_name) {
//     try {
// 	  func();
// 	  cerr << test_name << " OK" << endl;
// 	} catch (runtime_error& e) {
// 	  ++fail_count;
// 	  cerr << test_name << " fail: " << e.what() << endl;
// 	}
//   }

//   ~TestRunner() {
//     if (fail_count > 0) {
//       cerr << fail_count << " unit tests failed. Terminate" << endl;
//       exit(1);
//     }
//   }

// private:
//   int fail_count = 0;
// };

// void Assert(bool cond, const std::string& hint)
// {
// 	AssertEqual(cond, true, hint);
// }

#include "UnitTestFramework.h"


void Assert(bool cond, const std::string& hint)
{
	AssertEqual(cond, true, hint);
}


TestRunner::TestRunner()
{
	fail_count = 0;
}


TestRunner::~TestRunner()
{
	if (fail_count > 0)
	{
		std::cerr << fail_count << " tests failed. Terminate";
		exit(1);
	}
}