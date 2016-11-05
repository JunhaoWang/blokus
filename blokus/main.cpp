//
//  main.cpp
//  blokus
//
//  Created by Junhao Wang on 10/27/16.
//  Copyright © 2016 Junhao Wang. All rights reserved.
//

#include <iostream>
#include <type_traits>
#include <stdlib.h>
#include <map>

#include "grid.h"
#include "shape.h"
#include "player.h"

using namespace std;

// 21 shapes

static const Shape one_cell({Coordinate(0, 0)},"one_cell");
static const Shape two_cell({Coordinate(0, 0),Coordinate(0, 1)},"two_cell");
static const Shape three_cell({Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2)},"three_cell");
static const Shape four_cell({Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(0, 3)},"four_cell");
static const Shape five_cell({Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(0, 3),Coordinate(0, 4)},"five_cell");
static const Shape cross({Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(-1, 1),Coordinate(1, 1)},"cross");
static const Shape crossstrange({Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(-1, 1),Coordinate(1, 2)},"crossstrange");
static const Shape boomerangsmall({Coordinate(0, 0),Coordinate(0, 1),Coordinate(1,1)},"boomerangsmall");
static const Shape square({Coordinate(0, 0),Coordinate(0, 1),Coordinate(1, 0),Coordinate(1, 1)},"square");
static const Shape squaredot({Coordinate(0, 0),Coordinate(0, 1),Coordinate(1, 1),Coordinate(1, 2),Coordinate(0, 2)},"squaredot");
static const Shape tshape({Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(1, 1),Coordinate(2, 1)},"tshape");
static const Shape boomerangbig({Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(1, 2),Coordinate(2, 2)},"boomerangbig");
static const Shape mshape({Coordinate(0, 0),Coordinate(0, 1),Coordinate(1, 1),Coordinate(1, 2),Coordinate(2, 2)},"mshape");
static const Shape ushape({Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(1, 2),Coordinate(1, 0)},"ushape");
static const Shape boomerangbigkill({Coordinate(0, 0),Coordinate(0, 1),Coordinate(1, 1),Coordinate(2, 1),Coordinate(2, 2)},"boomerangbigkill");
static const Shape boomerangsmallkill({Coordinate(0, 0),Coordinate(0, 1),Coordinate(1, 1),Coordinate(1, 2)},"boomerangsmallkill");
static const Shape boomeranghalf({Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(1, 2),Coordinate(1, 3)},"boomeranghalf");
static const Shape lshapesmall({Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(1, 2)},"lshapesmall");
static const Shape lshapebig({Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(0, 3),Coordinate(1, 3)},"lshapebig");
static const Shape lshapebigmiddle({Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(0, 3),Coordinate(1, 2)},"lshapebigmiddle");
static const Shape lshapesmallmiddle({Coordinate(0, 0),Coordinate(0, 1),Coordinate(0, 2),Coordinate(1, 1)},"lshapesmallmiddle");


bool isOk(int row, int col, Cell c, Grid* g) {
	return g->isOk(row, col, c);
}

bool firstisOk(int row, int col, Cell c, Grid *g){
	return g->firstisOk(row, col, c);
}

int main(int argc, const char * argv[]) {
	int s = 30;
	Grid* grid = new Grid(s);
	vector<Shape> one {one_cell};
	vector<Shape> two {two_cell};
	vector<Shape> three {three_cell, boomerangsmall};
	vector<Shape> four {four_cell, square, lshapesmall, lshapesmallmiddle, boomerangsmallkill};
	vector<Shape> five {five_cell, cross, crossstrange, squaredot, tshape, boomerangbig, mshape, ushape, boomerangbigkill,boomeranghalf,lshapebig,lshapebigmiddle};
	
	map<int, vector<Shape>, greater<int>> m {{1,one}, {2,two}, {3,three}, {4,four}, {5,five}};
	
	Player red (grid, Cell::Red, m);
	Player blue (grid, Cell::Blue, m);
	Player green (grid, Cell::Green, m);
	Player yellow (grid, Cell::Yellow, m);
	
	red.initplay(Corner::Upleft, s, firstisOk, false);
	blue.initplay(Corner::Upright, s, firstisOk, false);
	green.initplay(Corner::Downleft, s, firstisOk, false);
	yellow.initplay(Corner::Downright, s, firstisOk, false);
	
	while (red.play(isOk, true) && blue.play(isOk, true) && green.play(isOk, true) && yellow.play(isOk, true)){
//	while (red.play(isOk)){
		grid->print();
		cout<<'\n';
	}
	grid->print();
	grid->win();
    return 0;
}
