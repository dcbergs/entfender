/****************************************************************
 * Program name:	Entfender, Successional.hpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Derived class of Space to represent 
 * 			successional forest
 ***************************************************************/

#include <string>

#include "Space.hpp"

#ifndef SUCCESSIONAL_HPP
#define SUCCESSIONAL_HPP

class Successional : public Space{

	public:
		Successional();
		std::string getSpaceType();
		void draw();
		void setBkg();
		void action();

};

#endif


