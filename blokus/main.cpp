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


// TODO: make 21 shapes above here

int main(int argc, const char * argv[]) {
	
	const Grid grid(8);
	grid.isOccupied(2,2);
    return 0;
}
