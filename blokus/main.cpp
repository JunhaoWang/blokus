//
//  main.cpp
//  blokus
//
//  Created by Junhao Wang on 10/27/16.
//  Copyright © 2016 Junhao Wang. All rights reserved.
//

#include <iostream>
#include <type_traits>
#include <stdlib.h>

#include "grid.h"
#include "shape.h"

using namespace std;

// 21 shapes

static const Shape one_cell{Coordinate(0, 0)};
static const Shape two_cell{Coordinate(0, 0),Coordinate(0, 1)};
static const Shape three_cell{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2)};
static const Shape four_cell{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(0, 3)};
static const Shape five_cell{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(0, 3),Coordinate(0, 4)};
static const Shape cross{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(-1, 1),Coordinate(1, 1)};
static const Shape crossstrange{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(-1, 1),Coordinate(1, 2)};
static const Shape boomerangsmall{Coordinate(0, 0),Coordinate(0, 1),Coordinate(1,1)};
static const Shape square{Coordinate(0, 0),Coordinate(0, 1),Coordinate(1, 0),Coordinate(1, 1)};
static const Shape squaredot{Coordinate(0, 0),Coordinate(0, 1),Coordinate(1, 1),Coordinate(1, 2),Coordinate(0, 2)};
static const Shape tshape{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(1, 1),Coordinate(2, 1)};
static const Shape boomerangbig{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(1, 2),Coordinate(2, 2)};
static const Shape mshape{Coordinate(0, 0),Coordinate(0, 1),Coordinate(1, 1),Coordinate(1, 2),Coordinate(2, 2)};
static const Shape ushape{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(1, 2),Coordinate(1, 0)};
static const Shape boomerangbigkill{Coordinate(0, 0),Coordinate(0, 1),Coordinate(1, 1),Coordinate(2, 1),Coordinate(2, 2)};
static const Shape boomerangsmallkill{Coordinate(0, 0),Coordinate(0, 1),Coordinate(1, 1),Coordinate(1, 2)};
static const Shape boomeranghalf{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(1, 2),Coordinate(1, 3)};
static const Shape lshapesmall{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(1, 2)};
static const Shape lshapebig{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(0, 3),Coordinate(1, 3)};
static const Shape lshapebigmiddle{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(0, 3),Coordinate(1, 2)};
static const Shape lshapesmallmiddle{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(1, 1)};


int main(int argc, const char * argv[]) {
	
	Grid grid(10);
	for (int i = 0; i < 1000000; ++i){
		grid.putShape(lshapesmallmiddle, 5, 5, Orientation::RightNeg, Cell::Blue);
	}
	grid.print();
    return 0;
}
