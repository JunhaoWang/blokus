//
//  player.h
//  blokus
//
//  Created by Junhao Wang on 11/3/16.
//  Copyright © 2016 Junhao Wang. All rights reserved.
//

#ifndef player_h
#define player_h

#include <map>
#include <vector>

#include "shape.h"
#include "grid.h"
#include "strategy:random.h"

enum class Corner{
	Upleft,
	Upright,
	Downleft,
	Downright
};


class Player{
public:
	Player(Grid *gin, Cell cellin, std::map<int, std::vector<Shape>, std::greater<int>> shapesin, Strategy* strategyin): grid(gin),cell(cellin),shapes(shapesin), strategy(strategyin) {};
	
	bool play(std::function<bool(int,int,Cell,Grid* g)> func, bool cornercheck, bool verbose, bool slow);
	bool playat(int row, int col, std::function<bool(int,int,Cell,Grid*)> func, bool cornercheck);
	void initplay(Corner c, int size, std::function<bool(int,int,Cell,Grid*)> func, bool cornercheck);
	
	Grid *grid;
	Cell cell;
	Strategy *strategy;
	std::vector<Move> moves;
	std::map<int, std::vector<Shape>, std::greater<int>> shapes;
	std::vector<Orientation> orients = {Orientation::UpPos,
		Orientation::UpNeg,
		Orientation::RightPos,
		Orientation::RightNeg,
		Orientation::DownPos,
		Orientation::DownNeg,
		Orientation::LeftPos,
		Orientation::LeftNeg};
	
};


#endif /* player_h */
