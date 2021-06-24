#pragma once
#include "library.h"


class Bullet
{
private:
    //Variables
    sf::Sprite sprite;
    sf::Vector2f direction;
    float bulletSpeed;

public:
    Bullet();
    Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float bullet_speed);
    ~Bullet();

    //Accessor
    const sf::FloatRect getBounds() const;
    //Functions
    void update();
    void render(sf::RenderTarget& target);
};

