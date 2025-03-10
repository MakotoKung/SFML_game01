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

void Entity::setScale(const sf::Vector2i& scale) {

	sprite.setScale(static_cast<float>(scale.x),static_cast<float>( scale.y));
}

void Entity::SetPosition(const sf::Vector2i& Pos) {
	Position = Pos;
	sprite.setPosition(static_cast<float>(Position.x), static_cast<float>(Position.y));
	body.setPosition(static_cast<float>(Position.x), static_cast<float>(Position.y));

}


bool Entity::Game_Over() {
	sf::Vector2i Window_AREA = { 1280,720 };
	if ( (Position.x >= Window_AREA.x ) || ( Position.y >= Window_AREA.y ))
	{
		return 0;
	}
	if (Hp <= 0) {
		return 0;
	}
	return 1;

	//if Hitboxmonster == player === dead;

}

void Entity::Render(sf::RenderWindow& window) {
		window.draw(sprite);
		window.draw(body);
		
}
sf::FloatRect Entity::GetBounds() const {
	return sprite.getGlobalBounds();
}

// ??????????????? Entity ????
bool Entity::CheckCollision(const Entity& other) const {
	return this->GetBounds().intersects(other.GetBounds());
}

