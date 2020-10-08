#pragma once
#include <SFML/Graphics.hpp>

class Object : public sf::Drawable, public sf::Transformable
{
public:
    int health = 10;
    bool isAlive = true;
    sf::Sprite sprite;
    sf::Transform transform;
    sf::Vector2f position = getPosition();

    Object(int initialHealth);
    bool loadSprite(const std::string& str, sf::IntRect IRe);
    void CheckForUnitCollision(Object object);
    void CheckHealth();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::VertexArray m_vertices;
    sf::Texture texture;
};