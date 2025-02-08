#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

void Player::Movement() {
	sf::Vector2i move({ 0,0 });
	float Hold = 0.05;
	float Accel = acc;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && (stamina >= 10)) { 
		acc = 1.5f; 
		stamina -= 2;
	}
	else { acc = 0.8f; }
	if (stamina <= 100) { stamina += 4 * Hold; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Position.y > allowedArea.top) {
		move.y -= 4 * acc;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Position.y < allowedArea.top + allowedArea.height - 1) {
		move.y += 4 * acc;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && Position.x > allowedArea.left) {
		move.x -= 4 * acc;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && Position.x < allowedArea.left + allowedArea.width - 1) {
		move.x += 4 * acc ;
	}
	SetPosition(Position + move);
	std::cout << "\nStamina : " << stamina;
	std::cout <<"\nacc: " << acc;
	//std::cout << Position.x << " " << Position.y;

}
