/**********************************************
 * Program name:	Lab 7, InputVal.cpp
 * Author:		Dylan Bergschneider
 * Date:		5/14/2019
 * Description:		Validates that an integer is within
 * 			given low and high bounds.
 ********************************************************/

#include <iostream>
#include <string>
#include <stdexcept> //for out of range exception using stoi()

#include "InputVal.hpp"



//gathers user integer input between given low and high bounds,
//inclusive, and re-prompts for valid input when invalid input
//is supplied.
int inputIntInclusiveBound(int loBound, int hiBound){

	int input;
	std::string inputString;
	std::getline(std::cin, inputString);

	//failure conditions: any non-digit characters besides an initial - sign, fails to convert to int, int is outside of range
	bool success = true;
	for(int i = 0; i < inputString.length(); i++){
		if(!isdigit(inputString[i])){
			//make sure it's not an initial '-' character
			if(i != 0 || inputString[i] != '-'){
				success = false;
			}
		}
	}
	if(success){
		try{
			input = std::stoi(inputString);
		}
		catch(const std::out_of_range& err){
			//tried to convert a string too long for int
			success = false;
		}
		if(input < loBound || input > hiBound){
			success = false;
		}
	}

	//if failed, prompt and check again (separate from first check to only give error message
	//after the initial input)
	while(!success){
		success = true;
		std::cin.clear();
		std::cout << std::endl << "Please enter an integer between " << loBound << " and " << hiBound << ", inclusive: ";
		std::getline(std::cin, inputString);
		for(int i = 0; i < inputString.length(); i++){
			if(!std::isdigit(inputString[i])){
				//make sure it's not an initial '-' character
				if(i != 0 || inputString[i] != '-'){
					success = false;
				}
			}
		}
		if(success){
			try{
				input = std::stoi(inputString);
			}
			catch(const std::out_of_range& err){
				//tried to convert a string too long for int
				success = false;
			}
			if(input < loBound || input > hiBound){
				success = false;
			}
		}
		
	}

	return input;
}

//gathers user integer input unbounded
//and re-prompts for valid input when invalid input
//is supplied.
int inputInt(){

	int input;
	std::string inputString;
	std::getline(std::cin, inputString);

	//failure conditions: any non-digit characters, fails to convert to int, int is outside of range
	bool success = true;
	for(int i = 0; i < inputString.length(); i++){
		if(!isdigit(inputString[i])){
			//make sure it's not an initial '-' character
			if(i != 0 || inputString[i] != '-'){
				success = false;
			}
		}
	}
	if(success){
		try{
			input = std::stoi(inputString);
		}
		catch(const std::out_of_range& err){
			//tried to convert a string too long for int
			success = false;
		}
	}

	//if failed, prompt and check again (separate from first check to only give error message
	//after the initial input)
	while(!success){
		success = true;
		std::cin.clear();
		std::cout << std::endl << "Please enter an integer: ";
		std::getline(std::cin, inputString);
		for(int i = 0; i < inputString.length(); i++){
			if(!std::isdigit(inputString[i])){
				//make sure it's not an initial '-' character
				if(i != 0 || inputString[i] != '-'){
					success = false;
				}
			}
		}
		if(success){
			try{
				input = std::stoi(inputString);
			}
			catch(const std::out_of_range& err){
				//tried to convert a string too long for int
				success = false;
			}
		}
		
	}

	return input;
}

//recognizes a variety of yes/no, true/false string inputs to gather boolean input
bool inputBool(){

	bool input;
	bool valid = false;
	std::string inputString;
	std::cout << "Please enter 'Y' or 'N': ";
	std::cin >> inputString;
	std::string yesStrings[10] = {"y", "Y", "t", "T", "true", "True", "TRUE", "yes", "Yes", "YES"};
	std::string noStrings[10] = {"n", "N", "f", "F", "false", "False", "FALSE", "no", "No", "NO"};
	while(!valid){

		for(int i = 0; i < 10; i++){
			if(inputString == yesStrings[i]){
				input = true;
				valid = true;
			}
			else if(inputString == noStrings[i]){
				input = false;
				valid = true;
			}
		}
		if(!valid){
			std::cout << "Input not recognized. Please enter yes, no, true, or false: ";
			std::cin >> inputString;
		}
	}
	
	return input;
}

//gets wasd or 1-5 character input for movement/item use
//or l to leave game
//returns z for invalid choice
char wasd15(){

	std::string inputString;
	std::getline(std::cin, inputString);
	if(inputString == "w"){
		return 'w';
	}
	else if(inputString == "a"){
		return 'a';
	}
	else if(inputString == "s"){
		return 's';
	}
	else if(inputString == "d"){
		return 'd';
	}
	//the letter L
	else if(inputString == "l"){
		return 'l';
	}
	//the number 1
	else if(inputString == "1"){
		return '1';
	}
	else if(inputString == "2"){
		return '2';
	}
	else if(inputString == "3"){
		return '3';
	}
	else if(inputString == "4"){
		return '4';
	}
	else if(inputString == "5"){
		return '5';
	}
	else{
		return 'z';
	}
}



//gathers string input
std::string inputString(){
	
	std::string str = "";
	std::getline(std::cin, str);

	while(str.length() == 0){
		std::cout << "Please enter a string: ";
		std::getline(std::cin, str);
	}

	return str;

}

std::string inputAnyString(){
	std::string str;
	std::getline(std::cin, str);
	return str;
}


