#include <SFML/Graphics.hpp>

//Käytännössä olisi fiksumpaa tehdä kaksi luokkaa Uille: kuville ja tekstille
class UI : sf::Drawable, sf::Transformable
{
public:
	//sf::Sprite sprite;
	sf::Text text;
	//For Text
	void InitializeText(int fontsize);
	void SetString(int playerhealth);
	//For pictures
	//bool InitializeSprite(std::string s);

private:
	sf::Texture texture;
	//virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

