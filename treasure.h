#pragma once

#include "library.h"


class Treasure
{
private:
    sf:: Sprite sprite;
    sf::Texture texture;

    void createTexture();
    void createSprite();

public:
    Treasure();
    virtual ~Treasure();

    //Accessors
    const sf::Vector2f getPos() const;
    const sf::FloatRect getBounds() const;
    bool isClicked(const sf::Vector2f &mouse_position) const;

    //Modifiers
    void setPosition(const float x, const float y);

    //Functions
    void update();
    void render(sf::RenderTarget& target);
};
