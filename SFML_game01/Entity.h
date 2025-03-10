#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>

class Entity  {

	protected:
		sf::Sprite sprite;
		sf::Texture texture;
		sf::Vector2i Position;
	public:
		
		int Hp;
		int damage;
		sf::RectangleShape body;
		void LoadTexture(std::string); 
		void setScale(const sf::Vector2i& scale);
		void SetPosition(const sf::Vector2i& Position);//Pos =Position reture Pos;
		void setVisible(bool visible);
		sf::Vector2i getPosition()const {
			//std::cout << std::endl << Position.x << " " << Position.y;
			return Position;
		}
		
		bool Game_Over();
		sf::FloatRect GetBounds() const;
		bool CheckCollision(const Entity& other) const;
		void Render(sf::RenderWindow& window);
			
		
};
#endif
