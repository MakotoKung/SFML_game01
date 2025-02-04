#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <Vector>

class Player : public Entity {
	private: 
		sf::IntRect allowedArea;
	public:
		Player(const sf::Vector2i& startPos,const sf::IntRect& area) :allowedArea(area) {
			SetPosition(startPos);
		}
		void Movement();

		
};

#endif