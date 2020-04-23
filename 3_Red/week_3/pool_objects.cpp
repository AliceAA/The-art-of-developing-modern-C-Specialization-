#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <deque> 
#include <stdexcept>
#include <set>
using namespace std;


template <class T>
class ObjectPool {
public:
  T* Allocate(){
    if(!dall.empty()){
      all.push_front(dall.front());
      dall.pop_front();
      return *all.begin();
    } else{
        T* obj = new T;
        all.push_front(obj);
        return obj;
    }
  }
  T* TryAllocate(){
    if(!dall.empty()){
      all.push_front(dall.front());
      dall.pop_front();
      return *all.begin();
    } else{
      return nullptr;
    }
  }

  void Deallocate(T* object){
    auto it = find(all.begin(), all.end(), object);
    if(it==all.end()){
      throw invalid_argument("");
    } else{
      all.erase(it);
      dall.push_back(object);
    }
  }

  ~ObjectPool(){

    for (auto item : all){
		  delete item;
    }
	  all.clear();
    
    for (auto item : dall){
		  delete item;
    }
	  dall.clear();
  }

private:

  deque <T*> all;
  deque <T*> dall;
};

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}