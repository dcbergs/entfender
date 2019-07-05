/****************************************************************
 * Program name:	Entfender, Highway.hpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Derived class of Space to represent a
 * 			road
 ***************************************************************/

#include <string>

#include "Space.hpp"

#ifndef HIGHWAY_HPP
#define HIGHWAY_HPP

class Highway : public Space{

	public:
		Highway();
		std::string getSpaceType();
		void draw();
		void setBkg();
		void action();

};

#endif



