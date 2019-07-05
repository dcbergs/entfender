/*****************************************************
 * Program name:	Entfender, Water.cpp
 * Author:		Dylan Bergschneider
 * Date:		6/9/2019
 * Description:		Represents a water item (used
 * 			to flood tiles)
 *****************************************************/

#include <string>

#include "Item.hpp"
#include "Water.hpp"
#include "Colors.hpp"
#include "Sprites.hpp"

Water::Water(){

	itemID = 4;
	color = wFor;
	sprite = wSpr;
	itemString = "Water          ";
}
