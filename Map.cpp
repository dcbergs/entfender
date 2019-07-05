/****************************************************************
 * Program name:	Entfender, Map.cpp
 * Author:		Dylan Bergschneider
 * Date:		5/30/2019
 * Description:		Contains a map of Space objects in a grid
 ***************************************************************/

#include "Map.hpp"
#include "OldGrowth.hpp"
#include "Successional.hpp"
#include "River.hpp"
#include "Dirt.hpp"
#include "Highway.hpp"
#include "Farm.hpp"
#include "Building.hpp"
#include "Colors.hpp"
#include "Boulder.hpp"
#include "MagicIce.hpp"
#include "Seeds.hpp"
#include "Fire.hpp"
#include "Water.hpp"
#include "Heal.hpp"

#include <iostream>
#include <stdlib.h>

/*************************************
 * MAP CODES
 * o = old growth	s = successional
 * r = river		h = highway
 * b = building		f = farm
 * d = dirt
 ************************************/

Map::Map(int levelNumber){

	//a grid of symbols to make level design a bit easier
	std::string symbols[20];
	switch(levelNumber){

		case 1:
			{
			symbols[0] =  "ddddddddddddrddddsssoooooooooo";
			symbols[1] =  "dddssdddddddrdddddddddssoooooo";
			symbols[2] =  "dddssdddddddrrrddddddddssooooo";
			symbols[3] =  "ddddddddddddddrdddddddssoooooo";
			symbols[4] =  "ddfhfdfffffffdrddddddddsssssoo";
			symbols[5] =  "dddhbdfffffdddrddddddddddsssoo";
			symbols[6] =  "ffdhdfffffddddrrrddddddddddsso";
			symbols[7] =  "fddhdffffdffdffdrrrdddddddddss";
			symbols[8] =  "fddhdddffffffffffdrdddddddsooo";
			symbols[9] =  "dddhfffffffsfffffdrddddddddsoo";
			symbols[10] = "ddbhbdbdbdffffffdrrrdddddddddo";
			symbols[11] = "dhhhhhhhhdfffsffdrdrrddddddddd";
			symbols[12] = "ddbhbdddbffdfffdrrddrrrrrrdddd";
			symbols[13] = "dddhhhhhhffffffdrddddddddrdddd";
			symbols[14] = "dddhdddddffffdrrrddsssdddrrddd";
			symbols[15] = "dddhdddbdffddfrdddssoosdddrrdd";
			symbols[16] = "dddhhhhhhhbsrrrddddoooosdddrdd";
			symbols[17] = "sddddddddhhhhhhhdffffodsdddrdd";
			symbols[18] = "sssdddddddddrrrhhhhhhhhddddrrr";
			symbols[19] = "ssssdddddddddfrrddddbfdddddddd";
			}
			break;
		default:
			{
			symbols[0] =  "ddddddffffddddddrdddssssssoooo";
			symbols[1] =  "ddddddffffddddddrdddssssssoooo";
			symbols[2] =  "ddddddffffddddddrdddssssssoooo";
			symbols[3] =  "ddddddffffddddddrdddssssssoooo";
			symbols[4] =  "ddddddffffddddddrdddssssssoooo";
			symbols[5] =  "ddddddffffddddddrdddssssssoooo";
			symbols[6] =  "ddddddffffddddddrdddssssssoooo";
			symbols[7] =  "ddddddffffddddddrdddssssssoooo";
			symbols[8] =  "ddddddffffddddddrdddssssssoooo";
			symbols[9] =  "ddddddffffddddddrdddssssssoooo";
			symbols[10] = "ddddddffffddddddrdddssssssoooo";
			symbols[11] = "ddddddffffddddddrdddssssssoooo";
			symbols[12] = "ddddddffffddddddrdddssssssoooo";
			symbols[13] = "ddddddffffddddddrdddssssssoooo";
			symbols[14] = "ddddddffffddddddrdddssssssoooo";
			symbols[15] = "ddddddffffddddddrdddssssssoooo";
			symbols[16] = "ddddddffffddddddrdddssssssoooo";
			symbols[17] = "ddddddffffddddddrdddssssssoooo";
			symbols[18] = "ddddddffffddddddrdddssssssoooo";
			symbols[19] = "ddddddffffddddddrdddssssssoooo";
			}
			break;

	}


	//convert the string grid to an actual map
	//first, a grid of blank Space pointers
	grid = new Space**[20];
	for(int i = 0; i < 20; i++){
		grid[i] = new Space*[30];
	}

	/*************************************
	 * MAP CODES
	 * o = old growth	s = successional
	 * r = river		h = highway
	 * b = building		f = farm
	 * d = dirt
	 ************************************/

	//now iterate through each row and create new derived space pointers
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 30; j++){
			if(symbols[i].at(j) == 'o'){
				grid[i][j] = new OldGrowth();
			}
			else if(symbols[i].at(j) == 's'){
				grid[i][j] = new Successional();
			}
			else if(symbols[i].at(j) == 'r'){
				grid[i][j] = new River();
			}
			else if(symbols[i].at(j) == 'b'){
				grid[i][j] = new Building();
			}
			else if(symbols[i].at(j) == 'h'){
				grid[i][j] = new Highway();
			}
			else if(symbols[i].at(j) == 'f'){
				grid[i][j] = new Farm();
			}
			else{
				grid[i][j] = new Dirt();
			}
		}
	}

	countTiles();
	linker();


}


int Map::startEntRow(int levelNumber){

	switch(levelNumber){

		case 1:
			return 5;
			break;
		default:
			return 15;
			break;
	}
}


int Map::startEntColumn(int levelNumber){

	switch(levelNumber){

		case 1:
			return 25;
			break;
		default:
			return 15;
			break;
	}
}

//counts human vs ent vs neutral tiles
void Map::countTiles(){

	humanTiles = 0;
	neutralTiles = 0;
	entTiles = 0;

	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 30; j++){
			if(grid[i][j]->getSpaceID() == 0){
				entTiles++;
			}
			else if(grid[i][j]->getSpaceID() == 1){
				neutralTiles++;
			}
			else if(grid[i][j]->getSpaceID() == 2){
				neutralTiles++;
			}
			else if(grid[i][j]->getSpaceID() == 3){
				neutralTiles++;
			}
			else if(grid[i][j]->getSpaceID() == 4){
				humanTiles++;
			}
			else if(grid[i][j]->getSpaceID() == 5){
				humanTiles++;
			}
			else if(grid[i][j]->getSpaceID() == 6){
				humanTiles++;
			}
		}
	}
}

int Map::getHumanTiles(){

	return humanTiles;
}

int Map::getEntTiles(){

	return entTiles;
}

void Map::linker(){

	//top and bottom linkers
	for(int j = 0; j < 30; j++){
		grid[0][j]->setTop(nullptr);
		grid[0][j]->setBottom(grid[1][j]);
	}
	for(int i = 1; i < 19; i++){
		for(int j = 0; j < 30; j++){
			grid[i][j]->setTop(grid[i - 1][j]);
			grid[i][j]->setBottom(grid[i + 1][j]);
		}
	}
	for(int j = 0; j < 30; j++){
		grid[19][j]->setTop(grid[18][j]);
		grid[19][j]->setBottom(nullptr);
	}

	//left and right linkers
	for(int i = 0; i < 20; i++){
		grid[i][0]->setLeft(nullptr);
		grid[i][0]->setRight(grid[i][1]);
	}
	for(int i = 0; i < 20; i++){
		for(int j = 1; j < 29; j++){
			grid[i][j]->setLeft(grid[i][j - 1]);
			grid[i][j]->setRight(grid[i][j + 1]);
		}
	}
	for(int i = 0; i < 20; i++){
		grid[i][29]->setLeft(grid[i][28]);
		grid[i][29]->setRight(nullptr);
	}
}


Map::~Map(){

	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 30; j++){
			delete grid[i][j];
		}
		delete[] grid[i];
	}
	delete[] grid;
	grid = nullptr;
}

void Map::growthSim(){

	int actions = 8;

	for(int i = 0; i < actions; i++){
		//select a random tile to do an action
		int randRow = rand() % 20;
		int randColumn = rand() % 30;
		if(grid[randRow][randColumn]->getSpaceID() == 4){
			spreadHighway(randRow, randColumn);
		}
		else if(grid[randRow][randColumn]->getSpaceID() == 5){
			spreadBuilding(randRow, randColumn);
		}
		else if(grid[randRow][randColumn]->getSpaceID() == 6){
			spreadFarm(randRow, randColumn);
		}
	}
	countTiles();
}

void Map::spreadFarm(int row, int column){

	//first, Farm can spread farm or road
	bool farm = true;
	if((rand() % 100) <= 9){
		farm = false;
	}
	int randNeighbor = grid[row][column]->getRandomNeighbor();
	switch(randNeighbor){

		case 0:
			if(grid[row - 1][column]->getSpaceID() != 2){
				Space* ptr = grid[row][column]->getTop();
				if(farm)
					grid[row - 1][column] = new Farm();
				else
					grid[row - 1][column] = new Highway();
				delete ptr;
			}
			break;
		case 1:
			if(grid[row][column + 1]->getSpaceID() != 2){
				Space* ptr = grid[row][column]->getRight();
				if(farm)
					grid[row][column + 1] = new Farm();
				else
					grid[row][column + 1] = new Highway();
				delete ptr;
			}
			break;
		case 2:
			if(grid[row + 1][column]->getSpaceID() != 2){
				Space* ptr = grid[row][column]->getBottom();
				if(farm)
					grid[row + 1][column] = new Farm();
				else
					grid[row + 1][column] = new Highway();
				delete ptr;
			}
			break;
		case 3:
			if(grid[row][column - 1]->getSpaceID() != 2){
				Space* ptr = grid[row][column]->getLeft();
				if(farm)
					grid[row][column - 1] = new Farm();
				else
					grid[row][column - 1] = new Highway();
				delete ptr;
			}
			break;
	}
	linker();
}

void Map::spreadHighway(int row, int column){

	//first, Highway can spread highway (4), building (5), or farm (6)
	int type = 5;
	if(grid[row][column]->hasNeighbor(5)){
		//building or road
		if((rand() % 100) <= 49){
			type--;
		}
	}
	else{
		//road or farm
		if((rand() % 100) <= 39){
			type--;
		}
		else{
			type++;
		}
	}
	int randNeighbor = grid[row][column]->getRandomNeighbor();
	switch(randNeighbor){

		//note that it's also checking for rivers (only highway can be built on river)
		case 0:
			if(type == 4 || grid[row - 1][column]->getSpaceID() != 2){
				Space* ptr = grid[row][column]->getTop();
				if(type == 4)
					grid[row - 1][column] = new Highway();
				else if(type == 5)
					grid[row - 1][column] = new Building();
				else
					grid[row - 1][column] = new Farm();
				delete ptr;
			}
			break;
		case 1:
			if(type == 4 || grid[row][column + 1]->getSpaceID() != 2){
				Space* ptr = grid[row][column]->getRight();
				if(type == 4)
					grid[row][column + 1] = new Highway();
				else if(type == 5)
					grid[row][column + 1] = new Building();
				else
					grid[row][column + 1] = new Farm();
				delete ptr;
			}
			break;
		case 2:
			if(type == 4 || grid[row + 1][column]->getSpaceID() != 2){
				Space* ptr = grid[row][column]->getBottom();
				if(type == 4)
					grid[row + 1][column] = new Highway();
				else if(type == 5)
					grid[row + 1][column] = new Building();
				else 
					grid[row + 1][column] = new Farm();
				delete ptr;
			}
			break;
		case 3:
			if(type == 4 || grid[row][column - 1]->getSpaceID() != 2){
				Space* ptr = grid[row][column]->getLeft();
				if(type == 4)
					grid[row][column - 1] = new Highway();
				else if(type == 5)
					grid[row][column - 1] = new Building();
				else
					grid[row][column - 1] = new Farm();
				delete ptr;
			}
			break;
	}
	linker();
}

void Map::spreadBuilding(int row, int column){

	//first, Building can spread building or road
	bool building = true;
	if((rand() % 100) <= 49){
		building = false;
	}
	int randNeighbor = grid[row][column]->getRandomNeighbor();
	switch(randNeighbor){

		case 0:
			if(grid[row - 1][column]->getSpaceID() != 2){
				Space* ptr = grid[row][column]->getTop();
				if(building)
					grid[row - 1][column] = new Building();
				else
					grid[row - 1][column] = new Highway();
				delete ptr;
			}
			break;
		case 1:
			if(grid[row][column + 1]->getSpaceID() != 2){
				Space* ptr = grid[row][column]->getRight();
				if(building)
					grid[row][column + 1] = new Building();
				else
					grid[row][column + 1] = new Highway();
				delete ptr;
			}
			break;
		case 2:
			if(grid[row + 1][column]->getSpaceID() != 2){
				Space* ptr = grid[row][column]->getBottom();
				if(building)
					grid[row + 1][column] = new Building();
				else
					grid[row + 1][column] = new Highway();
				delete ptr;
			}
			break;
		case 3:
			if(grid[row][column - 1]->getSpaceID() != 2){
				Space* ptr = grid[row][column]->getLeft();
				if(building)
					grid[row][column - 1] = new Building();
				else
					grid[row][column - 1] = new Highway();
				delete ptr;
			}
			break;
	}
	linker();
}

void Map::useItem(Item* item, int row, int column){

	//boulder
	if(item->getItemID() == 0){
		//need to find adjacent buildings
		std::set<std::pair<int, int>> adjacents;
		grid[row][column]->findAdjacents(adjacents, 5, row, column);
		for(auto i = adjacents.begin(); i != adjacents.end(); i++){
			Space* ptr = grid[i->first][i->second];
			grid[i->first][i->second] = new Dirt();
			delete ptr;
		}
	}
	//magic ice
	if(item->getItemID() == 1){
		//need to find adjacent road
		std::set<std::pair<int, int>> adjacents;
		grid[row][column]->findAdjacents(adjacents, 4, row, column);
		for(auto i = adjacents.begin(); i != adjacents.end(); i++){
			Space* ptr = grid[i->first][i->second];
			grid[i->first][i->second] = new Dirt();
			delete ptr;
		}
	}
	//Seeds
	if(item->getItemID() == 2){
		//need to find adjacent dirt
		std::set<std::pair<int, int>> adjacents;
		grid[row][column]->findAdjacents(adjacents, 3, row, column);
		for(auto i = adjacents.begin(); i != adjacents.end(); i++){
			Space* ptr = grid[i->first][i->second];
			grid[i->first][i->second] = new Successional();
			delete ptr;
		}
	}
	//Fire
	if(item->getItemID() == 3){
		//need to find adjacent farms
		std::set<std::pair<int, int>> adjacents;
		grid[row][column]->findAdjacents(adjacents, 6, row, column);
		for(auto i = adjacents.begin(); i != adjacents.end(); i++){
			Space* ptr = grid[i->first][i->second];
			grid[i->first][i->second] = new Dirt();
			delete ptr;
		}
	}
	//Water
	if(item->getItemID() == 4){
		//floods a random direction of tiles?
		std::set<std::pair<int, int>> adjacents;
		//probably need a different function for that:
		grid[row][column]->findLine(adjacents, 3, row, column);
		for(auto i = adjacents.begin(); i != adjacents.end(); i++){
			Space* ptr = grid[i->first][i->second];
			grid[i->first][i->second] = new River();
			delete ptr;
		}
	}
	//Heal
	if(item->getItemID() == 5){
		//nothing happens to map, but ent heals
	}
	linker();
}

void Map::ageStep(){

	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 30; j++){
			//age tiles, which in turn handles items disappearing
			grid[i][j]->incAge();
			//check if successional forests need to grow
			if(grid[i][j]->getSpaceID() == 1 && grid[i][j]->getAge() >= 50){
				Space* ptr = grid[i][j];
				grid[i][j] = new OldGrowth();
				delete ptr;
			}
		}
	}
}

void Map::addItem(){

	int row = randomRow();
	int column = randomColumn();

	//theoretically infinite loop if map is full, but
	//items only last 15 steps and at most are generated
	//one per turn
	while(grid[row][column]->getItem() != nullptr){

		row = randomRow();
		column = randomColumn();
	}

	int which = (rand() % 6);
	switch(which){
		case 0:
			grid[row][column]->setItem(new Boulder());
			break;
		case 1:
			grid[row][column]->setItem(new MagicIce());
			break;
		case 2:
			grid[row][column]->setItem(new Seeds());
			break;
		case 3:
			grid[row][column]->setItem(new Fire());
			break;
		case 4:
			grid[row][column]->setItem(new Water());
			break;
		case 5:
			grid[row][column]->setItem(new Heal());
			break;
	}
}

int Map::randomRow(){
	return (rand() % 20);
}
int Map::randomColumn(){
	return (rand() % 30);
}


bool Map::isItem(int row, int column){

	if(grid[row][column]->getItem() != nullptr){
		return true;
	}
	return false;
}

//use isItem first
Item* Map::getItem(int row, int column){

	return grid[row][column]->getItem();
}

//removes item for ent to have, does not delete it
void Map::removeItem(int row, int column){

	grid[row][column]->removeItem();
}

//deletes item, use for when item times out
void Map::deleteItem(int row, int column){

	grid[row][column]->deleteItem();

}



bool Map::isOG(int row, int column){

	bool oldGrowth = false;
	if(grid[row][column]->getSpaceID() == 0){
		oldGrowth = true;
	}
	return oldGrowth;
}


//draws background only of a tile (in case the ent is there)
void Map::bkg(int row, int column){
	grid[row][column]->setBkg();
}

//draws full tile 
void Map::draw(int row, int column){
	grid[row][column]->draw();
}





