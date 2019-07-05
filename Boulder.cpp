/*****************************************************
 * Program name:	Entfender, Boulder.cpp
 * Author:		Dylan Bergschneider
 * Date:		6/6/2019
 * Description:		Represents a boulder item (used
 * 			to destroy buildings)
 *****************************************************/

#include <string>

#include "Item.hpp"
#include "Boulder.hpp"
#include "Colors.hpp"
#include "Sprites.hpp"

Boulder::Boulder(){

	itemID = 0;
	color = bFor;
	sprite = bSpr;
	itemString = "Boulder        ";
}


