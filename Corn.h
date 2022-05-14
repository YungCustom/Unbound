#include "Item.h"
#include <SFML/Graphics.hpp>
class Corn : public Item {
public:
	Corn(int xPos, int yPos);
	void useCorn();
private:
	int numUses;

};