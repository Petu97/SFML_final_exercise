#include "Object.h"
#include <iostream>


class Player : public Object
{
	using Object::Object;
public:
	sf::Vector2f playerpos;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirN;
};
