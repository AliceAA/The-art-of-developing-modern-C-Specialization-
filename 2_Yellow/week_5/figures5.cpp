#include<algorithm>
#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
#include <map>
#include <string>
#include<istream>
#include<vector>
#include<memory>
#include <iomanip>
#include <sstream>   

using namespace std;

class Figure{
public:  
  virtual string Name() = 0; 
  virtual double Perimeter() = 0 ;
  virtual double Area() = 0;
};

class Triangle : public Figure{
public:
  Triangle(double a1, double b1, double c1){
    a = a1;
    b = b1;
    c = c1;
  }
  string Name() override{
    return "TRIANGLE";
  };
  double Perimeter() override{
    return a+b+c;
  };
  double Area () override{
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
  };
private:
  double a, b, c;
};


class Rect : public Figure{
public:
  Rect(double width1, double height1){
    width = width1;
    height = height1;
  }
  string Name() override{
    return "RECT";
  };
  double Perimeter() override{
    return 2*(width+height);
  };
  double Area () override{
    return width*height;
  };
private:
  double width, height ;
} ;



class Circle : public Figure{
public:
  Circle(double r1){
    r = r1;
  }
  string Name() override{
    return "CIRCLE";
  };
  double Perimeter() override{
      return 2*3.14*r;
  };
  double Area () override{
    return 3.14*r*r;
  };
private:
  double r;
};

shared_ptr<Figure> CreateFigure(istringstream &is){
	string fig;
	is >> fig;
	if (fig == "RECT"){
		double w, h;
		is >> w >> h;
		return make_shared<Rect>(w, h);
	} else if (fig == "TRIANGLE") {
		double a, b, c;
		is >> a >> b >> c;
		return make_shared<Triangle>(a, b, c);
	} else if (fig == "CIRCLE") {
		double r;
		is >> r;
		return make_shared<Circle>(r);
	} else {
		//throw exception
		return make_shared<Rect>(1.0, 1.0);
	}
}
/*
int main() {
  //Figure f;
  vector < shared_ptr <Figure> > figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
*/