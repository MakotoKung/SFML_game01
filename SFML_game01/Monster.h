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

	public:
		Monster(){}
		void setID(int);
		int getID();
		void Random(int,int);


};

#endif // !MONSTER_H

