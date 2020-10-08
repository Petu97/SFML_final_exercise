#include "Object.h"
#include <iostream>

//function for setting up sprite
bool Object::loadSprite(const std::string& str, sf::IntRect IRe)
{
    if (!texture.loadFromFile(str))
        return -1;

    texture.loadFromFile(str, IRe);
    sprite.setTexture(texture);
    return true;
}

//override function for sfml draw
void Object::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite);
}

//constructor for setting up health for objects
Object::Object(int initialHealth)
{
    this->health = initialHealth;
}

void Object::CheckHealth()
{
    if (this->health <= 0)
		this->isAlive = false;
}

void Object::CheckForUnitCollision(Object object)
{
	if (sprite.getGlobalBounds().intersects(object.sprite.getGlobalBounds()))
	{
		health -= 1;
		if (health <= 0)
		{
			isAlive = false;
		}
	}
}

