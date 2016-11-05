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
	Unoccupied = '.',
	Red = 'R',
	Green = 'G',
	Blue = 'B',
	Yellow = 'Y'
};

class Grid{
public:
	Grid(int sz);
	~Grid();
	
	bool isOccupied(int row, int col);
	bool isNotOut(int row, int col);
	bool isNotSurface(int row, int col, Cell c);
	bool isCorner(int row, int col, Cell c);
	
	bool isOk(int row, int col, Cell c);
	bool firstisOk(int row, int col, Cell c);
	
	Cell getCell(int row, int col);
	Cell& getCellRef(int row, int col);
	char getCellValue(Cell c);
	
	bool putShape(const Shape& sp, int row, int col, Orientation o, Cell c, std::function<bool(int,int,Cell,Grid*)> func, bool cornercheck);
	bool checkShape(const Shape& sp, int row, int col, Orientation o, Cell c, std::function<bool(int,int,Cell,Grid*)> func, bool cornercheck);
	
	void print();
	void win();
	
	Grid(const Grid &) = delete;
	Grid(Grid&&) = delete;
	Grid &operator=(const Grid &) = delete;
//private:
	int size;
	Cell *grid;
	
};

#endif /* grid_h */
