#pragma once
#include "library.h"


class Fallenenemy
{
private:
    //Variables
    unsigned pointCount;
    sf::CircleShape shape;
    int type;
    float speed;
    int hp;
    int hpMax;
    int damage;
    int points;
    int losePoints;


    void createVariables();
    void createShape();

public:
    Fallenenemy(float pos_x, float pos_y);
    virtual ~Fallenenemy();

    //Accessor
    const sf::FloatRect getBounds() const;
    const int& getPoints() const;
    const int& getDamage() const;
    const int& getLosePoints() const;

    //Functions
    void update();
    void render(sf::RenderTarget& target);
};

