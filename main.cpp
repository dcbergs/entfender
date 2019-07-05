/*******************************************************************
 * Program name:	IDK
 * Author:		Dylan Bergschneider
 * Date:		5/29/2019
 * Description:		idk
 ******************************************************************/


#include <string>
#include <iostream>
#include <stdlib.h>

#include "Game.hpp"
#include "Colors.hpp"
#include "Menu.hpp"
#include "InputVal.hpp"

void instructions();

int main(){

	srand(time(NULL));

	bool playAgain = true;
	while(playAgain){
		std::string menuChoices[3] = {"Play", "Instructions", "Exit"};
		int play = menu("Welcome to ENTFENDER!", 3, menuChoices);
		switch(play){
			case 1:
				{
				Game game;
				std::string endMessage = game.iterate();
				std::cout << default1 << endMessage << std::endl;
				//play again?
				std::string playAgainOptions[2] = {"Yes", "No"};
				int playAgainMenu = menu("Play again?", 2, playAgainOptions);
				if(playAgainMenu == 2){
					playAgain = false;
				}
				}
				break;
			case 2:
				{
				instructions();
				}
				break;
			case 3:
				{
				playAgain = false;
				}
				break;
		}
	}

	return 0;
}


void instructions(){

	std::cout << "Welcome to Entfender!" << std::endl;
	std::cout << std::endl;
	std::cout << "You will play as an ent, defending its old-growth forests against human development." << std::endl;
	std::cout << std::endl;
	std::cout << "Move around the map using W, A, S, or D followed by enter for up, left, down, and " << std::endl;
	std::cout << "rightward movement. Collect any item by simply walking over it with free inventory " << std::endl;
	std::cout << "space. Use any item by entering its number shown your inventory (1 - 5)." << std::endl;
	std::cout << std::endl;
	std::cout << "Human settlement expands from existing buildings, roads, and farms. Though it has " << std::endl;
	std::cout << "trouble expanding across water, road tiles may span the water as bridges from nearby" << std::endl;
	std::cout << "roads. Any other tile type is an easy target for expansion!" << std::endl;
	std::cout << std::endl;
	std::cout << "There are various items for reducing specific developments to dirt. Once a tile is" << std::endl;
	std::cout << "dirt, use seeds to plant new successional forests or water to flood the tile." << std::endl;
	std::cout << "Successional forests eventually grow up into old-growth forests, which protect " << std::endl;
	std::cout << "you from the damage caused by going about the deforested countryside!" << std::endl;
	std::cout << std::endl;
	std::cout << "If the humans take out all of the old-growth forests, you lose." << std::endl;
	std::cout << "If, however, you can eliminate all of the human's developments, you win!" << std::endl;
	std::cout << std::endl;
	std::cout << "Or, if you get tired, enter the letter 'l' to quit." << std::endl;
	std::cout << std::endl;
	std::cout << "Press enter to return to the main menu." << std::endl;
	std::string dummy = inputAnyString();
}






