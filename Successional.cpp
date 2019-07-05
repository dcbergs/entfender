/****************************************************************
 * Program name:	Entfender, Successional.cpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Derived class of Space to represent 
 * 			successional forest
 ***************************************************************/

#include <string>
#include <iostream>

#include "Successional.hpp"
#include "Colors.hpp"
#include "Sprites.hpp"

Successional::Successional(){

	spaceID = 1;

}

void Successional::action(){
}

std::string Successional::getSpaceType(){

	return "Successional forest";
}

void Successional::draw(){

	std::cout << sfBkg;

	if(item != nullptr){
		item->draw();
	}
	else{
		std::cout << sfFor << light;
	}
}

void Successional::setBkg(){

	std::cout << sfBkg;

}

