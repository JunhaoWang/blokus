//
//  grid.h
//  blokus
//
//  Created by Junhao Wang on 10/27/16.
//  Copyright © 2016 Junhao Wang. All rights reserved.
//

#ifndef grid_h
#define grid_h
#include "shape.h"

enum class Cell {
	Unoccupied,
	Red,
	Green,
	Blue,
	Yellow
};


class Grid{
public:
	Grid(int sz);
	~Grid();
	
	bool isOccupied(int row, int col) const;
	Cell getCell(int row, int col) const;
	
	bool putShape(const Shape& sp, int row, int col, Orientation o);
	
	Grid(const Grid &) = delete;
	Grid(Grid&&) = delete;
	Grid &operator=(const Grid &) = delete;
private:
	int size;
	Cell *grid;
	
};

#endif /* grid_h */
