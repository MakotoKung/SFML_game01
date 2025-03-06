#pragma once
#ifndef MONSTER_H
#define MONSTER_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <iostream>
#include<random>

class Monster : public Entity {
	private: 
		int id;
		int heighFrame;
		int widthFrame;
		sf::IntRect Frame;

	public:
		Monster(){}
		void setID(int);
		int getID();
		void set_heighFrame(int);
		int get_heighFrame();
		void set_widthFrame(int);
		int get_widthFrame();
		void setRect(int, int, int, int);
		void Random(int,int);


};

#endif // !MONSTER_H

