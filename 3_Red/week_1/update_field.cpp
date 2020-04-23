#include "airline_ticket.h"
#include "test_runner.h"

#include <algorithm>
#include <numeric>
using namespace std;

#include <sstream>

bool operator< (Date lhs, Date rhs){
  if (lhs.year==rhs.year){
    if (lhs.month==rhs.month){
      return (lhs.day<rhs.day);
    } else return (lhs.month<rhs.month);
  } else return (lhs.year<rhs.year);
}

bool operator== (Date lhs, Date rhs){
  if (lhs.year==rhs.year&&lhs.month==rhs.month&&lhs.day==rhs.day)
    {return true;}
   else 
    {return false;}
}

bool operator> (Date lhs, Date rhs){
  return !(lhs<rhs)||(lhs==rhs);
}

ostream& operator << (ostream& os, Date d) {
  os << d.year<<"-"<<d.month<<"-"<<d.day<<endl;
  return os;
}

istream& operator >> (istream& is, Date& d){
  char c1, c2;
  is >>d.year>>c1>>d.month>>c2>>d.day;
  return is;
}


bool operator< (Time lhs, Time rhs){
  return (lhs.hours*60+lhs.minutes < rhs.hours*60+rhs.minutes);
}

bool operator== (Time lhs, Time rhs){
  return (lhs.hours==rhs.hours && lhs.minutes==rhs.minutes);
}

bool operator> (Time lhs, Time rhs){
  return (lhs.hours*60+lhs.minutes > rhs.hours*60+rhs.minutes);
}

ostream& operator << (ostream& os, Time t) {
  os << t.hours<<":"<<t.minutes<<endl;
  return os;
}

istream& operator >> (istream& is, Time& t){
  char c1;
  is >>t.hours>>c1>>t.minutes;
  return is;
}

#define SORT_BY(field)                                        \
  [](const AirlineTicket& lhs, const AirlineTicket& rhs)      \
  { return lhs.field < rhs.field;}                            \



#define UPDATE_FIELD(ticket, field, values)  {      \
  map<string, string>::const_iterator it;           \
  it = values.find(#field);                         \
  if (it != values.end()) {                         \
    istringstream is(it->second);                   \
    is >> ticket.field;                             \
  }                                                 \
}

void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);


  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}