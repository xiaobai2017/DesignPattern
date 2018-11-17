#ifndef FLYWEIGHT_HPP_
#define FLYWEIGHT_HPP_

#include<iostream>
#include<map>
#include<string>
using namespace std;

class Shape {
 public:
  virtual ~Shape() {}
  virtual void Draw() = 0;
};

class Circle : public Shape {
 public:
  Circle(string color);
  void Draw() override;
  void SetInfo(int x, int y, int radius);

 private:
  string color_;
  int x_;
  int y_;
  int radius_;
};

Circle::Circle(string color) {
  color_ = color;
  x_ = 0;
  y_ = 0;
  radius_ = 1;
}

void Circle::SetInfo(int x, int y, int radius) {
  x_ = x;
  y_ = y;
  radius_ = radius;
}

void Circle::Draw() {
  cout << "color: " << color_ << ", coordinate of circle center: ("
       << x_ << "," << y_ << "), radius: " << radius_ << endl;
}

class ShapeFactory {
 public:
  static Circle* GetCircle(string color);

 private:
  ShapeFactory(){}
 private:
  static map<string, Circle*> circle_pool_;
};

map<string, Circle*> ShapeFactory::circle_pool_;

Circle* ShapeFactory::GetCircle(string color) {
  Circle* circle;
  auto itorator = circle_pool_.find(color);
  if (circle_pool_.end() == itorator) {
    circle = new Circle(color);
    circle_pool_.insert(pair<string, Circle*>(color, circle));
  } else {
    circle = itorator->second;
  }
  return circle;
}
/*
#include"tmp.hpp"
#include<iostream>
using namespace std;

int main(int argc, char* argv[]) {
  Circle* circle = ShapeFactory::GetCircle(string("red"));
  circle->SetInfo(2, 2, 1);
  circle->Draw();

  circle = ShapeFactory::GetCircle(string("green"));
  circle->SetInfo(3, 3, 1);
  circle->Draw();

  circle = ShapeFactory::GetCircle(string("red"));
  circle->SetInfo(3, 3, 1);
  circle->Draw();
  return 0;
}
*/

#endif //FLYWEIGHT_HPP_








