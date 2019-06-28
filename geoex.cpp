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
 * $Id: geoex.cpp,v 1.1 2010/06/02 10:33:09 gsotirov Exp $
 */

/**
 * @file geoex.cpp
 * Test module for the class hierarchy from Geo namespace
 */

#include <iostream>

#include "geo.hpp"

using std::cout;
using std::endl;

/**
 * Main test program
 */
int main(int argc, char * argv[]) {
  Geo::Point2D p2d0(0, 0);
  Geo::Point3D p3d0(0, 0, 0);
  Geo::Circle * pCircle = new Geo::Circle(&p2d0, 3.5);
  Geo::Square * pSquare = new Geo::Square(&p2d0, 3);
  Geo::Sphere * pSphere = new Geo::Sphere(&p3d0, 3.5);
  Geo::Cube   * pCube   = new Geo::Cube(&p3d0, 3);

  cout << "A circle with radius " << pCircle->getRadius() << endl;
  cout << " Circle's area is " << pCircle->area() << endl;
  cout << " Circle's circumference is " << pCircle->perimeter() << endl;

  cout << "A square with side " << pSquare->getSide() << endl;
  cout << " Square's area is " << pSquare->area() << endl;
  cout << " Square's perimeter is " << pSquare->perimeter() << endl;

  cout << "A sphere with radius " << pSphere->getRadius() << endl;
  cout << " Sphere's surface area is " << pSphere->area() << endl;
  cout << " Sphere's circumference is " << pSphere->perimeter() << endl;
  cout << " Sphere's volume is " << pSphere->volume() << endl;

  cout << "A cube with edge " << pCube->getEdge() << endl;
  cout << " Cube's surface area is " << pCube->area() << endl;
  cout << " Cube's perimeter is " << pCube->perimeter() << endl;
  cout << " Cube's volume is " << pCube->volume() << endl;

  delete pCube;
  delete pSphere;
  delete pSquare;
  delete pCircle;
}

