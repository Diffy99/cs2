#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
  protected:
    int x;
    int y;
    int radius;
    const static double PI;

  public:
    Circle();
    Circle(int x, int y, int radius);
    ~Circle();
    int getX(); 
    int getY();
    int getRadius();
    void setX(int x);
    void setY(int y);
    void setRadius(int radius);
    double getArea();
    double getPerimeter();
    void draw();
    void print();
};

#endif
