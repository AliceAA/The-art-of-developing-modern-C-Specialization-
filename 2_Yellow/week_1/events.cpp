#include <iostream>
#include <exception>
using namespace std;
#include <map>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip>

#include <algorithm>
#include <iterator>

// - добавление события:                        Add Дата Событие
// - удаление события:                          Del Дата Событие
// - удаление всех событий за конкретную дату:  Del Дата
// - поиск событий за конкретную дату:          Find Дата
// - печать всех событий за все даты:           Print

class Date {
public:
    Date(int year, int month, int day){
        y = year;
        m = month;
        d = day;
    }
    int GetYear() const{
        return y;
    }
    int GetMonth() const{
        return m;
    }
    int GetDay() const{
        return d;
    }
private:
    int y, m, d;
};

void print_date(const Date& date){
    cout<<setfill ('0')<<setw(4)<<date.GetYear()<<"-"<<
        setfill ('0')<<setw(2)<<date.GetMonth()<<"-"<<
        setfill ('0')<<setw(2)<<date.GetDay()<<" ";
}


bool operator<(const Date &lhs, const Date &rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == rhs.GetMonth()) {
			return lhs.GetDay() < rhs.GetDay();
		}
		return lhs.GetMonth() < rhs.GetMonth();
	}
	return lhs.GetYear() < rhs.GetYear();
}


class Database {
public:
    void AddEvent(const Date& date, const string& event){
        events[date].insert(event);
        //cout<<"ok"<<endl;//
    }
    bool DeleteEvent(const Date& date, const string& event){
        if(events[date].find(event)!= events[date].end()){
            cout<<"Deleted successfully"<<endl;
            events[date].erase(event);
            return true;
        } else{
            cout<<"Event not found"<<endl;
            return false;
        }
    }
    int  DeleteDate(const Date& date){
        int n = events[date].size();
        cout<<"Deleted "<<n<<" events"<<endl;
        events.erase(date);
        return n;
    }

    void Find(const Date& date) {
        for (auto i:events[date]){
            cout<<i<<endl;
        }
    }

    void Print(){
        for (auto set_events:events){
            for (auto deal:set_events.second){
                print_date(set_events.first);
                cout<<deal<<endl;
            }
        }
    }

private:
    map<Date, set<string> > events;
};

Date read_date(const string& command, string& event, bool word){
    string a, command2, command3, command4;
    remove_copy(command.begin(), command.end(), back_inserter(command2), char(226));
    remove_copy(command2.begin(), command2.end(), back_inserter(command3), char(128));
    remove_copy(command3.begin(), command3.end(), back_inserter(command4), char(139));
    istringstream iss(command4);
    iss >> a;

    stringstream w;

    int y, m, d;
    char def1, def2;
    iss >> y ;
    iss>> def1 ;
    iss>> m;
    iss >> def2 ;

    int c = iss.peek();
    if (iss.eof()) {/
      throw exception();
    }

    if (!isdigit(c)) {
    if (c!=43&&c!=45){
      throw exception();}
    }


    iss>> d;
    if (def1!= '-'||def2!= '-'||isalpha(iss.peek())){
      throw exception();
    }
    Date date(y,m,d);
    if (word){
        iss>>event;
    }
    return date;
}

bool is_ok_date(const Date& date){
    if(date.GetMonth()>12 ||date.GetMonth()<1){
        cout<<"Month value is invalid: "<<date.GetMonth()<<endl;
        return false;
    }
    else if(date.GetDay()>31||date.GetDay()<1){
        cout<<"Day value is invalid: "<<date.GetDay()<<endl;
        return false;
    }
    return true;
}

int main() {
    Database db;
    string command;
    string action;
    while (getline(cin, command)) {
        try{
            if (command.length()!=0 ){
                istringstream iss(command);
                iss >> action;
                if (action=="Add")
                {
                    string event;
                    Date date = read_date(command, event, true);
                    if(is_ok_date(date)){
                        db.AddEvent(date, event);
                    }
                }
                else if (action=="Del")
                {
                    string event;
                    Date date = read_date(command, event, true);
                    if(is_ok_date(date)){
                        if(event.empty()){
                            db.DeleteDate(date);
                        }else{
                            db.DeleteEvent(date, event);
                        }
                    }
                }
                else if (action=="Find")
                {
                    string event;
                    Date date = read_date(command, event, false);
                    if(is_ok_date(date)){
                        db.Find(date);
                    }


                }
                else if (action=="Print")
                {
                    db.Print();
                }
                else{
                    cout<<"Unknown command: "<<action;
                }

            }
        }
        catch(exception& ex) {
            istringstream iss(command);
            iss>>action;
            iss>>action;
            cout << "Wrong date format: "<<action<<endl;// << ex.what();
        }
    }

    return 0;
}