/****************************************************************
 * Program name:	Entfender, Building.cpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Derived class of Space to represent a
 * 			building
 ***************************************************************/

#include <string>
#include <iostream>

#include "Building.hpp"
#include "Highway.hpp"
#include "Colors.hpp"
#include "Sprites.hpp"

Building::Building(){

	spaceID = 5;

}

void Building::action(){

/*
	//if it's next to a building
	if(hasNeighbor(5)){
		//select random neighbor
		//Space* temp = randomNeighbor();
		//if that neighbor is a building, do nothing
		//if(temp->getSpaceID() == 5){
		//}
		//if that neighbor is a road, make it a building
		//else if(temp->getSpaceID() == 4){
			
		//if that neighbor is anything else, make it a road
		else{
			delete temp;
			temp = new Highway();
		}
	}
	//otherwise
	else{
		//select a random neighbor
		//chance of road or farm
	}
*/
}

std::string Building::getSpaceType(){

	return "Building";
}

void Building::draw(){

	std::cout << buBkg;

	if(item != nullptr){
		item->draw();
	}
	else{
		std::cout << buFor << buSpr;
	}
}

void Building::setBkg(){

	std::cout << buBkg;

}

