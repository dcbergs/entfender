/****************************************************************
 * Program name:	Entfender, Space.hpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		abstract class to represent tiles in game
 ***************************************************************/

#include <string>
#include <set>
#include <utility>

#include "Item.hpp"

#ifndef SPACE_HPP
#define SPACE_HPP

class Space{

	protected:
		int age;
		int spaceID;
		Item* item;
		Space* top;
		Space* right;
		Space* bottom;
		Space* left;
	public:
		Space();
		~Space();
		virtual std::string getSpaceType() = 0;
		virtual void draw() = 0;
		virtual void setBkg() = 0;
		virtual void action() = 0;

		void setItem(Item* newItem);
		Item* getItem();

		//for re-assigning item to ent
		void removeItem();
		//for deleting item when it times out
		void deleteItem();

		int getAge();
		int getSpaceID();
		void incAge();

		bool hasNeighbor(int tileID);
		int getRandomNeighbor();
		void findAdjacents(std::set<std::pair<int,int>> &adjacents, int spaceID, int row, int column);
		void findAdjacentsOnce(std::set<std::pair<int,int>> &adjacents, int spaceID, int row, int column);
		void findLine(std::set<std::pair<int,int>> &adjacents, int spaceID, int row, int column);

		void setTop(Space* newTop);
		void setRight(Space* newRight);
		void setBottom(Space* newBottom);
		void setLeft(Space* newLeft);

		Space* getTop();
		Space* getRight();
		Space* getBottom();
		Space* getLeft();

};

#endif
