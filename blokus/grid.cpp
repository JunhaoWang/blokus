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
#include <iostream>
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

bool Grid::isOccupied(int row, int col) {
	return getCell(row, col) != Cell::Unoccupied;
}

bool Grid::isNotOut(int row, int col) {
	return row >= 0 && row < size && col >= 0 && col < size;
}

bool Grid::isOk(int row, int col) {
	return isNotOut(row, col) && !isOccupied(row, col);
}

Cell Grid::getCell(int row, int col) {
	assert(row >= 0 && row < size);
	assert(col >= 0 && col < size);
	return grid[row*size+col];
}

Cell& Grid::getCellRef(int row, int col) {
	assert(row >= 0 && row < size);
	assert(col >= 0 && col < size);
	return grid[row*size+col];
}

// Todo: put shape into grid (improve to private holder.data later)
bool Grid::putShape(const Shape& sp, int row, int col, Orientation o, Cell c) {
	Shape holder (sp);
	holder = holder.transform(o).move(Coordinate(row, col));
	for (auto i:holder.data){
		if (!isOk(i.row,i.col)){
			return false;
		}		
	}
	for (auto i:holder.data){
		getCellRef(i.row, i.col) = c;
	}
	return true;
}

char Grid::getCellValue(Cell c){
	switch (c) {
		case Cell::Unoccupied:
			return '.';
		case Cell::Red:
			return 'R';
		case Cell::Green:
			return 'G';
		case Cell::Blue:
			return 'B';
		case Cell::Yellow:
			return 'Y';
		default:
			abort();
	}
}

// Todo: improve print grid
void Grid::print(){
	
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			std::cout << getCellValue(getCell(i, j));
		}
		std::cout<<'\n';
	}
	std::cout<<std::endl;
}


