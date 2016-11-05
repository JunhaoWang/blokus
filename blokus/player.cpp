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

bool Player::play(){
	
	for (auto& skey: shapes){
		for (auto s = skey.second.begin(); s != skey.second.end(); ++s){
			for (auto o: orients){
				for (int i = 0; i < grid->size*grid->size; ++i){
					if (grid->checkShape(*s, i/grid->size, i%grid->size, o, cell)){
						grid->putShape(*s, i/grid->size, i%grid->size, o, cell);
						skey.second.erase(s);
						return true;
					}
				}
			}
		}
	}
	return false;
}
