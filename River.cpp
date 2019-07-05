/****************************************************************
 * Program name:	Entfender, River.cpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Derived class of Space to represent a
 * 			river
 ***************************************************************/

#include <string>
#include <iostream>

#include "River.hpp"
#include "Colors.hpp"
#include "Sprites.hpp"

River::River(){

	spaceID = 2;

}

void River::action(){
}

std::string River::getSpaceType(){

	return "River";
}

void River::draw(){

	std::cout << fwBkg;

	if(item != nullptr){
		item->draw();
	}
	else{
		std::cout << " ";
	}
}

void River::setBkg(){

	std::cout << fwBkg;

}

