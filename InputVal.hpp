/*******************************************************************
 * Program name:	Lab 7, InputVal.hpp
 * Author:		Dylan Bergschneider
 * Date:		5/14/2019
 * Description:		Header file for InputVal.cpp which validates
 * 			integers, optionally within a given range.
 ******************************************************************/


#ifndef INPUTVAL_HPP
#define INPUTVAL_HPP

//gathers user input, ensuring it is between the given high and
//low bounds, re-prompting for valid input until given
int inputIntInclusiveBound(int loBound, int hiBound);

//gathers user input for int, but no bounds checking
int inputInt();

//gathers true/false input
bool inputBool();

//gathers string input
std::string inputString();

//gathers any, even blank, string
std::string inputAnyString();

//gets wasd or 1-5 character input for movement/item use
//returns z for invalid choice
char wasd15();

#endif

 
