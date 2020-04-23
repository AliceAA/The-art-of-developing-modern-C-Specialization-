#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class Person{
public:
  Person(string name):Name(name){}

  virtual string Role() const {
      return "Person";
  }

  virtual string Brief() const {
      return  Role() +": " + Name;
  }

  virtual void Walk(const string destination) const{
    cout << Brief() << " walks to: " << destination << endl;
  }
  const string Name;
};


class Student : public Person{
public:

    Student(string name, string favouriteSong) :Person{name}, Name(name), FavouriteSong (favouriteSong){}
    
    string Role() const {
        return "Student";
    }
    void Learn() const{
        cout << Brief() << " learns" << endl;
    }

    void Walk(const string destination) const {
        
        Person::Walk(destination);
        cout << Brief() << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() const {
        cout << Brief()<< " sings a song: " << FavouriteSong << endl;
    }

public:
    const string Name;
    const string FavouriteSong;
};


class Teacher : public Person{
public:

    Teacher(string name, string subject) :Person{name}, Name(name), Subject (subject){}

    string Role() const {
        return "Teacher";
    }

    void Teach()const  {
        cout << Brief() << " teaches: " << Subject << endl;
    }

    void Walk(const string destination)const  {
        Person::Walk(destination);
    }

public:
    const string Name;
    const string Subject;
};


class Policeman : public Person{
public:
    Policeman(string name) :Person{name}, Name(name){}

    string Role() const {
        return "Policeman";
    }

    void Check(const Person& t) const {
      string person_type = typeid(t).name();
      person_type.replace(0,1,"");
      cout << Brief()<< " checks "<<person_type<<". "<<person_type<<"'s name is: " << t.Name << endl;
    }

    void Walk(const string destination)const  {
        Person::Walk(destination);
    }

public:
    const string Name;
    const string role = "Policeman";
};


void VisitPlaces(const Person& t, const vector<string> places) {
    for (auto p : places) {
        t.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}

