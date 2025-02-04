#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"
#include <iostream>
#include <vector>

using namespace std;

//Define variable
const int width = 1280;
const int height = 720;


int main()
{
    Player player({5,520},sf::IntRect(0,320,1220,250)); //Contructor = Position in Entity_Class x,y
    Entity Monster;
    
    //Setting 
    player.body.setFillColor(sf::Color::Transparent);
    player.body.setOutlineThickness(5.0f);
    player.body.setOutlineColor(sf::Color::Blue);
    player.body.setSize({64,128});

    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(width, height), "First Game");
    window.setFramerateLimit(60);

    //Position_Onwindow  = Map_height = height - (TILE*Map_HEIGHT) ;
    //Map_width  = (TILE *Map_WIDTH);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (player.Game_Over() == 0) {
                window.close();
            }
            
        }
        float deltatime = clock.restart().asSeconds();

        player.Movement();
        player.getPosition();
        player.Render(window);
        window.display();
        window.clear();
        
        
    }

    return 0;
}

/*----------------------------------------------------------------------------
    01/02/2568 (2.59)
    กำหนดพิกัดได้แล้วเหลือ การแสดงภาพตัวอย่างของPlayer object 
    Next do-list 
     //Complete//   - Find How to show Player object  
     //Complete//   - add movement in class Player then can move in area window
     //Complete//   - add Game_Over when movement 
     //Complete//   - Prepare space Map for Player stage 0-1200 x; y =320-520;  
*/ 

/*-----------------------------------------------------------------------------
    03/02/2568 (0.02)
    have coodinate of Enitity 
    Next to do-list 
     //Design//    -What player can do in the game
                   -Image Background, player 
                   -Find how to add animation 
                   -Random monster 
                        -Type of monster 
                        -Theame game 
        
*/