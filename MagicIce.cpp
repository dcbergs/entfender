/*****************************************************
 * Program name:	Entfender, MagicIce.cpp
 * Author:		Dylan Bergschneider
 * Date:		6/9/2019
 * Description:		Represents a magic ice item (used
 * 			to destroy roads)
 *****************************************************/

#include <string>

#include "Item.hpp"
#include "MagicIce.hpp"
#include "Colors.hpp"
#include "Sprites.hpp"

MagicIce::MagicIce(){

	itemID = 1;
	color = iFor;
	sprite = iSpr;
	itemString = "Magic Ice      ";
}


