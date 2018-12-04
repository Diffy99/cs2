#ifndef COLORCIRCLE_H
#define COLORCIRCLE_H

#include "Circle.h"

class ColorCircle : public Circle
{
  protected:
    int r;
    int g;  
    int b;

  public:
    ColorCircle(int x, int y, int radius, int r, int g, int b);
    ColorCircle();
    ~ColorCircle();
    void setR(int r);
    void setG(int g);
    void setB(int b);
    int getR();
    int getG();
    int getB();
    void draw();
    void print();

};

#endif