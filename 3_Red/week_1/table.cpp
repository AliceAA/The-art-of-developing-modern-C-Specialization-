#include "test_runner.h"
#include <vector>
#include <iostream>

using namespace std;

template <typename T> class Table {
 private:
  vector<vector<T>> table;

 public:
  Table(size_t rows, size_t columns) {
    Resize(rows, columns);
  }

  const vector<T>& operator [] (size_t idx) const {
    return table[idx];
  }

  vector<T>& operator [] (size_t idx) {
    return table[idx];
  }

  void Resize(size_t rows, size_t columns) {
    table.resize(rows);
    for (auto& item : table) {
      item.resize(columns);
    }
  }

  pair<size_t, size_t> Size() const {
    return {table.size(), (table.empty() ? 0 : table[0].size())};
  }

};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}


