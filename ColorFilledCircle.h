#ifndef COLORFILLEDCIRCLE_H
#define COLORFILLEDCIRCLE_H

#include "ColorCircle.h"

class ColorFilledCircle : public ColorCircle
{
  public:
    ColorFilledCircle();
    ColorFilledCircle(int x, int y, int radius, int r, int g, int b);
    ~ColorFilledCircle();
    void draw();
    void print();
};

#endif