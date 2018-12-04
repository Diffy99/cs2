#include <iostream>
#include "Circle.h"
#include "graph1.h"

const double Circle::PI = 3.14159628;

Circle::Circle()
{
  cout << "In Circle default Constructor" << endl;
  //Set default values - x=100, y=100, radius=10
  setX(100);
  setY(100);
  setRadius(10);
  
}

Circle::Circle(int x, int y, int radius)
{
  cout << "In Circle Parameterized Constructor" << endl;
  setX(x);
  setY(y);
  setRadius(radius);
  
}

Circle::~Circle()
{
  cout << "In Destructor for Circle" << endl;
}

int Circle::getX() 
{
  return x;
}

int Circle::getY()
{
  return y;
}

void Circle::setX(int x)
{
  this->x = x;
}

void Circle::setY(int y)
{
  this->y = y;
}

int Circle::getRadius()
{
  return radius;
}

void Circle::setRadius(int radius)
{
  this->radius = radius;
}

double Circle::getArea()
{
  return(radius*radius*PI);
}

double Circle::getPerimeter()
{
  return(2*radius*PI);
}

void Circle::draw()
{
  //Draw the basic circle
  drawCircle(radius,x,y);
}

void Circle::print()
{
  //Print info beneath the circle
  gout << setPos(x,y+radius+15) << "center: (" << x << "," << y << ")" << endg;
  gout << setPos(x,y+radius+30) << "Area: " << getArea() << endg;
  gout << setPos(x,y+radius+45) << "Perimeter: " << getPerimeter() << endg;
}