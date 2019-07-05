/********************************************************
 * Program name:	Entfender, Ent.cpp
 * Author:		Dylan Bergschneider
 * Date:		6/3/2019
 * Description:		Holds basic information about the
 * 			player character, an ent.
 *******************************************************/

#include <iostream>

#include "Ent.hpp"
#include "Colors.hpp"
#include "Sprites.hpp"

Ent::Ent(int startRow, int startColumn){

	row = startRow;
	column = startColumn;
	health = 50;

	for(int i = 0; i < 5; i++){
		inventory[i] = nullptr;
	}

}

Ent::~Ent(){
	//delete inventory
	for(int i = 0; i < 5; i++){

		delete inventory[i];
	}
}

void Ent::removeItem(int slot){

	Item* temp = inventory[slot];
	inventory[slot] = nullptr;
	delete temp;

}

void Ent::healEnt(){
	health = 50;
}

bool Ent::isItem(int slot){

	if(slot < 0 || slot > 4){
		return false;
	}
	else if(inventory[slot] != nullptr){
		return true;
	}
	return false;
}

//not safeguarded for out-of-bounds, call isItem() first!
Item* Ent::getItem(int slot){

	return inventory[slot];
}

Item* Ent::getItem(char input){

	return inventory[(input - '0' - 1)];
}


bool Ent::canDo(char input){
	bool can = false;
	if(input == 'w' && row > 0){
		can = true;
	}
	else if(input == 'a' && column > 0){
		can = true;
	}
	else if(input == 's' && row < 19){
		can = true;
	}
	else if(input == 'd' && column < 29){
		can = true;
	}
	else if(input == 'l'){
		//letter L, quit condition
		can = true;
	}
	//add conditions for item use
	else if(input == '1' && isItem(0)){
		can = true;
	}
	else if(input == '2' && isItem(1)){
		can = true;
	}
	else if(input == '3' && isItem(2)){
		can = true;
	}
	else if(input == '4' && isItem(3)){
		can = true;
	}
	else if(input == '5' && isItem(4)){
		can = true;
	}
	
	return can;
}


bool Ent::hasSpace(){

	for(int i = 0; i < 5; i++){
		if(inventory[i] == nullptr){
			return true;
		}
	}
	return false;

}

//not safe-guarded, use hasSpace() first
void Ent::putItem(Item* item){

	for(int i = 0; i < 5; i++){
		if(inventory[i] == nullptr){
			inventory[i] = item;
			i += 4;
		}
	}
}


void Ent::action(char input){

	switch(input){

		case 'w':
			row -= 1;
			break;
		case 'a':
			column -= 1;
			break;
		case 's':
			row += 1;
			break;
		case 'd':
			column += 1;
			break;
		//add conditions for items
	}
}


void Ent::takeDamage(){
	health -= 1;
}

int Ent::getHealth(){
	return health;
}

int Ent::getRow(){

	return row;
}

int Ent::getColumn(){

	return column;
}

void Ent::setRow(int newRow){

	row = newRow;
}

void Ent::setColumn(int newColumn){

	column = newColumn;
}

bool Ent::isOn(int qRow, int qColumn){

	if(row == qRow && column == qColumn){
		return true;
	}
	else{
		return false;
	}
}

void Ent::draw(){

	std::cout << eFor << eSpr;
}

void Ent::drawHP(){

	//greens is a fraction of 50 (max health) times 18 (health bar size)
	int greens = 18 * health;
	greens /= 50;
	if((18 * health) % 50 > 0){
		greens++;
	}
	std::cout << greenBkg;
	for(int i = 0; i < greens; i++){
		std::cout << " ";
	}
	std::cout << redBkg;
	for(int i = greens; i < 18; i++){
		std::cout << " ";
	}
}




