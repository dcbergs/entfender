/*****************************************************
 * Program name:	Entfender, Item.hpp
 * Author:		Dylan Bergschneider
 * Date:		6/6/2019
 * Description:		Represents an abstract item
 *****************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

class Item{

	protected:
		static const int daysTillDisappear = 18;
		int daysSitting;
		int itemID;
		std::string color;
		std::string sprite;
		std::string itemString;
	public:
		Item();
		int getDaysSitting();
		void incrementDaysSitting();
		void draw();
		std::string getItemString();
		int getItemID();
};

#endif

