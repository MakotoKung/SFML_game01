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
    Player player({5,520},sf::IntRect(0,320,1220,250),3,{64,128}); //Contructor = Position in Entity_Class x,y
    Entity Monster;
    Entity SKY, CLOUD, HILL, FIELD;
    SKY.setVisible(false);
    player.setVisible(true);
    cout << player.getVisible();
    
    //Setting 
    player.body.setFillColor(sf::Color::Transparent);
    player.body.setOutlineThickness(5.0f);
    player.body.setOutlineColor(sf::Color::Blue);
    player.body.setSize({64,128});
    player.LoadTexture("D:/ALL/Anime/8a7ae09df6771a1e65adbf2c2ff2b743.png");
    
    
    
    //Backgournd 
    sf::Sprite sky;
    sf::Texture skyTex;
    skyTex.loadFromFile("Image/sky.png");
    sky.setTexture(skyTex);
    SKY.LoadTexture("Image/sky.png");
    /*CLOUD.LoadTexture("SFML_game01\Image\2.png");
    HILL.LoadTexture("SFML_game01\Image\3.png");
    FIELD.LoadTexture("SFML_game01\Imgae\4.png");*/

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
        
        
        window.clear(sf::Color::White);
        //window.draw(sky);
        SKY.Render(window);

        player.Render(window);
        window.display();
        
        
        
        
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
     //Complete//  -Image Background, player 
                   -Find how to add animation 
                   -Random monster 
                        -Type of monster 
                        -Theame game 
        
*/

/*--------------------------------------------------------------------------------
    08/02/2568 (0.55)
    Fix bug reset image frame by frame
    Next to do-list 

                    -add Backgournd in gameplay and player



*/