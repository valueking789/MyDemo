#ifndef __TABLE_H
#define __TABLE_H


#include<vector>
#include<utility>

#include "Bomb.h"
#include "Tile.h"

class Table { //settings up the table 
private:
	int rows, columns;
	std::vector<Bomb> Bombs;
	std::vector<Tile> Tiles;

public:
	Table();
	Table(int rows, int columns, int bombs);
	void genTile(int bombs); //randomly generating the bombs and setup the number tiles
	void drawTable(); //draw the game board
	int getSurrBombs(int x, int y); //get the amount of bombs surrounding a note
	std::pair<int, int> getDimension();
	bool checkVeiled(int x, int y);
	bool checkMarked(int x, int y);
	void openVeiled(int x, int y); //after left clicking 
	void changeMarkState(int x, int y);
};

#endif 