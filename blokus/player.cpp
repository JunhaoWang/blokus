//
//  player.cpp
//  blokus
//
//  Created by Junhao Wang on 11/3/16.
//  Copyright © 2016 Junhao Wang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <typeinfo>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <thread>

#include "player.h"

bool Player::playat(int row, int col, std::function<bool(int,int,Cell,Grid*)> func, bool cornercheck){
	for (auto& skey: shapes){
		for (auto s = skey.second.begin(); s != skey.second.end(); ++s){
			for (auto o: orients){
				if (grid->checkShape(*s, row, col, o, cell, func, cornercheck)){
					moves.push_back(Move(s, row, col, o));
				}
			}
		}
	}
	
//	std::cout<<"initial found "<<moves.size()<<" moves"<<'\n';
	
	if (!moves.empty()){
		std::random_shuffle(moves.begin(), moves.end());
		srand((int)time(NULL)*2);
		auto m = moves[rand()%moves.size()];
		grid->putShape(*m.s, m.row, m.col, m.o, cell, func, cornercheck);
		int num = (int)(*(m.s)).data.size();
		shapes[num].erase(m.s);
		moves.clear();
		return true;
	}
	
	return false;
}

/*
 
 struct Move{
	Shape s;
	int row;
	int col;
	Orientation o;
	Move(Shape &sin, int rowin, int colin, Orientation oin):s(sin),row(rowin),col(colin),o(oin){}
 };
 
 */

bool Player::play(std::function<bool(int,int,Cell,Grid*)> func, bool cornercheck, bool verbose, bool slow){
	for (auto& skey: shapes){
		for (auto s = skey.second.begin(); s != skey.second.end(); ++s){
			for (auto o: orients){
				for (int i = 0; i < grid->size*grid->size; ++i){
					if (grid->checkShape(*s, i/grid->size, i%grid->size, o, cell, func, cornercheck)){
						moves.push_back(Move(s, i/grid->size, i%grid->size, o));
					}
				}
			}
		}
	}
	
//	std::cout<<"found "<<moves.size()<<" moves"<<'\n';
	
	if (!moves.empty()){
		std::random_shuffle(moves.begin(), moves.end());
		srand((int)time(NULL));
		auto m = moves[rand()%moves.size()];
		grid->putShape(*m.s, m.row, m.col, m.o, cell, func, cornercheck);
		int num = (int)(*(m.s)).data.size();
		shapes[num].erase(m.s);
		moves.clear();
		if (verbose){
			grid->print();
		}
		if (slow){
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		return true;
	}

	return false;
}

void Player::initplay(Corner c, int size, std::function<bool(int,int,Cell,Grid*)> func, bool cornercheck){
	switch (c){
		case Corner::Upleft:
			playat(0, 0, func, cornercheck);
			break;
		case Corner::Upright:
			playat(0, size - 1, func, cornercheck);
			break;
		case Corner::Downleft:
			playat(size - 1, 0, func, cornercheck);
			break;
		case Corner::Downright:
			playat(size - 1, size - 1, func, cornercheck);
			break;
	}
}