/***********************************************************
 * Program Name:	Lab 7, Menu.hpp
 * Author:		Dylan Bergschneider
 * Date:		5/14/2019
 * Description:		Generates a menu for options passed
 * 			as an array of strings and/or ints.
 * 			Validates user selection and returns
 * 			an integer representing the choice.
 **********************************************************/


#ifndef MENU_HPP
#define MENU_HPP

//displays a menu with the given title and array of string labels as
//choices. numOptions must match the length of textLabels. Returns
//an integer corresponding to the choice (between 1 - numOptions)
int menu(std::string title, int numOptions, std::string textLabels[]);
		


#endif

