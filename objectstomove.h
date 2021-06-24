#pragma once
#include "library.h"


class ObjectsToMove
{
private:
    //Variables
    sf::Texture texture;
    sf::Sprite sprite;

    void createTexture();
    void createSprite();

public:
    ObjectsToMove(float pos_x, float pos_y);
    ~ObjectsToMove();

    //Accessors
    const sf::Vector2f getPos() const;
    const sf::FloatRect getBounds() const;
    bool isClicked(const sf::Vector2f &mouse_position) const;

    //Functions
    void setPos(const float x, const float y);
    void changePos(const size_t x_, const size_t y_);
    void update();
    void render(sf::RenderTarget& target);
};

