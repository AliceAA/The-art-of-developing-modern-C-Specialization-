
/*
//#pragma once

#include <string>

using namespace std;

class PhoneNumber {
public:
  //  Принимает строку в формате +XXX-YYY-ZZZZZZ
  //    Часть от '+' до первого '-' - это код страны.
  //    Часть между первым и вторым символами '-' - код города
  //    Всё, что идёт после второго символа '-' - местный номер.
  //    Код страны, код города и местный номер не должны быть пустыми.
  //    Если строка не соответствует этому формату, нужно выбросить исключение invalid_argument. Проверять, что номер содержит только цифры, не нужно.

  //    Примеры:
  //    * +7-495-111-22-33
  //    * +7-495-1112233
  //    * +323-22-460002
  //    * +1-2-coursera-cpp
  //    * 1-2-333 - некорректный номер - не начинается на '+'
  //    * +7-1233 - некорректный номер - есть только код страны и города
  
  explicit PhoneNumber(const string &international_number);

  string GetCountryCode() const;
  string GetCityCode() const;
  string GetLocalNumber() const;
  string GetInternationalNumber() const;

private:
  string country_code_;
  string city_code_;
  string local_number_;
};
*/
#include <phone_number.h>
#include <stdexcept> 
#include <iostream>

PhoneNumber::PhoneNumber(const string &international_number){

  if(international_number[0]=='+'){
    int first =0;
    int second = 0;
    bool once = true;
    for (int i=0; i<international_number.length(); ++i)
  {
    if(international_number.at(i)=='-'&&once){
      first = i;
      once = false;
    } else if(international_number.at(i)=='-') {
      second = i;
      break;
      }
  }
  if (first!=1&&second-first!=1&&first!=0&&second!=0&&second!=(international_number.length()-1)){

    country_code_ = international_number.substr(1,first-1);
    city_code_ = international_number.substr(first+1, second-first-1);
    local_number_ = international_number.substr(second+1);

  } else throw invalid_argument("");
  
  
  } else throw invalid_argument("");

}

string PhoneNumber::GetCountryCode() const{
  return country_code_;
}

string PhoneNumber::GetCityCode() const{
  return city_code_;
}

string PhoneNumber::GetLocalNumber() const{
  return local_number_;
}

string PhoneNumber::GetInternationalNumber() const{
  return '+'+country_code_+'-'+city_code_+'-'+local_number_;
}

/*
int main(){
  PhoneNumber p1("+-h-d");
  cout<<p1.GetCountryCode()<<"   "<<p1.GetCityCode()<<"   "<<p1.GetLocalNumber()<<endl;
  cout<<p1.GetInternationalNumber();
}*/



