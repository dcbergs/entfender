/****************************************************************
 * Program name:	Entfender, Dirt.cpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Derived class of Space to represent a
 * 			plot of dirt
 ***************************************************************/

#include <string>
#include <iostream>

#include "Dirt.hpp"
#include "Colors.hpp"
#include "Sprites.hpp"

Dirt::Dirt(){

	spaceID = 3;

}

void Dirt::action(){
}

std::string Dirt::getSpaceType(){

	return "Dirt";
}

void Dirt::draw(){

	std::cout << diBkg;

	if(item != nullptr){
		item->draw();
	}
	else{
		std::cout << " ";
	}
}

void Dirt::setBkg(){

	std::cout << diBkg;

}

