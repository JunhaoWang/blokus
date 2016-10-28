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

Shape Shape::move(Coordinate coord) const{
	Shape holder (*this);
	for (auto &i: holder.data){
		std::cout<<"Move coord "<<i.row<<" "<<i.col<<std::endl;
		i.row += coord.row;
		i.col += coord.col;
	}
	return holder;
}


// shape template default to be RightNeg
Shape Shape::transform(Orientation o) const{
	Shape holder (*this);
	switch (o) {

/*			UpPos example:
 
					 #
					 ##
					 #
					 #
*/
		case Orientation::UpPos:
			return holder;
			
////////////////////////////////////////////
			
/*			UpNeg example:
 
					 #
					##
					 #
					 #
*/
		case Orientation::UpNeg:
			return holder;
			break;

////////////////////////////////////////////
			
/*			RightPos example

					#
				 #####
*/
		
		case Orientation::RightPos:
			return holder;
			break;
			
////////////////////////////////////////////

/*		!!! RightNeg example !!! (this is default template Orientation)
 
				 #####
					#
 */
		
		case Orientation::RightNeg:
			return holder;
			break;

////////////////////////////////////////////

/*			DownPos example
 
					 #
					 #
					 ##
					 #
*/
			
			
		case Orientation::DownPos:
			for (auto& i: holder.data){
				i.row *= -1;
			}
			return holder;
			break;
			
////////////////////////////////////////////

/*			DownNeg example
 
					 #
					 #
					##
					 #
*/
			
		case Orientation::DownNeg:
			return holder;
			break;
			
////////////////////////////////////////////

/*			LeftPos example
 
				  #
				 #####
*/
			
		case Orientation::LeftPos:
			return holder;
			break;
			
////////////////////////////////////////////

/*			LeftNeg example
 
				#####
				 #
*/
			
		case Orientation::LeftNeg:
			return holder;
			break;
			
////////////////////////////////////////////

		// Unspecified transformation
		default:
			abort();
	}
	return holder;
}



