#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
public:
  friend std::istream& operator>>(std::istream& is, Point& p);
  friend std::ostream& operator<<(std::ostream& os, Point& p);
  Point();
  Point(std::istream &is);
  Point(double x, double y);
  double dist(const Point& other);
  friend bool operator == (Point& p1, Point& p2);
  friend class Rhombus;

private:
  double x;
  double y;
};

#endif // POINT_H