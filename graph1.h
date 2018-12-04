/*BMPLoader - loads Microsoft .bmp format
    Copyright (C) 2006  Chris Backhouse

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.


  cjbackhouse@hotmail.com 		www.backhouse.tk
  
  I would appreciate it if anyone using this in something cool would tell me
  so I can see where it ends up.

  Takes a filename, returns an array of RGB pixel data
  Loads:
  24bit bitmaps
  256 colour bitmaps
  16 colour bitmaps
  2 colour bitmaps  (Thanks to Charles Rabier)

  This code is designed for use in openGL programs, so bitmaps not correctly padded will not
  load properly, I believe this only applies to: 
  256cols if width is not a multiple of 4
  16cols if width is not a multiple of 8
  2cols if width is not a multiple of 32

  Sample code:

	BMPClass bmp;
	BMPLoad(fname,bmp);
	glTexImage2D(GL_TEXTURE_2D,0,3,bmp.width,bmp.height,0,GL_RGB,GL_UNSIGNED_BYTE,bmp.bytes);
*/
#include <windows.h>
#include <gl/glut.h>
#include <iostream>
#include <cstring>
#include <string>
#define endg "_endg_"


#ifndef BMPLOADER_H
#define BMPLOADER_H

#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned char BYTE;

class BMPClass
{
public:
	BMPClass();
	~BMPClass();
	BYTE& pixel(int x,int y,int c);
	void allocateMem();
	int width,height;
	BYTE* bytes;			//OpenGL formatted pixels
};

#define BMPError char
#define BMPNOTABITMAP 'b'	//Possible error flags
#define BMPNOOPEN 'o'
#define BMPFILEERROR 'f'
#define BMPBADINT 'i'
#define BMPNOERROR '\0'
#define BMPUNKNOWNFORMAT 'u'

//Loads the bmp in fname, and puts the data in bmp
BMPError BMPLoad(string fname,BMPClass& bmp);

//Translates my error codes into English	
std::string TranslateBMPError(BMPError err);	

//Load and select in OpenGL
BMPError BMPLoadGL(string fname);

struct Precision
{
  int precision;
  bool precisionFlag;
};

struct GraphColor
{
  int r;
  int g;
  int b;
};

class Gout
{
  private:
    int x;
    int y;
    int r;
    int g;
    int b;
    int precision;
    bool precisionFlag;


  public:
    Gout() { r= 0; g=255; b= 0; precisionFlag = false; };
    void setX(int x) { this->x = x;}
    void setY(int y) { this->y = y;}
    int getX() { return x;}
    int getY() { return y;}
    void setR(int r) {this->r = r;}
    void setG(int g) {this->g = g;}
    void setB(int b) {this->b = b;}
    int getR() {return r;}
    int getG() { return g;}
    int getB() {return b;}
    void setPrecisionFlag(bool flag) { precisionFlag = flag;}
    bool getPrecisionFlag() {return precisionFlag;}
    void setPrecision(int precision) {this->precision = precision;}
    int  getPrecision() {return precision;}
    friend Gout& operator<<(Gout& g, int int_val);
    friend Gout& operator<<(Gout& g, double int_val);
    friend Gout& operator<<(Gout& g, char* char_val);
    friend Gout& operator<<(Gout& g, string string_val);
   
};

extern Gout gout;

struct Point
{
  int x;
  int y;
};



struct GraphObject
{
  char* str;
  int id;
  int no_points;
  Point* points;
  double* colors;
  int radius;
  int no_objects;
  BMPClass* bmp;
  int remove;
  int width;
  int height;
  int del;
  BYTE* bytes; //PNG BYTES
};

void reshape(int w, int h);
void display(void);
void init(char* title);
int drawPoint(int x, int y);
int drawCircle(int radius, int x, int y);
void drawMyCircle( int Radius, int numPoints, int x, int y );
int drawLine(int x1, int y1, int x2, int y2, int width);
int drawRect(int x1, int y1, int width, int height);
void displayGraphics();
int displayBMP(char* fn,int x, int y);
int displayBMP(string fn, int x, int y);
int displayPNG(string fn, int x, int y);
int displayPNG(char* fn, int x, int y);
int displayText(char* str, int x, int y, int r, int g, int b);
void clearGraphics();
void setColor(int obj_no, int r, int g, int b);
GraphColor setColor(int r, int g, int b);
void timerColor(int value);
void moveObject(int obj_no, int x, int y);
void processSpecialKeys(int key, int x, int y);
DWORD WINAPI display1(LPVOID lpParam);
void processMouse(int button, int state, int x, int y);
void removeObject(int id);
void clearText();
void GRAPH_SS();
bool up();
bool down();
bool left();
bool right();
bool leftMouse(int&x, int&y);
bool rightMouse(int&x, int&y);
bool middleMouse(int&x, int&y);
Gout& operator<<(Gout& g, int int_val);
Gout& operator<<(Gout& g, double int_val);
Gout& operator<<(Gout& g, char* char_val);
Gout& operator<<(Gout& g, char char_val);
Gout& operator<<(Gout& g, Gout&(*pt2Func)(int x, int y));
Gout& operator<<(Gout& g, Gout&(*pt2Func)(int r, int g, int b));
Gout& operator<<(Gout& g, Point a);
Gout& operator<<(Gout& g, GraphColor gc);
Gout& operator<<(Gout& g, Precision p);
Gout& operator<<(Gout& g, Gout&(*pt2Func)(int precision));
Precision setPrecision(int precision);
Point setPos(int x, int y);
void getPos(int obj_no, Point points[], int& no_points);
bool mouseDragged(int& x, int& y);
void processMouseDragged(int x, int y);
void replaceObject(int orig_obj, int new_obj);

#endif