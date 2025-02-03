#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <Vector>

class Player : public Entity {
	
	public:
		Player(const sf::Vector2i& startPos) {
			SetPosition(startPos);
		}
		void Movement();

		
};

#endif