#pragma once
#include "library.h"


class Fallenenemy
{
private:
    sf::CircleShape shape;
    int type;
    float speed;
    int hp;
    int hpMax;
    int damage;
    int points;

    void createShape();
    void createVariables();

public:
    Fallenenemy(float pos_x, float pos_y);
    virtual ~Fallenenemy();

    //Accessor
    const sf::FloatRect getBounds() const;

    //Functions
    void update();
    void render(sf::RenderTarget& target);
};

