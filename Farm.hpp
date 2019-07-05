/****************************************************************
 * Program name:	Entfender, Farm.hpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Derived class of Space to represent a
 * 			farm plot
 ***************************************************************/

#include <string>

#include "Space.hpp"

#ifndef FARM_HPP
#define FARM_HPP

class Farm : public Space{

	public:
		Farm();
		std::string getSpaceType();
		void draw();
		void setBkg();
		void action();

};

#endif



