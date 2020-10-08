#include "MovementHandler.h"
#include <iostream>


bool CheckBoundaries(sf::Sprite o)
{
	if (o.getPosition().x > 480 || o.getPosition().y > 448 || o.getPosition().x < 0 || o.getPosition().y < 0) //windowsize (512) - character size (32) = 480
		return false;
	else
		return true;
}

void MoveChar(sf::Sprite& o, float ver, float hor)
{
	sf::Vector2f oldPos = o.getPosition();
	sf::Vector2f newPos = sf::Vector2f(oldPos.x + ver, oldPos.y + hor);
	o.setPosition(newPos);
	//Check if new position is not within map area
	if (!CheckBoundaries(o))
		o.setPosition(oldPos);
}

