#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "playerClass.h"

int windowWidth = 1536;
int windowHeight = 865;

using namespace sf;
using namespace std;


int main(){
    //Create the main window
    RenderWindow app(VideoMode(windowWidth,windowHeight), "Platformer");

    bool playerUp, playerDown, playerLeft, playerRight = false;
    bool playerUpJump;

    playerClass playerObject;

    Texture texture;
    texture.loadFromFile("C:/Users/iesty/Documents/Projects/2dgame/data/images/animation.png");

    IntRect rectSourceSprite(0, 0 ,50, 50);
    IntRect rectSourceSprite2(0, 50 ,50, 50);
    IntRect rectSourceSprite3(0, 100 ,50, 50);
    IntRect rectSourceSprite4(0, 150 ,50, 50);
    Sprite sprite(texture, rectSourceSprite4);
    Clock clock;

    Texture Background;
    Background.loadFromFile("C:/Users/iesty/Documents/Projects/2dgame/data/images/background.png");
    Sprite BackgroundSprite(Background);

    //Start the game loop
    while(app.isOpen())
    {
        //Process events
        Event event{};
        while(app.pollEvent(event)) {
            if(event.type == Event::Closed)
                app.close();
            }

        //animations

        //move right
    if(playerObject.xvel > 0 && playerObject.yvel == 0) {
        if (clock.getElapsedTime().asSeconds() > 0.2f) {
            if (rectSourceSprite.left == 200)
                rectSourceSprite.left = 50;
            else
                rectSourceSprite.left += 50;

            sprite.setTextureRect(rectSourceSprite);
            clock.restart();
        }
    }
//move left
        if(playerObject.xvel < 0 && playerObject.yvel == 0) {
            if (clock.getElapsedTime().asSeconds() > 0.2f) {
                if (rectSourceSprite2.left == 200)
                    rectSourceSprite2.left = 50;
                else
                    rectSourceSprite2.left += 50;

                sprite.setTextureRect(rectSourceSprite2);
                clock.restart();
            }
        }

        //stand still
        if ((playerObject.yvel == 0.00) && (playerObject.xvel == 0.00) && (playerObject.playerFaceLeft)) {

            rectSourceSprite2.left = 0;
            sprite.setTextureRect(rectSourceSprite2);
            clock.restart();
        }

        if (playerObject.yvel == 0.00 && playerObject.xvel == 0.00 && (!playerObject.playerFaceLeft)){

                rectSourceSprite.left = 0;
                sprite.setTextureRect(rectSourceSprite);
                clock.restart();
        }

        //jump
        if(playerObject.yvel > 0 && playerObject.playerFaceLeft || playerObject.yvel < 0 && playerObject.playerFaceLeft ) {
            if (clock.getElapsedTime().asSeconds() > 0.3f) {
                if(rectSourceSprite3.left != 100)
                    rectSourceSprite3.left += 50;
                sprite.setTextureRect(rectSourceSprite3);
                clock.restart();
            }
        }

        if(playerObject.yvel > 0.00 && !playerObject.playerFaceLeft || playerObject.yvel < 0 && !playerObject.playerFaceLeft ) {
            if (clock.getElapsedTime().asSeconds() > 0.3f) {
                if(rectSourceSprite4.left != 100)
                    rectSourceSprite4.left += 50;
                sprite.setTextureRect(rectSourceSprite4);
                clock.restart();
            }
        }

        if(playerObject.yvel == 0){
            rectSourceSprite3.left = 0;
            rectSourceSprite4.left = 0;
        }

        //direction
        if(Keyboard::isKeyPressed(Keyboard::Right)) playerRight = true;
        if(Keyboard::isKeyPressed(Keyboard::Left)) playerLeft = true;
        if(Keyboard::isKeyPressed(Keyboard::Space) && playerObject.yvel < 0.5) playerUp = true;
        if(Keyboard::isKeyPressed(Keyboard::Down)) playerDown = true;
        if(!(Keyboard::isKeyPressed(Keyboard::Down))) playerDown = false;
        if(!(Keyboard::isKeyPressed(Keyboard::Space))) playerUp = false;
        if(!(Keyboard::isKeyPressed(Keyboard::Left))) playerLeft = false;
        if(!(Keyboard::isKeyPressed(Keyboard::Right))) playerRight = false;
        playerObject.update(playerUp, playerDown, playerRight, playerLeft);

        //Clear screen
        app.clear(sf::Color(0, 0, 0));
        app.draw(BackgroundSprite);
        app.draw(sprite);
        sprite.move(Vector2f(playerObject.xvel, playerObject.yvel));





        //Update the window
        app.display();


    }
    return EXIT_SUCCESS;
}
