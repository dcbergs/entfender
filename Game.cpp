/*************************************************
 * Program name:	Entfender, Game.cpp
 * Author:		Dylan Bergschneider
 * Date:		6/3/2019
 * Description:		holds a Map and Ent object,
 * 			runs the game loop.
 ************************************************/

#include <iostream>
#include <string>

#include "Game.hpp"
#include "Map.hpp"
#include "Ent.hpp"
#include "Colors.hpp"
#include "Sprites.hpp"
#include "InputVal.hpp"
#include "Item.hpp"



Game::Game(){

	map = new Map(1);
	ent = new Ent(map->startEntRow(1), map->startEntColumn(1));
}

Game::~Game(){

	delete map;
	delete ent;

}

std::string Game::iterate(){

	bool invalid = false;
	char input;
	bool gameOver = false;
	std::string message;

	while(!gameOver){

		//first, draw the current map
		draw();

		//check win/lose conditions related to tile coverage
		if(map->getHumanTiles() == 0){
			gameOver = true;
			message = "You have returned the forests to glory!";
		}
		else if(map->getEntTiles() == 0){
			gameOver = true;
			message = "The humans have cut down the very last tree!";
		}

		//GET USER INPUT
		if(!gameOver){
			do{
				invalid = false;
				//get input
				input = wasd15();
				if(input == 'z'){
					invalid = true;
				}

				//make sure this input can do something
				if(!ent->canDo(input)){
					invalid = true;
				}
				if(invalid){
					//redraw map
					draw();
					std::cout << "Invalid input. Use WASD + enter to move or 1 through 5 + enter for items." << std::endl;
				}

			}while(invalid);

			//QUIT IF INPUT IS 'L'
			if(input == 'l'){
				gameOver = true;
				message = "You have abandoned the forest to destruction by humans!";
			}
		}

		//MOVE THE ENT OR USE ITEM
		if(!gameOver){
			if(input == 'w' || input == 'a' || input == 's' || input == 'd'){
				ent->action(input);
			}
			else if(input == '1' || input == '2' || input == '3' || input == '4' || input == '5'){
				if(ent->getItem(input)->getItemID() == 5){
					//heal ent
					ent->healEnt();
				}
				else{
					map->useItem(ent->getItem(input), ent->getRow(), ent->getColumn());
				}
				ent->removeItem(input - '0' - 1);
			}

			//if ent is now on item slot, pick it up
			if(map->isItem(ent->getRow(), ent->getColumn())){
				if(ent->hasSpace()){
					ent->putItem(map->getItem(ent->getRow(), ent->getColumn()));
					map->removeItem(ent->getRow(), ent->getColumn());
				}
			}
			

			//lose HP if not on old-growth tile
			if(!map->isOG(ent->getRow(), ent->getColumn())){
				ent->takeDamage();
				if(ent->getHealth() <= 0){
					gameOver = true;
					message = "You have died!";
				}
			}

		}

		//now random map tiles grow, if you haven't died
		if(!gameOver){

			map->growthSim();
			//also a chance to add an item
			int itemAdd = (rand() % 100);
			if(itemAdd <= 99){
				map->addItem();
			}

			//also everything ages a day (successional forests grow, items disappear)
			map->ageStep();
			
		}
	}
	return message;
}

int Game::randomRow(){
	return (rand() % 20);
}
int Game::randomColumn(){
	return (rand() % 30);
}

void Game::draw(){

	//clear console
	for(int i = 0; i < 40; i++){
		std::cout << std::endl;
	}

	//row 0
	for(int j = 0; j < 30; j++){
		if(ent->isOn(0, j)){
			map->bkg(0, j);
			ent->draw();
		}
		else{
			map->draw(0, j);
		}
	}
	std::cout << default1 << "        Entfender";
	std::cout << default1 << "          \u2502 KEY" << std::endl;
	//row 1
	for(int j = 0; j < 30; j++){
		if(ent->isOn(1, j)){
			map->bkg(1, j);
			ent->draw();
		}
		else{
			map->draw(1, j);
		}
	}
	std::cout << default1 << "                           \u2502 Terrain:";
	std::cout << default1 << std::endl;

	//row 2
	for(int j = 0; j < 30; j++){
		if(ent->isOn(2, j)){
			map->bkg(2, j);
			ent->draw();
		}
		else{
			map->draw(2, j);
		}
	}
	std::cout << default1 << "  HP: ";
	ent->drawHP();
	std::cout << default1 << "   \u2502 ";
	std::cout << ogBkg << ogFor << dark << default1;
	std::cout << " Old Growth Forest";
	std::cout << default1 << std::endl;

	//row 3
	for(int j = 0; j < 30; j++){
		if(ent->isOn(3, j)){
			map->bkg(3, j);
			ent->draw();
		}
		else{
			map->draw(3, j);
		}
	}
	std::cout << default1 << "                           \u2502 ";
	std::cout << sfBkg << sfFor << light << default1;
	std::cout << " Successional Forest";
	std::cout << default1 << std::endl;

	//row 4
	for(int j = 0; j < 30; j++){
		if(ent->isOn(4, j)){
			map->bkg(4, j);
			ent->draw();
		}
		else{
			map->draw(4, j);
		}
	}
	std::cout << default1 << "         INVENTORY";
	std::cout << "         \u2502 ";
	std::cout << fwBkg << " " << default1;
	std::cout << " River";
	std::cout << default1 << std::endl;

	//row 5
	for(int j = 0; j < 30; j++){
		if(ent->isOn(5, j)){
			map->bkg(5, j);
			ent->draw();
		}
		else{
			map->draw(5, j);
		}
	}
	std::cout << default1 << "  " << invBoxTop;
	std::cout << "   \u2502 ";
	std::cout << diBkg << " " << default1;
	std::cout << " Dirt";
	std::cout << default1 << std::endl;

	//row 6
	for(int j = 0; j < 30; j++){
		if(ent->isOn(6, j)){
			map->bkg(6, j);
			ent->draw();
		}
		else{
			map->draw(6, j);
		}
	}
	std::cout << default1 << "  \u2502  1) ";
	if(ent->isItem(0)){
		std::cout << ent->getItem(0)->getItemString();
	}
	else{
		std::cout << "               ";
	}
	std::cout << "\u2502";
	std::cout << "   \u2502 ";
	std::cout << hwBkg << " " << default1;
	std::cout << " Road";
	std::cout << default1 << std::endl;

	//row 7
	for(int j = 0; j < 30; j++){
		if(ent->isOn(7, j)){
			map->bkg(7, j);
			ent->draw();
		}
		else{
			map->draw(7, j);
		}
	}
	std::cout << default1 << "  \u2502  2) ";
	if(ent->isItem(1)){
		std::cout << ent->getItem(1)->getItemString();
	}
	else{
		std::cout << "               ";
	}
	std::cout << "\u2502";
	std::cout << "   \u2502 ";
	std::cout << buBkg << buFor << buSpr << default1;
	std::cout << " Building";
	std::cout << default1 << std::endl;

	//row 8
	for(int j = 0; j < 30; j++){
		if(ent->isOn(8, j)){
			map->bkg(8, j);
			ent->draw();
		}
		else{
			map->draw(8, j);
		}
	}
	std::cout << default1 << "  \u2502  3) ";
	if(ent->isItem(2)){
		std::cout << ent->getItem(2)->getItemString();
	}
	else{
		std::cout << "               ";
	}
	std::cout << "\u2502";
	std::cout << "   \u2502 ";
	std::cout << flBkg << flFor << light << default1;
	std::cout << " Farm";
	std::cout << default1 << std::endl;

	//row 9
	for(int j = 0; j < 30; j++){
		if(ent->isOn(9, j)){
			map->bkg(9, j);
			ent->draw();
		}
		else{
			map->draw(9, j);
		}
	}
	std::cout << default1 << "  \u2502  4) ";
	if(ent->isItem(3)){
		std::cout << ent->getItem(3)->getItemString();
	}
	else{
		std::cout << "               ";
	}
	std::cout << "\u2502";
	std::cout << "   \u2502 Items:";
	std::cout << default1 << std::endl;

	//row 10
	for(int j = 0; j < 30; j++){
		if(ent->isOn(10, j)){
			map->bkg(10, j);
			ent->draw();
		}
		else{
			map->draw(10, j);
		}
	}
	std::cout << default1 << "  \u2502  5) ";
	if(ent->isItem(4)){
		std::cout << ent->getItem(4)->getItemString();
	}
	else{
		std::cout << "               ";
	}
	std::cout << "\u2502";
	std::cout << "   \u2502 ";
	std::cout << bFor << bSpr << default1;
	std::cout << " Boulder (destroys buildings)";
	std::cout << default1 << std::endl;


	//row 11
	for(int j = 0; j < 30; j++){
		if(ent->isOn(11, j)){
			map->bkg(11, j);
			ent->draw();
		}
		else{
			map->draw(11, j);
		}
	}
	std::cout << default1 << "  " << invBoxBot;
	std::cout << "   \u2502 ";
	std::cout << iFor << iSpr << default1;
	std::cout << " Magic Ice (destroys roads)";
	std::cout << default1 << std::endl;

	//row 12
	for(int j = 0; j < 30; j++){
		if(ent->isOn(12, j)){
			map->bkg(12, j);
			ent->draw();
		}
		else{
			map->draw(12, j);
		}
	}
	std::cout << default1 << "                           \u2502 ";
	std::cout << sFor << sSpr << default1;
	std::cout << " Seeds (plants a forest in dirt)";
	std::cout << default1 << std::endl;

	//row 13
	for(int j = 0; j < 30; j++){
		if(ent->isOn(13, j)){
			map->bkg(13, j);
			ent->draw();
		}
		else{
			map->draw(13, j);
		}
	}
	std::cout << default1 << "                           \u2502 ";
	std::cout << fFor << fSpr << default1;
	std::cout << " Fire (burns down a farm)";
	std::cout << default1 << std::endl;

	//row 14
	for(int j = 0; j < 30; j++){
		if(ent->isOn(14, j)){
			map->bkg(14, j);
			ent->draw();
		}
		else{
			map->draw(14, j);
		}
	}
	std::cout << default1 << "                           \u2502 ";
	std::cout << wFor << wSpr << default1;
	std::cout << " Water (floods a tile)";
	std::cout << default1 << std::endl;

	//row 15
	for(int j = 0; j < 30; j++){
		if(ent->isOn(15, j)){
			map->bkg(15, j);
			ent->draw();
		}
		else{
			map->draw(15, j);
		}
	}
	std::cout << default1 << "                           \u2502 ";
	std::cout << hFor << hSpr << default1;
	std::cout << " Heal (heals the ent)";
	std::cout << default1 << std::endl;

	//row 16
	for(int j = 0; j < 30; j++){
		if(ent->isOn(16, j)){
			map->bkg(16, j);
			ent->draw();
		}
		else{
			map->draw(16, j);
		}
	}
	std::cout << default1 << std::endl;

	//row 17
	for(int j = 0; j < 30; j++){
		if(ent->isOn(17, j)){
			map->bkg(17, j);
			ent->draw();
		}
		else{
			map->draw(17, j);
		}
	}
	std::cout << default1 << std::endl;

	//row 18
	for(int j = 0; j < 30; j++){
		if(ent->isOn(18, j)){
			map->bkg(18, j);
			ent->draw();
		}
		else{
			map->draw(18, j);
		}
	}
	std::cout << default1 << std::endl;

	//row 19
	for(int j = 0; j < 30; j++){
		if(ent->isOn(19, j)){
			map->bkg(19, j);
			ent->draw();
		}
		else{
			map->draw(19, j);
		}
	}
	std::cout << default1 << std::endl;


	std::cout << default1 << std::endl;

}
