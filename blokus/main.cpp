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

// TODO: make 21 shapes above

static const Shape one_cell{Coordinate(0, 0)};
static const Shape two_cell{Coordinate(0, 0),Coordinate(0, 1)};
static const Shape three_cell{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2)};
static const Shape four_cell{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(0, 3)};
static const Shape five_cell{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(0, 3),Coordinate(0, 4)};


int main(int argc, const char * argv[]) {
	
	Grid grid(10);
	grid.putShape(three_cell, 0, 0, Orientation::LeftNeg, Cell::Red);
	grid.print();
    return 0;
}
