#ifndef TILE_H
#define TILE_H

class Tile {
private :
	int x, y; //coordinate 
	int adjacent; //the amount of adjacent bomb
	bool veiled = true; //haven't beeing press
	bool mark = false; //right click thinggy

public :
	Tile();
	Tile(int x, int y);
	void getAdj(int val);
	int reAdjValue();
	bool getVeiledState();
	bool getMark(); //being marked or not 
	void swapVeiledState(); //mostly for unveiled 
	void changeMark(); //mark or unmark that tile 
};


#endif