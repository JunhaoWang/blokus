//
//  main.cpp
//  blokus
//
//  Created by Junhao Wang on 10/27/16.
//  Copyright © 2016 Junhao Wang. All rights reserved.
//

#include <iostream>
#include "grid.h"
#include "shape.h"



static const Shape one_cell{Coordinate(0, 0)};
static const Shape two_cell{Coordinate(0, 0),Coordinate(0, 1)};
static const Shape three_cell{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2)};
static const Shape four_cell{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(0, 3)};
static const Shape five_cell{Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(0, 3),Coordinate(0, 4)};


// TODO: make 21 shapes above


int main(int argc, const char * argv[]) {
	
	const Grid grid(8);
	grid.isOccupied(2,2);
	one_cell.move(Coordinate(1, 1));
    return 0;
}
