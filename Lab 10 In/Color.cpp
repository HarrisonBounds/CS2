#include <iostream>
#include <cmath>
#include "Color.h" 
#include "graph1.h" 

Color::Color()
{
  setColor(0,0,0);
}

Color::Color(int r, int g, int b)
{
  setColor(r,g,b);
}



void Color::setColor(int r, int g, int b)
{
  this->r = r;
  this->g = g;
  this->b = b;
}

int Color::getRed()
{
  return(r);
}

int Color::getGreen()
{
  return(g);
}

int Color::getBlue()
{
  return(b);
}

Color Color::operator+(Color right)
{
  Color ret_val;
  ret_val.r = (r + right.r)%256;
  ret_val.g = (g + right.g)%256;
  ret_val.b = (b + right.b)%256;

  return(ret_val);
  
}

Color Color::operator-(Color right)
{
  Color ret_val;
  ret_val.r = abs(r - right.r);
  ret_val.g = abs(g - right.g);
  ret_val.b = abs(b - right.b);

  return(ret_val);
}

Color Color::operator/(int right)
{
  Color ret_val;
  ret_val.r = r/right;
  ret_val.g = g/right;
  ret_val.b = b/right;

  return(ret_val);
}

Color Color::operator*(int right)
{
  Color ret_val;
  ret_val.r = (r*right)%256;
  ret_val.g = (g*right)%256;
  ret_val.b = (b*right)%256;

  return(ret_val);
}

bool Color::operator==(Color right)
{
  if ( (r == right.r) && (b == right.b) && (g == right.g) )
    return(true);
  else
    return(false);
}

bool Color::operator!=(Color right)
{
  if ( (r == right.r) && (b == right.b) && (g == right.g) )
    return(false);
  else
    return(true);
}

void Color::operator=(Color right)
{
  r = right.r;
  b = right.b;
  g = right.g;
  
}

Color Color::operator!()
{
  Color ret_val;
  ret_val.r = 255 - r;
  ret_val.g = 255 - g;
  ret_val.b = 255 - b;

  return(ret_val);
  
}

void Color::draw(int x, int y, int w, int h)
{
  int obj_no = drawRect(x,y,w,h);
  ::setColor(obj_no,r,g,b);
  
}

Color Color::operator++()
{
  r += 25;
  g += 25;
  b += 25;

  if (r > 255)
    r = 255;

  if (g > 255)
    g = 255;

  if (b > 255)
    b = 255;

  return(*this);
}

Color Color::operator++(int dummy)
{
  Color orig = *this;

  r += 25;
  g += 25;
  b += 25;

 if (r > 255)
    r = 255;

  if (g > 255)
    g = 255;

  if (b > 255)
    b = 255;

  return(orig);
}

Color Color::operator--()
{
  r -= 25;
  g -= 25;
  b -= 25;

  if (r < 0)
    r = 0;

  if (g < 0)
    g = 0;

  if (b < 0)
    b = 0;

  return(*this);
}

Color Color::operator--(int dummy)
{
  Color orig = *this;

  r -= 25;
  g -= 25;
  b -= 25;

  if (r < 0)
    r = 0;

  if (g < 0)
    g = 0;

  if (b < 0)
    b = 0;

  return(orig);
}

bool Color::operator<(Color right)
{
  //Compute the magnitude of the right
  double magr = sqrt( (double)((right.r*right.r) + (right.g*right.g) + (right.b*right.b)));
  double magl = sqrt( (double)((r*r) + (g*g) + (b*b)));

  if (magl < magr)
    return(true);
  else
    return(false);
}

bool Color::operator>(Color right)
{
  double magr = sqrt( (double)((right.r*right.r) + (right.g*right.g) + (right.b*right.b)));
  double magl = sqrt( (double)((r*r) + (g*g) + (b*b)));

  if (magl < magr)
    return(false);
  else
    return(true);
}

