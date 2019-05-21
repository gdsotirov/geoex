/**
 * @file The modules defines a simple class hierarchy of 2D and 3D shapes.
 * It's created as an example for Stefan Kanev in a comment on his
 * publication Structures vs Objects [http://skanev.com/2010/05/30/structs-vs-objects/].
 * The purpose is to illustrate adding and removing of operations in class
 * hierarchies used in Object Oriented Programming.
 */

/* Copyright (C) 2010-2019 Georgi D. Sotirov <gdsotirov@dir.bg>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 *
 * $Id: geo.hpp,v 1.2 2010/06/03 12:13:06 gsotirov Exp $
 */

#include <cmath>

namespace Geo {

/* Two dimensional space point */
class Point2D {
private:
  double x;
  double y;

public:
  Point2D(double px, double py) : x(px), y(py) {}

  virtual double getX() { return x; }
  virtual double getY() { return y; }

  virtual ~Point2D() {}
};

/* Three dimensional space point */
class Point3D: public Point2D {
private:
  double z;

public:
  Point3D(double px, double py, double pz) : Point2D(px, py), z(pz) {}

  double getZ() { return z; }
};

/* General shape */
class Shape {
public:
  virtual double area(void) = 0;
  virtual double perimeter(void) = 0;
  virtual ~Shape() {}
};

/* Two dimensional shape */
class Shape2D: public Shape {
private:
  Point2D ref_point;

public:
  explicit Shape2D(Point2D * p) : ref_point(*p) {}
  Shape2D(double px, double py) : ref_point(px, py) {}
};

/* Three dimensional shpe */
class Shape3D: public Shape {
private:
  Point3D ref_point;

public:
  explicit Shape3D(Point3D * p) : ref_point(* p) {}

  /* remove - not always useful for 3D */
  double perimeter(void) { return 0; };
  /* new operation for 3D */
  virtual double volume(void) = 0;
};

/* A circle */
class Circle: public Shape2D {
private:
  double radius;

public:
  Circle(Point2D * p, double r) : Shape2D(p), radius(r) {}
  Circle(double px, double py, double r) : Shape2D(px, py), radius(r) {}

  double getRadius(void) { return radius; }

  double area(void) { return M_PI * radius * radius; }
  double perimeter(void) { return 2 * M_PI * radius; }
};

/* A rectangle */
class Rectangle: public Shape2D {
private:
  double width;
  double height;
public:
  Rectangle(Point2D * p, double w, double h) : Shape2D(p), width(w), height(h) {}
  Rectangle(double px, double py, double w, double h) : Shape2D(px, py), width(w), height(h) {}

  double getWidth(void) { return width; }
  double getHeight(void) { return height; }

  double area(void) { return width * height; }
  double perimeter(void) { return 2 * width + 2 * height; }
};

/* A square */
class Square: public Shape2D {
private:
  double side;

public:
  Square(Point2D * p, double s) : Shape2D(p), side(s) {}
  Square(double x, double y, double s) : Shape2D(x, y), side(s) {}

  double getSide(void) { return side; }

  double area(void) { return side * side; }
  double perimeter(void) { return side * 4; }
};

/* A sphere */
class Sphere: public Shape3D {
private:
  Circle cr;
public:
  Sphere(Point3D * cntr, double r) : Shape3D(cntr), cr(cntr->getX(), cntr->getY(), r) {}

  double getRadius(void) { return cr.getRadius(); }

  double area(void) { return 4 * M_PI * cr.getRadius() * cr.getRadius(); }
  double perimeter(void) { return cr.perimeter(); }
  double volume(void) { return 4.0/3.0 * M_PI * cr.getRadius() * cr.getRadius() * cr.getRadius(); }
};

/* A cube */
class Cube: public Shape3D {
private:
  Square sq;
public:
  Cube(Point3D * p, double s) : Shape3D(p), sq(p->getX(), p->getY(), s) {}

  double getEdge(void) { return sq.getSide(); }

  double area(void) { return sq.area() * 6; }
  /* Perimeter by sides or by sides and shape diagonals? */
  double volume(void) { return sq.getSide() * sq.getSide() * sq.getSide(); }
};

}

