#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include<map>
#include<set>
#include<iterator>

using namespace std;

class ReadingManager {
public:
  ReadingManager() {}

  void Read(int user_id, int page_count) {
    if (users.find(user_id) != users.end()) {
      pages.erase(pages.lower_bound(users.at(user_id)));
    }
    users[user_id] = page_count;
    pages.insert(page_count);
  }

  double Cheer(int user_id) {
    if ((users.find(user_id) == users.end())) {
      return 0;
    }
    const double user_count = pages.size();
    if (user_count == 1.) {
      return 1;
    }

    int limit = users.at(user_id);
    auto it = pages.find(limit);
    if(it ==pages.begin()) {return 0;}
    
    double result = static_cast<double>(distance(pages.begin(),it))/(user_count-1);

    return result;
  }

private:
  map <int, int> users;
  multiset<int> pages;
  
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }

  return 0;
}