#pragma once
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
class Item
{
private:
	int charges;
	string name;
	int xPos;
	int yPos;
public:

	void setCharges(int charges);
	void setName(string name);
	void setXPos(int xPos);
	void setYPos(int yPos);
	int getCharges();
	int getXPos();
	int getYPos();
	string getName();

};

