/****************************************************************
 * Program name:	Entfender, OldGrowth.hpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Derived class of Space to represent old
 * 			growth forest
 ***************************************************************/

#include <string>

#include "Space.hpp"

#ifndef OLDGROWTH_HPP
#define OLDGROWTH_HPP

class OldGrowth : public Space{

	public:
		OldGrowth();
		std::string getSpaceType();
		void draw();
		void setBkg();
		void action();

};

#endif

