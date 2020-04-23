#pragma once

#include <cstdlib>


template <typename T>
class SimpleVector {
public:
  SimpleVector(){
    data = nullptr;
  }
  explicit SimpleVector(size_t size){
    data_cap = size;
    data_size = size;
    data = new T[size];
  }
  ~SimpleVector(){
    delete[] data;
  }

  const T& operator[] (size_t index) const {
    return data[index];
  }

  T& operator[](size_t index) {
    return data[index];
  }

  T* begin() {return data;}
  T* end(){return data+data_size;}

  const T* begin()const  {return data;}
  const T* end()const {return data+data_size;}

  size_t Size() const {return data_size; }
  size_t Capacity() const{return data_cap; }

  void PushBack(const T& value){
    if(data==nullptr){
      data_cap+=1;
      data = new T[1];
    }
    if(data_size==data_cap){

      data_cap  = data_cap*2;

      T* data_temp = new T[data_size];
      
      for (int i = 0; i<data_size; i++){
        data_temp[i] = data[i];
      }
      delete[] data;

      data = new T[data_cap];
      for (int i = 0; i<data_size; i++){
        data[i] = data_temp[i];
      }

      delete[] data_temp;
    } 
    data[data_size] = value;
    data_size +=1;
  }

private:
  size_t data_cap = 0;
  size_t data_size = 0;
  T* data;
};

