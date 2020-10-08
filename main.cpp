#include <SFML\Graphics.hpp>
#include <list>
#include "Tilemap.cpp"
#include "Player.cpp"
#include "InputHandler.cpp"
#include "Enemy.cpp"
#include "UI.h"
#include "Bullet.cpp"
#include <math.h>
#include <vector>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(512, 512), "Level");
    static sf::RectangleShape windowsize;
    windowsize.setSize(sf::Vector2f(512.f, 512.f));
    // define the level with an array of tile indices
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 3,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 3, 3, 0, 3,
        0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 3, 3, 3, 3, 3,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3,
        0, 0, 0, 0, 0, 0, 0, 3, 0, 3, 3, 3, 3, 3, 3, 3,
        0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,

    };
    //Objects
    TileMap map;
    InputHandler handler;
    Player player(75);          //player hitpoints
    Enemy enemy(10);            //enemy hitpoints
    bullet b1;
    sf::Vector2f mousepos;
    sf::Font font;
    sf::Text playerhp;
    sf::Text enemyhp;
    sf::Text gameEndMessage;
    //Pre
    std::vector<bullet> bullets;
    bullets.push_back(bullet(b1));
    window.setFramerateLimit(60);
    enemy.sprite.setPosition(200, 200);
    //Texts
    font.loadFromFile("OpenSans-Bold.ttf");
    playerhp.setFont(font);
    playerhp.setCharacterSize(15);
    playerhp.setFillColor(sf::Color::White);
    playerhp.setPosition(1, 480);
    gameEndMessage.setFont(font);
    gameEndMessage.setPosition(240, 240);
    enemyhp.setFont(font);
    enemyhp.setCharacterSize(15);
    enemyhp.setPosition(240, 480);

    if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 16, 15))
        return -1;
    if (!enemy.loadSprite("enemy.png", sf::IntRect(0, 0, 32, 32)))
        return -1;
    if (!player.loadSprite("player.png", sf::IntRect(0, 0, 32, 32)))
        return -1;

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(player.isAlive && enemy.isAlive)  //"game -state"
        {   //"Update" loop
            player.playerpos = sf::Vector2f(player.sprite.getPosition().x, player.sprite.getPosition().y);
            mousepos = sf::Vector2f(sf::Mouse::getPosition(window));
            player.aimDir = mousepos - player.playerpos;
            player.aimDirN = player.aimDir / sqrt(pow(player.aimDir.x, 2) + pow(player.aimDir.y, 2));
            playerhp.setString("Your Hitpoints :" + std::to_string(player.health));
            enemyhp.setString("Enemy Hitpoints :" + std::to_string(enemy.health));
            enemy.CheckHealth();
            enemy.MoveEnemy();
            handler.GetInput(player.sprite);
            player.CheckForUnitCollision(enemy);

            //needs to be moved to inputhandler
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                b1.shape.setPosition(player.playerpos);
                b1.velocity = player.aimDirN * b1.speed;
                bullets.push_back(bullet(b1));
            }
            //projectiles
            for (size_t i = 0; i < bullets.size(); i++)
            {
                bullets[i].shape.move(bullets[i].velocity);
                if (bullets[i].shape.getGlobalBounds().intersects(enemy.sprite.getGlobalBounds()))
                {
                    bullets.erase(bullets.begin() + i);
                    enemy.health -= 1;
                }
            }
        }
        else //"finished -state"
        {
            if (player.isAlive)
                gameEndMessage.setString("You won!");
            else
                gameEndMessage.setString("You lost!"); 
        }

        //Drawing
        window.clear();
        window.draw(map);
        window.draw(player);
        window.draw(enemy);
        for (size_t i = 0; i < bullets.size(); i++) //Drawing projectiles
        {
            window.draw(bullets[i].shape);
        }
        window.draw(playerhp);
        window.draw(enemyhp);
        window.draw(gameEndMessage);
        window.display();
    }

    return 0;
}

