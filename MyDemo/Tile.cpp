#include "Tile.h"

Tile::Tile() {
	this->x = -1; this->y = -1; this->adjacent = 0;
};

Tile::Tile(int x, int y) {
	this->x = x;
	this->y = y;
	this->adjacent = 0;
}

void Tile::getAdj(int val) {
	this->adjacent = val;
}

int Tile::reAdjValue() {
	return this->adjacent;
}

bool Tile::getVeiledState() {
	return this->veiled;
}

bool Tile::getMark() {
	return this->mark;
}

void Tile::swapVeiledState() {
	this->veiled = !this->veiled;
}

void Tile::changeMark() {
	this->mark = !this->mark;
}