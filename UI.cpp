#include "UI.h"
#include <iostream>

//----------------------this class is not in use yet--------------------------
void UI::InitializeText(int fontsize)
{
	sf::Font font;
	font.loadFromFile("OpenSans-Bold.ttf");
	this->text.setFont(font);
	this->text.setCharacterSize(fontsize);
	this->text.setFillColor(sf::Color::White);
	this->text.setStyle(sf::Text::Bold);
}

void UI::SetString(int playerhealth)
{
	text.setString("Hitpoints :" + std::to_string(playerhealth));
}

//bool UI::InitializeSprite(std::string texturename)
//{
//	if (!texture.loadFromFile(texturename))
//	{
//		std::cout << "faled to load texture from a file" << std::endl;
//		return -1;
//	}
//	texture.loadFromFile(texturename);
//	sprite.setTexture(texture);
//	return true;
//}

//void UI::draw(sf::RenderTarget& target, sf::RenderStates states) const
//{
//	//target.draw(sprite);
//	target.draw(text);
//}