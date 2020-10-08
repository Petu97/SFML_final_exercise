#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "Object.h"

class bullet
{
public:
	sf::CircleShape shape;
	float speed;
	sf::Vector2f velocity;

	bullet(float radius = 3.f) : velocity(0.f, 0.f), speed(5.f)
	{
		this->shape.setRadius(radius);
		this->shape.setFillColor(sf::Color::White);
	}
};
