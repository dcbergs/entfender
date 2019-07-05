/****************************************************************
 * Program name:	Entfender, Highway.cpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Derived class of Space to represent a
 * 			road
 ***************************************************************/

#include <string>
#include <iostream>

#include "Highway.hpp"
#include "Colors.hpp"
#include "Sprites.hpp"

Highway::Highway(){

	spaceID = 4;

}

void Highway::action(){

}

std::string Highway::getSpaceType(){

	return "Road";
}

void Highway::draw(){

	std::cout << hwBkg;

	if(item != nullptr){
		item->draw();
	}
	else{
		std::cout << " ";
	}
}

void Highway::setBkg(){

	std::cout << hwBkg;

}

