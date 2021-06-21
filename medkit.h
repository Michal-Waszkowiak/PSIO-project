#pragma once
#include "library.h"

class Medkit
{
private:
    sf::RectangleShape shape;
    int giveHp;

    void createVariables();
    void createShape();
public:
    Medkit(float pos_x, float pos_y);
    virtual ~Medkit();

    //Accessor
    const sf::FloatRect getBounds() const;
    const int& getHp() const;

    //Functions
    void update();
    void render(sf::RenderTarget& target);
};

