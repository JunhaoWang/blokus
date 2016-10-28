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
};

class Shape{
public:
	Shape(std::initializer_list<Coordinate> coords);
	Shape transform(Orientation o) const;
	Shape move(Coordinate coord) const;
	
private:
	std::vector<Coordinate> data;
	
};

#endif /* shape_h */
