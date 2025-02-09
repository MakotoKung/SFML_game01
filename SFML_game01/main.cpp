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
    Player player(0.8f, 100.00f, { 5,520 }, sf::IntRect(0, 320, 1220, 250), 3, { 64,128 }); //Contructor = Position in Entity_Class x,y
    Entity Monster;
    Entity Background, barSta, sta, Heart[3];

    Background.LoadTexture("Image/Background.png");
    //----StaminaBar--------//
    barSta.body.setFillColor(sf::Color::Transparent);
    barSta.body.setOutlineColor(sf::Color::Black);
    barSta.body.setOutlineThickness(3.00f);
    barSta.body.setSize({ 350,40 });
    barSta.SetPosition({ 20,120 });
    //------Inside StaminaBar--------//
    sta.body.setFillColor(sf::Color::Yellow);
    sta.body.setSize({ 350 ,40 }); //stamina *3.5f;
    sta.SetPosition({ 20,120 });

    //-------Hp----------------//
    for (int i = 0;i < 3;i++) {
        Heart[i].LoadTexture("C:/Users/Shifuro/Downloads/Heart100.png");
    }
    Heart[0].SetPosition({ 10,10 });
    Heart[1].SetPosition({ 110,10 });
    Heart[2].SetPosition({ 210,10 });


    //Player Setting 
    player.body.setFillColor(sf::Color::Transparent);
    //------collision------//
    //player.body.setOutlineThickness(5.0f);
    //player.body.setOutlineColor(sf::Color::Blue);
    player.body.setSize({ 60,124 }); //default = {64,128}
    player.LoadTexture("Image/Player.png");
    player.Hp = 3;

    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(width, height), "First Game");
    window.setFramerateLimit(90);

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
        float stamina = player.getStamina();

        //----------Obj function-----------//
        player.Movement();
        player.getPosition();
        sta.body.setSize({ stamina * 3.5f ,40 });

        //-------------Draw--------------------//
        window.clear(sf::Color::White);
        Background.Render(window);
        barSta.Render(window);
        sta.Render(window);
        cout << "\nHP : " << player.Hp;
        if (player.Hp != 0) {
            for (int i = 0;i < player.Hp;i++) {
                Heart[i].Render(window);

            }

            //Hp.Render(window);
            player.Render(window);

            window.display();

        }
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
     //Get Idea//  -Find how to add animation  // Loop load new image by frame//
     //Get Idea//  -Random monster 
     //Get Idea//   -Type of monster //Easy meduim Hard//
                    -Theame game  // Hardcore Game //
        
*/

/*--------------------------------------------------------------------------------
    08/02/2568 (0.55)
    Fix bug reset image frame by frame
    Next to do-list 

     //Complete//   -add Backgournd in gameplay and player

*/
/*---------------------------------------------------------------------------------
    09/02/2568 (3.48)
    Add Stamina Bar and sprint button in player_class 
    Next to do-list 

    //Complte//     -Make HP_Bar
                    -Random system 
                    -score & Point 
                    -Main menu 
                    -Monster
                    -Hitbox (collision)



*/