#include<iostream>

#include "Utility.h"
#include "Table.h"
#include "Bomb.h"
#include "Tile.h"

Table::Table() {
	this->rows = 0;
	this->columns = 0;
};

Table::Table(int rows, int columns, int bombs) {
	this->rows = rows;
	this->columns = columns;

	this->Bombs.resize(rows * columns);
	this->Tiles.resize(rows * columns);

	this->genTile(bombs);
}

void Table::drawTable() {
	std::cout << "   ";
	for (int i = 0; i < this->columns; i++) {
		std::cout << i << ' ';
	}
	std::cout << "\n\n";
	for (int i = 0; i < this->rows; i++) {
		std::cout << i << "  ";
		for (int j = 0; j < this->columns; j++) {
			int pos = i * columns + j;


			if (this->checkMarked(i, j)) {
				std::cout << "? ";
				continue;
			}
			else if (this->checkVeiled(i, j)) {
				std::cout << "# ";
				continue;
			}

			if (this->Bombs[pos].checkViable()) {
				std::cout << this->Tiles[pos].reAdjValue() << " ";
			}
			else {std::cout << "B ";}
		}
		std::cout << '\n';
	}
	for (int i = 0; i < 3; i++) {
		std::cout << '\n';
	}
}

void Table::genTile(int bombs) {
	while (bombs) {
		int x = getRand(0, this->rows - 1);
		int y = getRand(0, this->columns - 1);
		//std::cerr << x << ' ' << y << '\n';
		int pos = x * columns + y;
		if (this->Bombs[pos].checkViable()) {
			this->Bombs[pos] = Bomb(x, y);
			--bombs;
		}
	}

	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			int pos = i * columns + j;
			if (this->Bombs[pos].checkViable()) {
				this->Tiles[pos] = Tile(i, j);
				this->Tiles[pos].getAdj(this->getSurrBombs(i, j));
			}
		}
	}
}

int Table::getSurrBombs(int x, int y) {
	int ans = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (x + i < 0 || x + i >= rows || y + j < 0 || y + j >= columns) {
				continue;
			}
			int pos = (x + i) * columns + (y + j);
			ans += !this->Bombs[pos].checkViable();
		}
	}
	return ans;
}

bool Table::checkVeiled(int x, int y) {
	int pos = x * columns + y;
	if (this->Bombs[pos].checkViable()) {
		return this->Tiles[pos].getVeiledState();
	}
	return this->Bombs[pos].getVeiledState();
}

bool Table::checkMarked(int x, int y) {
	int pos = x * columns + y;
	if (this->Bombs[pos].checkViable()) {
		return this->Tiles[pos].getMark();
	}
	return this->Bombs[pos].getMark();
}

std::pair<int, int> Table::getDimension() {
	return std::pair<int, int>(this->rows, this->columns);
}

void Table::openVeiled(int x, int y) {
	int pos = x * this->columns + y;
	if (this->Bombs[pos].checkViable()) {
		this->Tiles[pos].swapVeiledState();
		return;
	}
	this->Bombs[pos].swapVeiledState();
}

void Table::changeMarkState(int x, int y) {
	int pos = x * this->columns + y;
	if (this->Bombs[pos].checkViable()) {
		this->Tiles[pos].changeMark();
		return;
	}
	this->Bombs[pos].changeMark();
}