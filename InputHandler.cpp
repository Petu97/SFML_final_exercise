#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "MovementHandler.h"

class InputHandler
{
public:
    void GetInput(sf::Sprite& o)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            MoveChar(o, -5.f, 0.0f); //MovementHandle script
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            MoveChar(o, 5.f, 0.0f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            MoveChar(o, 0.0f, -5.f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            MoveChar(o, 0.0f, 5.f);
        }
    }
};