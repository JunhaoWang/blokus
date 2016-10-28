//
//  grid.cpp
//  blokus
//
//  Created by Junhao Wang on 10/27/16.
//  Copyright © 2016 Junhao Wang. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <cassert>
#include "grid.h"
#include "shape.h"

Grid::Grid(int sz): size(sz){
	grid = new Cell [size*size];
	for (int i = 0; i < size*size; ++i){
		grid[i] = Cell::Unoccupied;
	}
}

Grid::~Grid(){
	delete[] grid;
	grid = nullptr;
}

bool Grid::isOccupied(int row, int col) const {
	return getCell(row, col) != Cell::Unoccupied;
}

Cell Grid::getCell(int row, int col) const {
	assert(row >= 0 && row < size);
	assert(col >= 0 && col < size);
	return grid[row*size+col];
}

bool putShape(const Shape& sp, int row, int col, Orientation o) {
	
	return true;
}


