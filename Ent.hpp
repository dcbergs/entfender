/********************************************************
 * Program name:	Entfender, Ent.hpp
 * Author:		Dylan Bergschneider
 * Date:		6/3/2019
 * Description:		Holds basic information about the
 * 			player character, an ent.
 *******************************************************/

#include "Item.hpp"

#ifndef ENT_HPP
#define ENT_HPP

class Ent{

	private:
		int health; //?
		int row;
		int column;
		Item* inventory[5];

	public:
		Ent(int startRow, int startColumn);
		~Ent();
		int getHealth();
		void takeDamage();
		void healEnt();
		int getRow();
		int getColumn();
		void setRow(int newRow);
		void setColumn(int newColumn);
		bool isOn(int qRow, int qColumn);
		void draw();
		void drawHP();
		bool canDo(char input);
		void action(char input);

		//inventory functions
		bool isItem(int slot);
		Item* getItem(int slot);
		Item* getItem(char input);
		bool hasSpace();
		void putItem(Item* item);
		void removeItem(int slot);
};

#endif

