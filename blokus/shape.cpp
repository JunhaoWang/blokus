//
//  shape.cpp
//  blokus
//
//  Created by Junhao Wang on 10/27/16.
//  Copyright © 2016 Junhao Wang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include "shape.h"

Shape::Shape(std::initializer_list<Coordinate> coords){
	data = std::vector<Coordinate> (coords);
}

Shape Shape::move(Coordinate coord){
	Shape holder (*this);
	for (auto i: data){
		i.row += coord.row;
		i.col += coord.col;
	}
	return holder;
}


Shape Shape::transform(Orientation o){
	Shape holder (*this);
	switch (o) {
		case Orientation::UpPos:
			return holder;
		case Orientation::UpNeg:
			return holder;
			break;
		case Orientation::RightPos:
			return holder;
			break;
		case Orientation::RightNeg:
			return holder;
			break;
		case Orientation::DownPos:
			return holder;
			break;
		case Orientation::DownNeg:
			return holder;
			break;
		case Orientation::LeftPos:
			return holder;
			break;
		case Orientation::LeftNeg:
			return holder;
			break;
		default:
			abort();
	}
	return holder;
}


