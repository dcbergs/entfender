/*****************************************************
 * Program name:	Entfender, Item.cpp
 * Author:		Dylan Bergschneider
 * Date:		6/6/2019
 * Description:		Represents an abstract item
 *****************************************************/

#include <iostream>
#include <string>

#include "Item.hpp"

Item::Item(){
	daysSitting = 0;
}

int Item::getDaysSitting(){
	return daysSitting;
}

void Item::incrementDaysSitting(){
	daysSitting++;
}

void Item::draw(){
	std::cout << color << sprite;
}

std::string Item::getItemString(){

	return itemString;
}

int Item::getItemID(){
	return itemID;
}
