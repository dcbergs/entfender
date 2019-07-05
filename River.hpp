/****************************************************************
 * Program name:	Entfender, River.hpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Derived class of Space to represent a
 * 			river
 ***************************************************************/

#include <string>

#include "Space.hpp"

#ifndef RIVER_HPP
#define RIVER_HPP

class River : public Space{

	public:
		River();
		std::string getSpaceType();
		void draw();
		void setBkg();
		void action();

};

#endif


