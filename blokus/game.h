//
//  game.h
//  blokus
//
//  Created by Junhao Wang on 11/5/16.
//  Copyright © 2016 Junhao Wang. All rights reserved.
//

#ifndef game_h
#define game_h

#include <iostream>
#include "player.h"
#include "grid.h"


bool isOk(int row, int col, Cell c, Grid* g) {
	return g->isOk(row, col, c);
}

bool firstisOk(int row, int col, Cell c, Grid *g){
	return g->firstisOk(row, col, c);
}

class Game{
public:
	Grid *grid;
	Player red;
	Player green;
	Player blue;
	Player yellow;
	bool verbose = true;
	bool slow = true;
	
	Game(Grid *gridin, Player& redin, Player& greenin, Player& bluein, Player& yellowin, bool verbosein, bool slowin): grid(gridin), red(redin), green(greenin),blue(bluein),yellow(yellowin),verbose(verbosein),slow(slowin) {}
	
	void play(){
		red.initplay(Corner::Upleft, grid->size, firstisOk, false);
		blue.initplay(Corner::Upright, grid->size, firstisOk, false);
		green.initplay(Corner::Downleft, grid->size, firstisOk, false);
		yellow.initplay(Corner::Downright, grid->size, firstisOk, false);
		while (red.play(isOk, true, verbose, slow) && blue.play(isOk, true, verbose, slow) && green.play(isOk, true, verbose, slow) && yellow.play(isOk, true, verbose, slow)){
			
		}
		grid->print();
		grid->win();
	}
	
};

#endif /* game_h */
