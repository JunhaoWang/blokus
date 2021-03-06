//
//  shape.h
//  blokus
//
//  Created by Junhao Wang on 10/27/16.
//  Copyright © 2016 Junhao Wang. All rights reserved.
//

#ifndef shape_h
#define shape_h

#include <vector>
#include <string>

enum class Orientation {
	UpPos,
	UpNeg,
	RightPos,
	RightNeg,
	DownPos,
	DownNeg,
	LeftPos,
	LeftNeg
};

struct Coordinate {
	int row;
	int col;
	Coordinate(int r, int c) : row(r), col(c) {}
	void flipx(){
		col *= -1;
	}
	void flipy(){
		row *= -1;
	}
	void rotate(){
		int holder = row;
		row = col;
		col = -holder;
	}
};

class Shape{
public:
	Shape(std::initializer_list<Coordinate> coords, std::string namein);
	Shape transform(Orientation o) const;
	Shape move(Coordinate coord) const;
	void print(){
		std::cout<<name<<std::endl<<std::endl;
	}
//private:
	std::vector<Coordinate> data;
	std::string name;
	
};

#endif /* shape_h */
