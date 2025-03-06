#include "Monster.h"
#include <random>
#include <iostream>
#include <vector>
using namespace std;


void Monster::setID(int id) { id = id; }
int Monster::getID() { return id; }
void Monster::set_heighFrame(int heigh) { heighFrame = heigh; }
int Monster::get_heighFrame() { return heighFrame; }
void Monster::set_widthFrame(int width) { widthFrame = width; }
int Monster::get_widthFrame() { return widthFrame; }

void Monster::Random(int start,int end) {
    random_device rd;  // ใช้ entropy จริง (ถ้ามี)
    mt19937 gen(rd()); // Mersenne Twister (ตัวสร้างเลขสุ่มที่ดี)
    uniform_int_distribution<int> dist(start, end); // สุ่มเลข 1-100

    int roll = dist(gen);
    if (roll <= 60) {  
        id = 1;
        cout << "Random : 1" <<endl;
    }
    else if(roll <= 80 ){
        id = 2;
        cout << "Random :2 " <<endl;
    }
    else {
        id = 3;
        cout << "Random : 3" << endl;
    }

    

}

void Monster::setRect(int x, int y, int width, int heigh) {

    sprite.setTextureRect(sf::IntRect(x, y, width, heigh));
}