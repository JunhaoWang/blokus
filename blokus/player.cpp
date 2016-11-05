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

#include "player.h"

bool Player::playat(int row, int col, std::function<bool(int,int,Cell,Grid*)> func, bool cornercheck){
	for (auto& skey: shapes){
		for (auto s = skey.second.begin(); s != skey.second.end(); ++s){
			for (auto o: orients){
				if (grid->checkShape(*s, row, col, o, cell, func, cornercheck)){
					grid->putShape(*s, row, col, o, cell, func, cornercheck);
					skey.second.erase(s);
					return true;
				}
			}
		}
	}
	return false;
}


bool Player::play(std::function<bool(int,int,Cell,Grid*)> func, bool cornercheck){
	for (auto& skey: shapes){
		for (auto s = skey.second.begin(); s != skey.second.end(); ++s){
			for (auto o: orients){
				for (int i = 0; i < grid->size*grid->size; ++i){
					if (grid->checkShape(*s, i/grid->size, i%grid->size, o, cell, func, cornercheck)){
						grid->putShape(*s, i/grid->size, i%grid->size, o, cell, func, cornercheck);
						skey.second.erase(s);
						return true;
					}
				}
			}
		}
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