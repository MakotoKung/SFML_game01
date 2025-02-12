#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

void Player::Movement() {
	sf::Vector2i move({ 0,0 });
	float Hold = 0.05;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && (stamina >= 1)) { 
		acc = 1.5f; 
		stamina -= 2.00f;
	}
	else { acc = 0.8f;  }

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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) { 
		Hp -= 1 ; 
	}
	SetPosition(Position + move);
	//std::cout << "\nStamina : " << stamina;
	//std::cout <<"\nacc: " << acc;
	//std::cout << Position.x << " " << Position.y;

}

float Player::getStamina() { return stamina; }
void Player::setTime(float time) { Time = time; }
float Player::getTime() { return Time; }
void Player::setScore(int score) { Score += score; }
int Player::getScore() { return Score; }
