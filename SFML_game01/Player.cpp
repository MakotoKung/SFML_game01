#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

void Player::Movement() {
	
	sf::Vector2i move({ 0,0 });
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		move.y -= 10;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		move.y += 10;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		move.x -= 10;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		move.x += 10;
	}
	SetPosition(Position + move);
	//std::cout << Position.x << " " << Position.y;

}
