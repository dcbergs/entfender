/*************************************************
 * Program name:	Entfender, Game.hpp
 * Author:		Dylan Bergschneider
 * Date:		6/3/2019
 * Description:		holds a Map and Ent object,
 * 			runs the game loop.
 ************************************************/

#include <string>

#include "Item.hpp"
#include "Map.hpp"
#include "Ent.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game{

	private:
		Map* map;
		Ent* ent;

	public:
		Game();
		~Game();
		std::string iterate();
		void draw();
		int randomRow();
		int randomColumn();
};
#endif
