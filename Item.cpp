#include "Item.h"
int Item::getCharges() {

	return charges;
}
string Item::getName() {
	return name;
}
void Item::setCharges(int charges) {
	this->charges = charges;
	return;
}
void Item::setName(string name) {
	this->name = name;
	return;
}
int Item::getXPos() {
	return xPos;
}
int Item::getYPos() {
	return yPos;
}
void Item::setXPos(int xPos) {
	this->xPos = xPos;
}
void Item::setYPos(int yPos) {
	this->yPos = yPos;
}