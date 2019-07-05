/*********************************************************************
 * Program name:	Entfender, Colors.hpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Holds color constants for outputting colored
 * 			characters to console
 ********************************************************************/



#ifndef COLORS_HPP
#define COLORS_HPP


//return to defaults
const std::string default1 = "\033[0m";

//old growth forest
const std::string ogBkg = "\033[48;5;46m";
const std::string ogFor = "\033[38;5;22m";

//successional forest
const std::string sfBkg = "\033[48;5;46m";
const std::string sfFor = "\033[38;5;22m";

//river
const std::string fwBkg = "\033[48;5;4m";

//highway
const std::string hwBkg = "\033[48;5;8m";

//building
const std::string buBkg = "\033[48;5;8m";
const std::string buFor = "\033[38;5;7m";

//farmland
const std::string flBkg = "\033[48;5;94m";
const std::string flFor = "\033[38;5;11m";

//dirt
const std::string diBkg = "\033[48;5;94m";

//boulder
const std::string bFor = "\033[38;5;8m";

//magic ice
const std::string iFor = "\033[38;5;15m";

//seeds
const std::string sFor = "\033[38;5;22m";

//fire
const std::string fFor = "\033[38;5;9m";

//water
const std::string wFor = "\033[38;5;12m";

//heal
const std::string hFor = "\033[38;5;9m";

//ent
const std::string eFor = "\033[38;5;22m";



//misc backgrounds
const std::string redBkg = "\033[48;5;9m";
const std::string greenBkg = "\033[48;5;10m";

#endif
