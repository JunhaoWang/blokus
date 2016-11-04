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

Shape::Shape(std::initializer_list<Coordinate> coords, std::string namein): name(namein){
	data = std::vector<Coordinate> (coords);
}

Shape Shape::move(Coordinate coord) const{
	Shape holder (*this);
	for (auto &i: holder.data){
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
			for (auto &i:holder.data){
				i.rotate();
				i.rotate();
				i.rotate();
			}
			return holder;
			
////////////////////////////////////////////
			
/*			UpNeg example:
 
					 #
					##
					 #
					 #
*/
		case Orientation::UpNeg:
			for (auto &i:holder.data){
				i.rotate();
				i.rotate();
				i.rotate();
				i.flipx();
			}
			return holder;
			break;

////////////////////////////////////////////
			
/*			RightPos example

					#
				 #####
*/
		
		case Orientation::RightPos:
			for (auto &i:holder.data){
				i.flipy();
			}
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
			for (auto &i:holder.data){
				i.rotate();
				i.flipx();
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
			for (auto &i:holder.data){
				i.rotate();
			}
			return holder;
			break;
			
////////////////////////////////////////////

/*			LeftPos example
 
				  #
				 #####
*/
			
		case Orientation::LeftPos:
			for (auto &i:holder.data){
				i.rotate();
				i.rotate();
			}
			return holder;
			break;
			
////////////////////////////////////////////

/*			LeftNeg example
 
				#####
				 #
*/
			
		case Orientation::LeftNeg:
			for (auto &i:holder.data){
				i.rotate();
				i.rotate();
				i.flipy();
			}
			return holder;
			break;
			
////////////////////////////////////////////

		// Unspecified transformation
		default:
			abort();
	}
	return holder;
}



