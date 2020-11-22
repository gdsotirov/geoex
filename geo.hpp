/* Copyright (C) 2010-2019 Georgi D. Sotirov <gdsotirov@gmail.com>
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
 */

/**
 * @file geo.hpp
 * The modules defines a simple class hierarchy of 2D and 3D shapes.
 * It's created as an example for Stefan Kanev in a comment on his
 * publication Structures vs Objects [http://skanev.com/2010/05/30/structs-vs-objects/].
 * The purpose is to illustrate adding and removing of operations in class
 * hierarchies used in Object Oriented Programming.
 */

#include <cmath>

namespace Geo {

/** @brief Two dimensional space point */
class Point2D {
private:
  double x;
  double y;

public:
  /**
   * @brief Construct 2D point from X and Y coordinates
   * @param px X coordinate value
   * @param py Y coordinate value
   */
  Point2D(double px, double py) : x(px), y(py) {}

  /** @brief Retrieves point's X coordinate value */
  virtual double getX() { return x; }
  /** @brief Retrieves point's Y coordinate value */
  virtual double getY() { return y; }

  /** @brief Destructor. Does nothing */
  virtual ~Point2D() {}
};

/** @brief Three dimensional space point */
class Point3D: public Point2D {
private:
  double z;

public:
  /**
   * @brief Construct 3D point from X, Y and Z coordinates
   * @param px X coordinate value
   * @param py Y coordinate value
   * @param pz Z coordinate value
   */
  Point3D(double px, double py, double pz) : Point2D(px, py), z(pz) {}

  /** @brief Retrieves point's Z coordinate value */
  double getZ() { return z; }
};

/** @brief Generic shape */
class Shape {
public:
  /** @brief Prototype for calculation of shape's area */
  virtual double area(void) = 0;
  /** @brief Prototype for calculation of shape's perimeter */
  virtual double perimeter(void) = 0;
  /** @brief Destructor. Does nothing */
  virtual ~Shape() {}
};

/** @brief Generic two dimensional shape */
class Shape2D: public Shape {
private:
  Point2D ref_point;

public:
  /**
   * @brief Construct 2D shape from 2D reference point
   * @param p 2D point
   */
  explicit Shape2D(Point2D * p) : ref_point(*p) {}
  /**
   * @brief Construct 2D shape from coordinates
   * @param px X coordinate value
   * @param py Y coordinate value
   */
  Shape2D(double px, double py) : ref_point(px, py) {}
};

/** @brief Generic three dimensional shape */
class Shape3D: public Shape {
private:
  Point3D ref_point;

public:
  /**
   * @brief Construct 3D shape from 3D point
   * @param p 3D point
   */
  explicit Shape3D(Point3D * p) : ref_point(* p) {}

  /**
   * @brief Shape's perimeter
   *
   * Perimeter is a path that encompasses/surrounds a two-dimensional shape,
   * so it's rather not useful for 3D shapes.
   * @return Always zero.
   */
  double perimeter(void) { return 0; };
  /**
   * @brief Prototype for calculation of shape's volume
   */
  virtual double volume(void) = 0;
};

/** @brief Circle shape */
class Circle: public Shape2D {
private:
  double radius;

public:
  /**
   * @brief Construct circle shape from 2D point and radius
   * @param p 2D point
   * @param r Radius
   */
  Circle(Point2D * p, double r) : Shape2D(p), radius(r) {}
  /**
   * @brief Construct circle from coordinates and radius
   * @param px X coordinate value
   * @param py Y coordinate value
   * @param r Radius
   */
  Circle(double px, double py, double r) : Shape2D(px, py), radius(r) {}

  /**
   * @brief Retrieves circle's radius
   * @return Circle's radius
   */
  double getRadius(void) { return radius; }

  /**
   * @brief Calculates circle's area
   *
   * The area enclosed by a circle of radius <em>r</em> is \f$πr^2\f$
   * @return Circle's area
   */
  double area(void) { return M_PI * radius * radius; }
  /**
   * @brief Calculates circle's perimeter
   *
   * Circle's perimeter or circumference is the (linear) distance around it.
   * It's calculated as \f$2πr\f$
   * @return Circle's perimeter
   */
  double perimeter(void) { return 2 * M_PI * radius; }
};

/** @brief Rectangle shape */
class Rectangle: public Shape2D {
private:
  double width;
  double height;
public:
  /**
   * @brief Construct rectangle shape from 2D point, width and height
   * @param p 2D point
   * @param w Width
   * @param h Height
   */
  Rectangle(Point2D * p, double w, double h) : Shape2D(p), width(w), height(h) {}
  /**
   * @brief Construct rectangle from coordinates, width and height
   * @param px X coordinate value
   * @param py Y coordinate value
   * @param w Width
   * @param h Height
   */
  Rectangle(double px, double py, double w, double h) : Shape2D(px, py), width(w), height(h) {}

  /**
   * Retrieves rectangle's width
   * @return Rectangle's width
   */
  double getWidth(void) { return width; }
  /**
   * Retrieves rectangle's height
   * @return Rectangle's height
   */
  double getHeight(void) { return height; }

  /**
   * @brief Calculates rectangle's area
   *
   * Rectangle's area is calculate by multiplying width by height.
   * @return Rectangle's area
   */
  double area(void) { return width * height; }
  /**
   * @brief Calculates rectangle's perimeter
   * @return Rectangle's perimeter
   */
  double perimeter(void) { return 2 * width + 2 * height; }
};

/** @brief Square shape */
class Square: public Shape2D {
private:
  double side;

public:
  /**
   * @brief Constructs square shape from 2D point and side
   * @param p 2D point
   * @param s Side value
   */
  Square(Point2D * p, double s) : Shape2D(p), side(s) {}
  /**
   * @brief Constructs square shape from coordinates and side
   * @param x X coordinate value
   * @param y Y coordinate value
   * @param s Side value
   */
  Square(double x, double y, double s) : Shape2D(x, y), side(s) {}

  /**
   * @brief Retrieves side value
   * @return Side value
   */
  double getSide(void) { return side; }

  /**
   * @brief Calculates square's area
   * @return Square's area
   */
  double area(void) { return side * side; }
  /**
   * @brief Calculates square's perimeter
   * @return Square's perimeter
   */
  double perimeter(void) { return side * 4; }
};

/** @brief Sphere object */
class Sphere: public Shape3D {
private:
  Circle cr;
public:
  /**
   * @brief Constructs sphere shape from 3D point and radius for circle
   * @param cntr Sphere's central point
   * @param r Radius
   */
  Sphere(Point3D * cntr, double r) : Shape3D(cntr), cr(cntr->getX(), cntr->getY(), r) {}

  /**
   * @brief Retrieves sphere's radius
   * @return Sphere's radius
   */
  double getRadius(void) { return cr.getRadius(); }

  /**
   * @brief Calculates sphere's surface area
   *
   * Sphere's surface area is calculated by the formula \f$4πr^2\f$
   * @return Sphere's area
   */
  double area(void) { return 4 * M_PI * cr.getRadius() * cr.getRadius(); }
  /**
   * @brief Calculates sphere's perimeter
   *
   * Sphere's perimeter is the circumference of the aggregated circle
   * @return Sphere's perimeter
   */
  double perimeter(void) { return cr.perimeter(); }
  /**
   * @brief Calculates sphere's enclosed volume
   *
   * Sphere's enclosed volume is calculated by the formula \f$\frac{4}{3}πr^3\f$
   * @return Sphere's volume
   */
  double volume(void) { return 4.0/3.0 * M_PI * cr.getRadius() * cr.getRadius() * cr.getRadius(); }
};

/** @brief Cube shape
 *
 * This class does not provide method for calculation of perimeter, because
 * such an operation is ambiguous. Perimeter by sides or by sides and shape
 * diagonals?
 */
class Cube: public Shape3D {
private:
  Square sq;
public:
  /**
   * @brief Constructs cube shape from 3D point and side for square
   * @param p 3D point
   * @param s Side value
   */
  Cube(Point3D * p, double s) : Shape3D(p), sq(p->getX(), p->getY(), s) {}

  /**
   * @brief Retrieves cube's edge value from the side of the aggregated square
   * @return Cube's edge
   */
  double getEdge(void) { return sq.getSide(); }

  /**
   * @brief Calculates cube's surface area
   *
   * The surface area of a cube is the area of the six squares that cover it,
   * so it's calculated by the formula \f$6a^2\f$
   * @return Cube's area
   */
  double area(void) { return sq.area() * 6; }

  /**
   * @brief Calculates cube's volume
   *
   * The volume of a cube is the third power of its sides, so it's calculated
   * by the formula \f$a^3\f$
   * @return Cube's volume
   */
  double volume(void) { return sq.getSide() * sq.getSide() * sq.getSide(); }
};

}

