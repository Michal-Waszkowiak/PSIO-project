#pragma once
#include "library.h"


class Fallenenemy
{
private:
    unsigned pointCount;
    sf::CircleShape shape;
    int type;
    float speed;
    int hp;
    int hpMax;
    int damage;
    int points;


    void createVariables();
    void createShape();

public:
    Fallenenemy(float pos_x, float pos_y);
    virtual ~Fallenenemy();

    //Accessor
    const sf::FloatRect getBounds() const;
    const int& getPoints() const;
    const int& getDamage() const;

    //Functions
    void update();
    void render(sf::RenderTarget& target);
};

