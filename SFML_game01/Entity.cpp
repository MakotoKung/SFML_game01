#include"Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

void Entity::LoadTexture(std::string PATH) {
	
	if (!texture.loadFromFile(PATH)){
		throw std::runtime_error("Can't Load file from " + PATH);
	}
	sprite.setTexture(texture);
}

void Entity::SetPosition(const sf::Vector2i& Pos) {
	Position = Pos;
	sprite.setPosition(static_cast<float>(Position.x), static_cast<float>(Position.y));
	body.setPosition(static_cast<float>(Position.x), static_cast<float>(Position.y));

}
bool Entity::Game_Over() {
	sf::Vector2i Window_AREA = { 1280,720 };
	if ( (Position.x >= Window_AREA.x ) || ( Position.y >= Window_AREA.y ) || 
		(Position.x <= 0 ) || (Position.y <= 0) ) 
	{
		return 0;
	}


	return 1;

}

void Entity::Render(sf::RenderWindow& window) {
	window.draw(sprite);
	window.draw(body);
	window.display();
}

