//#pragma once

#include <stdexcept>
#include<iostream>
#include <array>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
  explicit StackVector(size_t a_size = 0){
    if (a_size>capacity_){
      throw invalid_argument("");
    } else{
      size_ = a_size;
    }
  }

  T& operator[](size_t index){ return my_array[index];}
  const T& operator[](size_t index) const{ return my_array[index];}

  auto begin(){ return my_array.begin();}
  auto end(){ return my_array.begin()+(size_);}
  auto begin() const { return my_array.begin();}
  auto end() const{ return my_array.begin()+(size_);}

  size_t Size() const{ return size_; }
  size_t Capacity() const{ return capacity_; }

  void PushBack(const T& value){
    if(size_==capacity_){
      //cout<<"here"<<endl;
      throw overflow_error("");
    } else{
      my_array[size_] = value;
      size_ +=1;
    }
  }

  T PopBack(){
    if(size_==0){
      throw underflow_error("");
    } else{
      size_ -=1;
      return my_array[size_];
    }
  }

private:
  size_t size_ = 0;//current number of elements
  size_t capacity_ = N;
  array<T, N> my_array;
};
