/****************************************************************
 * Program name:	Entfender, Farm.cpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Derived class of Space to represent a
 * 			farm plot
 ***************************************************************/

#include <string>
#include <iostream>

#include "Farm.hpp"
#include "Dirt.hpp"
#include "Highway.hpp"
#include "Colors.hpp"
#include "Sprites.hpp"

Farm::Farm(){

	spaceID = 6;

}

void Farm::action(){


}

std::string Farm::getSpaceType(){

	return "Farmland";
}

void Farm::draw(){

	std::cout << flBkg;

	if(item != nullptr){
		item->draw();
	}
	else{
		std::cout << flFor << light;
	}
}

void Farm::setBkg(){

	std::cout << flBkg;

}

