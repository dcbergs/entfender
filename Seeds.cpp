/*****************************************************
 * Program name:	Entfender, Seeds.cpp
 * Author:		Dylan Bergschneider
 * Date:		6/9/2019
 * Description:		Represents a seed item (used
 * 			to plant forests in dirt)
 *****************************************************/

#include <string>

#include "Item.hpp"
#include "Seeds.hpp"
#include "Colors.hpp"
#include "Sprites.hpp"

Seeds::Seeds(){

	itemID = 2;
	color = sFor;
	sprite = sSpr;
	itemString = "Seeds          ";
}

