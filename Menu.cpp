/*********************************************************
 * Program name:	Lab 7, Menu.cpp
 * Author:		Dylan Bergschneider
 * Date:		5/14/2019
 * Description:		Runs a menu given a 
 * 			number of options and appropriate-
 * 			length arrays of string and/or
 * 			integer labels. Displays menu and
 * 			returns user selection. Depends on
 * 			InputVal.cpp for input validation.
 ********************************************************/


#include <iostream>
#include <string>

#include "InputVal.hpp"
#include "Menu.hpp"


//displays a menu with the given title and array of string labels as
//choices. numOptions must match the length of textLabels. Returns
//an integer corresponding to the choice (between 1 - numOptions)
int menu(std::string title, int numOptions, std::string textLabels[]){

	int selection = 0;
	
	std::cout << title << std::endl;
	for(int i = 0; i < numOptions; i++){
		std::cout << i + 1 << ". " << textLabels[i] << std::endl;
	}

	selection = inputIntInclusiveBound(1, numOptions);
		
	return selection;


}



