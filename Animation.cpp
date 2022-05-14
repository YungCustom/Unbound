#include "Animation.h"
Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}
Animation::~Animation() {

}
void Animation::Update(int row, float deltaTime) {
	currImage.y = row;
	totalTime += deltaTime;
	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currImage.x++;
		if (currImage.x >= imageCount.x) {
			currImage.x = 0;
		}
	}
	uvRect.left = currImage.x * uvRect.width;
	uvRect.top = currImage.y * uvRect.height;
}