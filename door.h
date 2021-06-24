#pragma once

#include "library.h"


class Door
{
private:
    //Variables
    sf:: Sprite sprite;
    sf::Texture textureSheet;
    sf::IntRect currentFrame;

    void createTexture();
    void createSprite();

public:
    Door();
    virtual ~Door();

    //Accessors
    const sf::Vector2f getPos() const;
    const sf::FloatRect getBounds() const;

    //Modifiers
    void setPosition(const float x, const float y);

    //Functions
    void update();
    void render(sf::RenderTarget& target);
};

