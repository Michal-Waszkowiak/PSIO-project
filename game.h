#pragma once
#include "library.h"
#include "player.h"
#include "tilemap.h"
#include "bullet.h"
#include "fallenenemy.h"
#include "medkit.h"


class Game
{
private:

    //Variables

    sf::RenderWindow window;
    sf::Event eve;
    float windowHeight;
    float windowWidth;
    bool endGame;

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

    //Medkits
    float spawnTimerMed;
    float spawnTimerMaxMed;
    std::vector<Medkit*> medkits;

    //Resources
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets;

    //GUI
    sf::Font font;
    sf::Text pointText;
    sf::Text WinGameText;
    sf::Text LoseGameText;

    //Systems
    unsigned points;


    //Creating stuff

    void createWindow();
    void createVariables();
    void createFonts();
    void createText();
    void createPlayer();
    void createGUI();
    void createSystems();
    void createTextures();
    void createFallenEnemies();
    void createMedkits();

public:
    //Constructors | Deconstructors

    Game();
    virtual ~Game();

    //Accessors
    const bool& getEndGame() const;

    //Functions

    void pollEvents();
    void updatePlayer();
    void updateCollision();
    void updateLevel();
    void updateGUI();
    void updateBullets();
    void updateFallenEnemies();
    void updateMedkits();
    void updateCombat();
    void updateLose();
    void updateWin();
    void update();
    void renderPlayer();
    void renderGUI();
    void renderBulletes();
    void renderFallenEnemies();
    void renderMedkits();
    void render();
    const sf::RenderWindow& getWindow() const;
};
