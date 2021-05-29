#pragma once

#include"library.h"


class Platform
{
private:
    sf::Texture platformSpriteSheet;
    sf::Sprite platformSprite;
    sf::IntRect currentFrame;

    float xposition;
    float yposition;
    float xvelocity;
    float yvelocity;


    void createTexture();
    void createSprite();

public:
    Platform();

    virtual ~Platform();

    //Accessors
    const sf::Vector2f getPosition() const;
    const sf::FloatRect getGlobalBounds() const;

    //Modifiers
    void setPosition(const float x, const float y);

    //Functions
    void render(sf::RenderTarget& target);
};

