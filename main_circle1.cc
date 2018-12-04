#include <iostream>
#include "graph1.h"
#include "Circle.h"
#include "ColorCircle.h"
#include "ColorFilledCircle.h"

using namespace std;

int main()
{
  //Variable Declaration/Initialization
  ColorFilledCircle c; //What happens here?
  Circle c1(100,100,10); //Which Constructor runs?
  ColorCircle c2(300,100,10,255,0,0); //Which Constructors runs?
  ColorFilledCircle c3(100,300,10,0,255,0); //Which Constructors runs?
  ColorFilledCircle* cfc_ptr;

  //Create object dynamically
  cfc_ptr = new ColorFilledCircle();

  //Delete ptr
  delete cfc_ptr;

  return 0;
}