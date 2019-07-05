/****************************************************************
 * Program name:	Entfender, Building.hpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Derived class of Space to represent a
 * 			building
 ***************************************************************/

#include <string>

#include "Space.hpp"

#ifndef BUILDING_HPP
#define BUILDING_HPP

class Building : public Space{

	public:
		Building();
		std::string getSpaceType();
		void draw();
		void setBkg();
		void action();

};

#endif


