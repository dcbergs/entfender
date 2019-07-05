/*****************************************************
 * Program name:	Entfender, Fire.cpp
 * Author:		Dylan Bergschneider
 * Date:		6/9/2019
 * Description:		Represents a fire item (used
 * 			to burn down farms)
 *****************************************************/
#include <string>

#include "Item.hpp"
#include "Fire.hpp"
#include "Colors.hpp"
#include "Sprites.hpp"

Fire::Fire(){

	itemID = 3;
	color = fFor;
	sprite = fSpr;
	itemString = "Fire           ";
}

