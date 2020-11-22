# Build definitions for geoex program
#
# Copyright (C) 2010 Georgi D. Sotirov <gdsotirov@gmail.com>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#

CPP=g++
CPP_FLAGS=-Wall -O2 -ggdb
RM=rm

all: geoex

%.o : %.cpp
	$(CPP) $(CPP_FLAGS) -o $@ -c $<

geoex.o: geoex.cpp geo.hpp

geoex: geoex.o
	$(CPP) $(CPP_FLAGS) -o $@ $<

clean:
	$(RM) -f *.o
	$(RM) -f geoex

