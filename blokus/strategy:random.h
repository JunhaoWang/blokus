//
//  strategy:random.h
//  blokus
//
//  Created by Junhao Wang on 11/5/16.
//  Copyright © 2016 Junhao Wang. All rights reserved.
//

#ifndef strategy_random_h
#define strategy_random_h

#include <algorithm>
#include <ctime>
#include "strategy.h"

class Strategy_Random:public Strategy{
public:
	virtual Move getmove() {
		std::random_shuffle(allmoves.back().begin(),allmoves.back().end());
		srand(static_cast<unsigned int>(time(NULL)));
		std::cout<<allmoves.size()<<'\n'<<'\n';
		return allmoves.back()[static_cast<unsigned long>(static_cast<unsigned long>(rand())%allmoves.back().size())];
	}
};



#endif /* strategy_random_h */
