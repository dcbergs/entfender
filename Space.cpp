/****************************************************************
 * Program name:	Entfender, Space.cpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		abstract class to represent tiles in game
 ***************************************************************/

#include <stdlib.h>
#include <set>
#include <utility>
#include <iostream> //only for debugging

#include "Space.hpp"
#include "Item.hpp"

Space::Space(){

	item = nullptr;
	age = 0;
}

Space::~Space(){
	delete item;
	item = nullptr;
}


//for re-assigning item to ent
void Space::removeItem(){

	item = nullptr;
}

//for deleting item when it times out
void Space::deleteItem(){

	delete item;
	item = nullptr;

}

int Space::getAge(){
	return age;
}

int Space::getSpaceID(){
	return spaceID;
}

void Space::incAge(){

	age++;
	if(item != nullptr){
		item->incrementDaysSitting();
		if(item->getDaysSitting() >= 15){
			deleteItem();
		}
	}
}

void Space::setItem(Item* newItem){

	if(item != nullptr){
		Item* temp = item;
		item = newItem;
		delete temp;
	}
	else{
		item = newItem;
	}
}

Item* Space::getItem(){
	return item;
}


void Space::setTop(Space* newTop){
	top = newTop;
}

void Space::setRight(Space* newRight){
	right = newRight;
}

void Space::setBottom(Space* newBottom){
	bottom = newBottom;
}

void Space::setLeft(Space* newLeft){
	left = newLeft;
}

Space* Space::getTop(){
	return top;
}
Space* Space::getRight(){
	return right;
}
Space* Space::getBottom(){
	return bottom;
}
Space* Space::getLeft(){
	return left;
}

//find all tiles of a given type within two degrees of adjacency
void Space::findAdjacents(std::set<std::pair<int, int>> &adjacents, int spaceID, int row, int column){


	if(top != nullptr && top->getSpaceID() == spaceID){
		std::pair<int, int> aPair;
		aPair.first = row - 1;
		aPair.second = column;
		adjacents.insert(aPair);
		findAdjacentsOnce(adjacents, spaceID, aPair.first, aPair.second);
	}
	if(right != nullptr && right->getSpaceID() == spaceID){
		std::pair<int, int> aPair;
		aPair.first = row;
		aPair.second = column + 1;
		adjacents.insert(aPair);
		findAdjacentsOnce(adjacents, spaceID, aPair.first, aPair.second);
	}
	if(bottom != nullptr && bottom->getSpaceID() == spaceID){
		std::pair<int, int> aPair;
		aPair.first = row + 1;
		aPair.second = column;
		adjacents.insert(aPair);
		findAdjacentsOnce(adjacents, spaceID, aPair.first, aPair.second);
	}
	if(left != nullptr && left->getSpaceID() == spaceID){
		std::pair<int, int> aPair;
		aPair.first = row;
		aPair.second = column - 1;
		adjacents.insert(aPair);
		findAdjacentsOnce(adjacents, spaceID, aPair.first, aPair.second);
	}

}

//find all tiles of a given type within one more degree of adjacency
void Space::findAdjacentsOnce(std::set<std::pair<int, int>> &adjacents, int spaceID, int row, int column){

	if(top != nullptr){
		if(top->getTop() != nullptr && top->getTop()->getSpaceID() == spaceID){
			std::pair<int, int> aPair;
			aPair.first = row - 1;
			aPair.second = column;
			adjacents.insert(aPair);
		}
	}
	if(right != nullptr){
		if(right->getRight() != nullptr && right->getRight()->getSpaceID() == spaceID){
			std::pair<int, int> aPair;
			aPair.first = row;
			aPair.second = column + 1;
			adjacents.insert(aPair);
		}
	}
	if(bottom != nullptr){
		if(bottom->getBottom() != nullptr && bottom->getBottom()->getSpaceID() == spaceID){
			std::pair<int, int> aPair;
			aPair.first = row + 1;
			aPair.second = column;
			adjacents.insert(aPair);
		}
	}
	if(left != nullptr){
		if(left->getLeft() != nullptr && left->getLeft()->getSpaceID() == spaceID){
			std::pair<int, int> aPair;
			aPair.first = row;
			aPair.second = column - 1;
			adjacents.insert(aPair);
		}
	}
}

//find all tiles of a given type in a line
void Space::findLine(std::set<std::pair<int, int>> &adjacents, int spaceID, int row, int column){

	if(hasNeighbor(spaceID)){

		while(adjacents.empty()){

			int randLine = getRandomNeighbor();
			switch(randLine){
				case 0:
					{
					Space* iterator = top;
					int counter = 1;
					while(iterator != nullptr && iterator->getSpaceID() == 3){

						std::pair<int, int> aPair;
						aPair.first = row - counter;
						aPair.second = column;
						adjacents.insert(aPair);

						counter++;
						iterator = iterator->getTop();
					
					}
					break;
					}
				case 1:
					{
					Space* iterator = right;
					int counter = 1;
					while(iterator != nullptr && iterator->getSpaceID() == 3){

						std::pair<int, int> aPair;
						aPair.first = row;
						aPair.second = column + counter;
						adjacents.insert(aPair);

						counter++;
						iterator = iterator->getRight();
					
					}
					break;
					}
				case 2:
					{
					Space* iterator = bottom;
					int counter = 1;
					while(iterator != nullptr && iterator->getSpaceID() == 3){

						std::pair<int, int> aPair;
						aPair.first = row + counter;
						aPair.second = column;
						adjacents.insert(aPair);

						counter++;
						iterator = iterator->getBottom();
					
					}
					break;
					}
				case 3:
					{
					Space* iterator = left;
					int counter = 1;
					while(iterator != nullptr && iterator->getSpaceID() == 3){

						std::pair<int, int> aPair;
						aPair.first = row;
						aPair.second = column - counter;
						adjacents.insert(aPair);

						counter++;
						iterator = iterator->getLeft();
					}	
					break;
					}
			}
		}
	}
}


bool Space::hasNeighbor(int tileID){

	bool neighbor = false;

	if(top != nullptr && top->getSpaceID() == tileID){
		neighbor = true;
	}
	else if(right != nullptr && right->getSpaceID() == tileID){
		neighbor = true;
	}
	else if(bottom != nullptr && bottom->getSpaceID() == tileID){
		neighbor = true;
	}
	else if(left != nullptr && left->getSpaceID() == tileID){
		neighbor = true;
	}

	return neighbor;
}

int Space::getRandomNeighbor(){

	int neighbor = -1;
	while(neighbor == -1){
		int random = rand() % 4;
		switch(random){
			case 0:
				if(top != nullptr){
					neighbor = 0;
				}
				break;
			case 1:
				if(right != nullptr){
					neighbor = 1;
				}
				break;
			case 2:
				if(bottom != nullptr){
					neighbor = 2;
				}
				break;
			case 3:
				if(left != nullptr){
					neighbor = 3;
				}
				break;
		}
	}
	return neighbor;

}

