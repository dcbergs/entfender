/****************************************************************
 * Program name:	Entfender, Dirt.hpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Derived class of Space to represent a
 * 			plot of dirt
 ***************************************************************/

#include <string>

#include "Space.hpp"

#ifndef DIRT_HPP
#define DIRT_HPP

class Dirt : public Space{

	public:
		Dirt();
		std::string getSpaceType();
		void draw();
		void setBkg();
		void action();

};

#endif



