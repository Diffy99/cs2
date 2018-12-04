#include <iostream>
#include "graph1.h"
#include "ColorFilledCircle.h"
#include "ColorCircle.h"

ColorCircle::ColorCircle()
{
  cout << "In ColorCircle default Constructor" << endl;
  setR(200);
  setG(200);
  setB(200);

}

ColorCircle::ColorCircle(int x, int y, int radius, int r, int g, int b) : Circle(x,y,radius)
{
  cout << "In ColorCircle Parameterized Constructor" << endl;
  //Set r/g/b
  setR(r);
  setG(g);
  setB(b);
}

ColorCircle::~ColorCircle()
{
  cout << "In Destructor for ColorCircle" << endl;
}

void ColorCircle::setR(int r)
{
  this->r = r;
}

void ColorCircle::setG(int g)
{
  this->g = g;
}

void ColorCircle::setB(int b)
{
  this->b = b;
}

int ColorCircle::getR()
{
  return r;
}

int ColorCircle::getG()
{
  return g;
}

int ColorCircle::getB()
{
  return b;
}

void ColorCircle::draw()
{
  int obj_no = drawCircle(radius,x,y);
  setColor(obj_no,r,g,b);
}

void ColorCircle::print()
{
  Circle::print();
  gout << setPos(x,y+radius+60) << "Color: " << r << ","  
                                << g << "," << b << endg;
}

