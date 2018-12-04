#include <iostream>
#include "graph1.h"
#include "ColorFilledCircle.h"

ColorFilledCircle::ColorFilledCircle() 
{
  cout << "In ColorFilledCircle Default Constructor" << endl;
}

ColorFilledCircle::ColorFilledCircle(int x, int y, int radius, int r, int g, int b) : ColorCircle(x,y,radius,r,g,b)
{
  cout << "In ColorFilledCircle Parameterized Constructor" << endl;
}

ColorFilledCircle::~ColorFilledCircle()
{
  cout << "In Destructor for ColorFilledCircle" << endl;
}

void ColorFilledCircle::draw()
{
  int i = 0;
  int obj_no = 0;

  for (i = 0; i < radius; i++)
  {
    obj_no = drawCircle(i,x,y);
    setColor(obj_no,r,g,b);
  }
}

void ColorFilledCircle::print()
{
  ColorCircle::print();
  gout << setPos(x-radius,y) << "Filled  Circle" << endg;
}
