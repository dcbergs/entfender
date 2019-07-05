/****************************************************************
 * Program name:	Entfender, OldGrowth.cpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Derived class of Space to represent old
 * 			growth forest
 ***************************************************************/

#include <string>
#include <iostream>

#include "OldGrowth.hpp"
#include "Colors.hpp"
#include "Sprites.hpp"
#include "Item.hpp"

OldGrowth::OldGrowth(){

	spaceID = 0;

}

void OldGrowth::action(){
}


std::string OldGrowth::getSpaceType(){

	return "Old growth forest";
}

void OldGrowth::draw(){

	std::cout << ogBkg;

	if(item != nullptr){
		item->draw();
	}
	else{
		std::cout << ogFor << dark;
	}
}

void OldGrowth::setBkg(){

	std::cout << ogBkg;

}


