//
//  strategy.h
//  blokus
//
//  Created by Junhao Wang on 11/5/16.
//  Copyright © 2016 Junhao Wang. All rights reserved.
//

#ifndef strategy_h
#define strategy_h

#include "shape.h"

struct Move{
	std::vector<Shape>::iterator s;
	int row;
	int col;
	Orientation o;
	Move(std::vector<Shape>::iterator sin, int rowin, int colin, Orientation oin):s(sin),row(rowin),col(colin),o(oin){}
};

class Strategy{
public:
	std::vector<std::vector<Move>> allmoves;
	void addmoves(std::vector<Move> ms) {
		allmoves.push_back(ms);
	}
	virtual Move getmove() = 0;
};

#endif /* strategy_h */








