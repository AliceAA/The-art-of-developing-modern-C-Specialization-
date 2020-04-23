#include <vector>
#include<algorithm>
#include <iostream>
using namespace std;
/*
enum class Gender {
  FEMALE,
  MALE
};


struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};

// Это пример функции, его не нужно отправлять вместе с функцией PrintStats
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

void PrintStats(vector<Person> persons);

*/

void PrintStats(vector<Person> persons){
  vector<Person> female;
  vector<Person> male;
  vector<Person> female_employed;
  vector<Person> female_unemployed;
  vector<Person> male_employed;
  vector<Person> male_unemployed;

  partition_copy(persons.begin(), persons.end(),back_inserter(female), back_inserter(male), 
        [](const Person& p){return p.gender == Gender::FEMALE;});
  partition_copy(female.begin(), female.end(),back_inserter(female_employed), back_inserter(female_unemployed),
          [](const Person& p){return p.is_employed;});
  partition_copy(male.begin(), male.end(),back_inserter(male_employed), back_inserter(male_unemployed),  
        [](const Person& p){return p.is_employed;});


  cout<<"Median age = "<< ComputeMedianAge(persons.begin(), persons.end()) <<endl;;
  cout<<"Median age for females = "<< ComputeMedianAge(female.begin(), female.end()) <<endl;;
  cout<<"Median age for males = "<< ComputeMedianAge(male.begin(), male.end()) <<endl;;
  cout<<"Median age for employed females = "<< ComputeMedianAge(female_employed.begin(), female_employed.end()) <<endl;;
  cout<<"Median age for unemployed females = "<< ComputeMedianAge(female_unemployed.begin(), female_unemployed.end()) <<endl;;
  cout<<"Median age for employed males = "<< ComputeMedianAge(male_employed.begin(), male_employed.end()) <<endl;;
  cout<<"Median age for unemployed males = "<< ComputeMedianAge(male_unemployed.begin(), male_unemployed.end()) <<endl;;


}
/*
int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}
*/