/****************************************************************
 * Program name:	Entfender, Map.hpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Contains a map of Space objects in a grid
 ***************************************************************/

#include "Space.hpp"
#include "Item.hpp"

#include <vector>

#ifndef MAP_HPP
#define MAP_HPP

class Map{

	protected:
		Space *** grid;
		int humanTiles;
		int neutralTiles;
		int entTiles;

	public:
		Map(int levelNumber);
		~Map();
		void linker();
		void countTiles();
		int startEntRow(int levelNumber);
		int startEntColumn(int levelNumber);

		int getHumanTiles();
		int getEntTiles();

		void bkg(int row, int column);
		void draw(int row, int column);
		bool isOG(int row, int column);
		bool isItem(int row, int column);
		Item* getItem(int row, int column);
		//removes item for ent to have, does not delete it
		void removeItem(int row, int column);
		//deletes item, use for when item times out
		void deleteItem(int row, int column);
		void useItem(Item* item, int row, int column);

		void growthSim();
		void ageStep();
		void addItem();
		void spreadFarm(int row, int column);
		void spreadBuilding(int row, int column);
		void spreadHighway(int row, int column);

		int randomRow();
		int randomColumn();

};

#endif
