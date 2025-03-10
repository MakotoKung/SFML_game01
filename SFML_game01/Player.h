#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <Vector>

class Player : public Entity {
	private: 
		sf::IntRect allowedArea;
		float acc ;
		float stamina;
		float Time;
		int Score;
	public:
		Player(float a,float s,const sf::Vector2i& startPos,const sf::IntRect& area,int,const sf::Vector2i& Size) :allowedArea(area) {
			
			SetPosition(startPos);
			acc = static_cast<float>(a);
			stamina = s;

		}
		~Player() {
			std::cout << "\nObject delete";
		}
		void Movement();
		float getStamina();
		void setTime(float);
		float getTime();
		void setScore(int);
		int getScore();
		bool isCollision(const sf::Sprite& obj1, const sf::Sprite& obj2);
		

		
};

#endif