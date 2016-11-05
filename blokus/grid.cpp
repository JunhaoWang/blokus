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
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
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


void Grid::win(){
	std::map<std::string, int> counter;
	for (int i = 0; i < size*size; ++i){
		if (grid[i] == Cell::Blue){
			counter["blue"]++;
		}
		else if (grid[i] == Cell::Red){
			counter["red"]++;
		}
		else if (grid[i] == Cell::Yellow){
			counter["yellow"]++;
		}
		else if (grid[i] == Cell::Green){
			counter["green"]++;
		}
	}
	int maxnum = 0;
	std::string winner;
	for (auto it = counter.begin(); it != counter.end(); ++it){
		if (maxnum < it->second){
			maxnum = it->second;
			winner = it->first;
		}
		std::cout<<it->first<<" has "<<it->second<<'\n';
	}
	
	std::cout<<'\n';
	
	if (counter["blue"]==counter["red"] && counter["green"]==counter["yellow"] && counter["green"]==counter["red"]){
		std::cout<<"tie"<<'\n'<<std::endl;
		std::cout<<"==============================="<<'\n'<<'\n'<<std::endl;
		return;
	}
	std::cout<<winner<<" win"<<'\n'<<'\n'<<"game finished"<<'\n'<<std::endl;
	std::cout<<"==============================="<<'\n'<<'\n'<<std::endl;
}

bool Grid::isOccupied(int row, int col) {
	return getCell(row, col) != Cell::Unoccupied;
}

bool Grid::isNotOut(int row, int col) {
	return row >= 0 && row < size && col >= 0 && col < size;
}

bool Grid::isNotSurface(int row, int col, Cell c) {
	int result = 0;
	if (isNotOut(row - 1, col)){
		if (getCell(row - 1, col) == c){
			result += 1;
		}
	}
	if (isNotOut(row + 1, col)){
		if (getCell(row + 1, col) == c){
			result += 1;
		}
	}
	if (isNotOut(row, col + 1)){
		if (getCell(row, col + 1) == c){
			result += 1;
		}
	}
	if (isNotOut(row, col - 1)){
		if (getCell(row, col - 1) == c){
			result += 1;
		}
	}
	return result == 0;
}

bool Grid::isCorner(int row, int col, Cell c){
	int result = 0;
	if (isNotOut(row - 1, col - 1)){
		if (getCell(row - 1, col - 1) == c){
			result += 1;
		}
	}
	if (isNotOut(row - 1, col + 1)){
		if (getCell(row - 1, col + 1) == c){
			result += 1;
		}
	}
	if (isNotOut(row + 1, col - 1)){
		if (getCell(row + 1, col - 1) == c){
			result += 1;
		}
	}
	if (isNotOut(row + 1, col + 1)){
		if (getCell(row + 1, col + 1) == c){
			result += 1;
		}
	}
	return result > 0;
}

bool Grid::isOk(int row, int col, Cell c) {
	return isNotOut(row, col) && !isOccupied(row, col) && isNotSurface(row, col, c);
}

bool Grid::firstisOk(int row, int col, Cell c){
	Cell p = c;
	c = p;
	return isNotOut(row, col);
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
bool Grid::putShape(const Shape& sp, int row, int col, Orientation o, Cell c, std::function<bool(int,int,Cell,Grid*)> func, bool cornercheck) {
	Shape holder (sp);
	holder = holder.transform(o).move(Coordinate(row, col));
	if (!checkShape(sp, row, col, o, c, func, cornercheck)){
		return false;
	}
	for (auto i:holder.data){
		getCellRef(i.row, i.col) = c;
	}
	return true;
}

// Todo: put shape into grid (improve to private holder.data later)
bool Grid::checkShape(const Shape& sp, int row, int col, Orientation o, Cell c, std::function<bool(int,int,Cell,Grid*)> func, bool cornercheck) {
	Shape holder (sp);
	holder = holder.transform(o).move(Coordinate(row, col));
	int result = 0;
	for (auto i:holder.data){
		if (!func(i.row,i.col,c,this)){
			return false;
		}
		if (isCorner(row, col, c)){
			result += 1;
		}
	}
	if (cornercheck){
		if (result == 0){
			return false;
		}
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


