#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

void Player::Movement() {
	
	sf::Vector2i move({ 0,0 });
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Position.y > allowedArea.top) {
		move.y -= 10;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Position.y < allowedArea.top + allowedArea.height - 1) {
		move.y += 10;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && Position.x > allowedArea.left) {
		move.x -= 10;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && Position.x < allowedArea.left + allowedArea.width - 1) {
		move.x += 10;
	}
	SetPosition(Position + move);
	//std::cout << Position.x << " " << Position.y;

}
