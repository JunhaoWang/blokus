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

bool Grid::isOccupied(int row, int col) {
	std::cout<<"isOccupied "<<row<<" "<<col<<std::endl;
	return getCell(row, col) != Cell::Unoccupied;
}

bool Grid::isNotOut(int row, int col) {
	return row >= 0 && row < size && col >= 0 && col < size;
}

Cell Grid::getCell(int row, int col) {
	assert(row >= 0 && row < size);
	assert(col >= 0 && col < size);
	std::cout<<"getCell "<<row<<" "<<col<<std::endl;
	return grid[row*size+col];
}

Cell& Grid::getCellRef(int row, int col) {
	assert(row >= 0 && row < size);
	assert(col >= 0 && col < size);
	std::cout<<"getCellRef "<<row<<" "<<col<<std::endl;
	return grid[row*size+col];
}

// Todo: put shape into grid (improve to private holder.data later)
bool Grid::putShape(const Shape& sp, int row, int col, Orientation o, Cell c) {
	Shape holder (sp);
	holder = holder.transform(o).move(Coordinate(row, col));
	std::cout<<"putShape Move at "<<row<<" "<<col<<std::endl;
	for (auto i:holder.data){
		std::cout<<"putShape at "<<i.row<<" "<<i.col<<std::endl;
		if (isOccupied(i.row,i.col)){
			std::cout<<"putShape at "<<row<<" "<<col<<std::endl;
			return false;
		}
	}
	for (auto i:holder.data){
		getCellRef(i.row, i.col) = c;
	}
	return true;
}

// Todo: improve print grid
void Grid::print() const{
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			std::cout<<j;
		}
		std::cout<<'\n';
	}
	std::cout<<std::endl;
}


