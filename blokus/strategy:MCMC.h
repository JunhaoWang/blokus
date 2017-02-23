//
//  strategy:MCMC.h
//  blokus
//
//  Created by Junhao Wang on 11/5/16.
//  Copyright © 2016 Junhao Wang. All rights reserved.
//

#ifndef strategy_MCMC_h
#define strategy_MCMC_h

#include <algorithm>
#include <vector>
#include "strategy.h"

struct Node {
	int score = 0;
	int depth;
	Move m;
	Shape s;
	Node* prev;
	std::vector<Node*> children;
	Node(int scorein, int depthin, Move min, Shape sin, Node* previn, std::vector<Node*> childrenin): score(scorein), depth(depthin), m(min), s(sin), prev(previn), children(childrenin) {}
};

class MCtree {
public:
	int rounds = 0;
	
	Node* head;
	Node* select(Node* n);
	Node* expand(Node* n);
	void simulate(int times);
	
	MCtree(Node* headin): head(headin){}
};

class Strategy_MCMC:public Strategy_Random{
public:
	
	// TODO: input vector of legal moves, build a MCMC search tree in memory
	virtual void addmoves(std::vector<Move> ms) {
		Strategy_Random::addmoves(ms);
	}

	// TODO: get move from current MCMC search tree
	virtual Move getmove() {
		if (true){
			return Strategy_Random::getmove();
		}
		else {
			return Strategy_MCMC::getmove();
		}
	}
};

#endif /* strategy_MCMC_h */
