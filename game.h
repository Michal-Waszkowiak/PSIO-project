#pragma once
#include "library.h"
#include "player.h"
#include "tilemap.h"
#include "bullet.h"
#include "fallenenemy.h"
#include "medkit.h"
#include "door.h"
#include "objectstomove.h"
#include "treasure.h"


class Game
{
private:

    //Variables

    sf::RenderWindow window;
    sf::View view;
    sf::Event eve;

    float windowHeight;
    float windowWidth;
    bool endGame;
    bool extraLevel;
    bool extraLevelExtra;

    //Player
    Player* player;

    sf::RectangleShape playerHPbar;
    sf::RectangleShape playerHPbarBack;

    //Tilemap
    TileMap tilemap;

    //Door
    Door* door;

    //Enemies
    float spawnTimer;
    float spawnTimerMax;
    std::vector<Fallenenemy*> fallenemies;

    //ObjectsToMove
    std::vector<ObjectsToMove*> objectstomove;
    int numberOfObjects;

    //Medkits
    float spawnTimerMed;
    float spawnTimerMaxMed;
    std::vector<Medkit*> medkits;

    //Treasure
    Treasure* treasure;

    //Resources
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets;

    //GUI
    sf::Font font;
    sf::Text pointText;
    sf::Text WinGameText;
    sf::Text LoseGameText;
    sf::Text OpisText;
    std::string linia;
    std::fstream plik;

    //Systems
    unsigned points;


    //Creating stuff
    void createWindow();
    void createVariables();
    void createLoadText();
    void createFonts();
    void createText();
    void createPlayer();
    void createDoor();
    void createGUI();
    void createSystems();
    void createTextures();
    void createFallenEnemies();
    void createMedkits();
    void createObjectsToMove();
    void createTreasure();

public:
    //Constructors | Deconstructors

    Game();
    virtual ~Game();

    //Accessors
    const bool& getEndGame() const;
    const bool& getExtraLevel() const;
    void losePoints(const int loseP_);

    //Functions
    void pollEvents();
    //Main level

    void updatePlayer();
    void updateDoor();
    void updateCollision();
    void updateLevel();
    void updateGUI();
    void updateBullets();
    void updateFallenEnemies();
    void updateMedkits();
    void updateObjectsToMove();
    void updateTreasure();
    void updateCombat();
    void update();
    void renderPlayer();
    void renderDoor();
    void renderGUI();
    void renderBulletes();
    void renderFallenEnemies();
    void renderMedkits();
    void renderObjectsToMove();
    void renderTreasure();
    void render();

    //Extra level
    const sf::RenderWindow& getWindow() const;
};
