#pragma once
#include "library.h"
#include "player.h"
#include "platform.h"
#include "tilemap.h"


class Game
{
private:

    //Variables

    sf::RenderWindow window;
    sf::Event eve;
    float windowHeight;
    float windowWidth;

    Player* player;
    Platform* platform;
    TileMap map;


    //Creating stuff

    void createWindow();
    void createPlayer();
    void createPlatform();

public:
    //Constructors | Deconstructors

    Game();
    virtual ~Game();

    //Functions

    void updatePlayer();
    void updateCollision();
    void updateLevel();
    void update();
    void renderPlayer();
    void renderPlatform();
    void render();
    const sf::RenderWindow& getWindow() const;
};
