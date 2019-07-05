/*****************************************************
 * Program name:	Entfender, Heal.cpp
 * Author:		Dylan Bergschneider
 * Date:		6/9/2019
 * Description:		Represents a healing item (used
 * 			to heal yourself)
 *****************************************************/

#include <string>

#include "Item.hpp"
#include "Heal.hpp"
#include "Colors.hpp"
#include "Sprites.hpp"

Heal::Heal(){

	itemID = 5;
	color = hFor;
	sprite = hSpr;
	itemString = "Heal           ";
}

