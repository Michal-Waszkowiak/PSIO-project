#pragma once
#include "library.h"
#include "player.h"
#include "tilemap.h"
#include "bullet.h"
#include "fallenenemy.h"


class Game
{
private:

    //Variables

    sf::RenderWindow window;
    sf::Event eve;
    float windowHeight;
    float windowWidth;

    //Player
    Player* player;

    sf::RectangleShape playerHPbar;
    sf::RectangleShape playerHPbarBack;

    //Tilemap
    TileMap tilemap;

    //Enemies
    float spawnTimer;
    float spawnTimerMax;
    std::vector<Fallenenemy*> fallenemies;

    //Resources
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets;

    //GUI
    sf::Font font;
    sf::Text pointText;

    //Systems
    unsigned points;


    //Creating stuff

    void createWindow();
    void createPlayer();
    void createGUI();
    void createSystems();
    void createTextures();
    void createFallenEnemies();

public:
    //Constructors | Deconstructors

    Game();
    virtual ~Game();

    //Functions

    void updatePlayer();
    void updateCollision();
    void updateLevel();
    void updateGUI();
    void updateBullets();
    void updateFallenEnemies();
    void updateCombat();
    void update();
    void renderPlayer();
    void renderGUI();
    void renderBulletes();
    void renderFallenEnemies();
    void render();
    const sf::RenderWindow& getWindow() const;
};
