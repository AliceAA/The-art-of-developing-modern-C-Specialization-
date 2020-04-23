#include "test_runner.h"

#include <vector>
using namespace std;

template <typename T>
class LinkedList {
public:
  struct Node {
    T value;
    Node* next = nullptr;
  };

  ~LinkedList(){
    auto node_to_delete = GetHead();

    if (node_to_delete == nullptr)
    {
		delete node_to_delete;
		return;
    }

	auto iter_node = node_to_delete->next;

    if (iter_node == nullptr)
    {
		delete node_to_delete;
		delete iter_node;
        return;
    }

    while (iter_node != nullptr)
    {
		delete node_to_delete;
		node_to_delete = iter_node;
		iter_node = iter_node->next;
    }

	delete node_to_delete;
	delete iter_node;
  }

  void PushFront(const T& value){
    Node* temp_head = new Node;
    temp_head->value = value;
    temp_head->next = head;

    head = temp_head;

  }	

  void InsertAfter(Node* node, const T& value){
    if(node==nullptr){
      PushFront(value);
    } else{
      Node* insert_node = new Node;
      insert_node->value = value;
      insert_node->next = node->next;

      node->next= insert_node;
    }
  }

  void RemoveAfter(Node* node){
    if(node == nullptr){
      PopFront();
    } else if (node->next == nullptr){
        return;
    } else{
      Node* temp = node->next;
      node->next = temp->next;//
      temp->next = nullptr;
      delete temp;
    }
  }

  void PopFront(){
    if(head == nullptr){
      return;
    } else {
      Node* temp = head;
      head = head->next;
      temp->next = nullptr;
      delete temp;
    }
  }

  Node* GetHead() { return head; }
  const Node* GetHead() const { return head; }

private:
  Node* head = nullptr;
};



template <typename T>
vector<T> ToVector(const LinkedList<T>& list) {
  vector<T> result;
  for (auto node = list.GetHead(); node; node = node->next) {
    result.push_back(node->value);
  }
  return result;
}

void TestPushFront() {
  LinkedList<int> list;

  list.PushFront(1);
  ASSERT_EQUAL(list.GetHead()->value, 1);
  list.PushFront(2);
  ASSERT_EQUAL(list.GetHead()->value, 2);
  list.PushFront(3);
  ASSERT_EQUAL(list.GetHead()->value, 3);

  const vector<int> expected = {3, 2, 1};
  ASSERT_EQUAL(ToVector(list), expected);
}

void TestInsertAfter() {
  LinkedList<string> list;

  list.PushFront("a");
  auto head = list.GetHead();
  ASSERT(head);
  ASSERT_EQUAL(head->value, "a");

  list.InsertAfter(head, "b");
  const vector<string> expected1 = {"a", "b"};
  ASSERT_EQUAL(ToVector(list), expected1);

  list.InsertAfter(head, "c");
  const vector<string> expected2 = {"a", "c", "b"};
  ASSERT_EQUAL(ToVector(list), expected2);
}

void TestRemoveAfter() {
  LinkedList<int> list;
  for (int i = 1; i <= 5; ++i) {
    list.PushFront(i);
  }

  const vector<int> expected = {5, 4, 3, 2, 1};
  ASSERT_EQUAL(ToVector(list), expected);

  auto next_to_head = list.GetHead()->next;
  list.RemoveAfter(next_to_head); // СѓРґР°Р»СЏРµРј 3
  list.RemoveAfter(next_to_head); // СѓРґР°Р»СЏРµРј 2

  const vector<int> expected1 = {5, 4, 1};
  ASSERT_EQUAL(ToVector(list), expected1);

  while (list.GetHead()->next) {
    list.RemoveAfter(list.GetHead());
  }
  ASSERT_EQUAL(list.GetHead()->value, 5);
}

void TestPopFront() {
  LinkedList<int> list;

  for (int i = 1; i <= 5; ++i) {
    list.PushFront(i);
  }
  for (int i = 1; i <= 5; ++i) {
    list.PopFront();
  }
  ASSERT(list.GetHead() == nullptr);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestPushFront);
  RUN_TEST(tr, TestInsertAfter);
  RUN_TEST(tr, TestRemoveAfter);
  RUN_TEST(tr, TestPopFront);
  return 0;
}