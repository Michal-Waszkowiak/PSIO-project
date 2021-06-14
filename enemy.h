#pragma once
#include "library.h"

enum ENEMY_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, ATTACK};

class Enemy
{
private:
    sf:: Sprite sprite;
    sf::Texture textureSheet;
    sf::Clock animationTime;


    //Animation
    short animationStates;
    sf::IntRect currentFrame;


    //Physics
    sf::Vector2f velocity;
    float velMax;
    float velMin;
    float acceleration;
    float drag;
    float gravity;
    float velocityMaxY;


    void createVariables();
    void createTexture();
    void createSprite();
    void createAnimation();
    void createPhysics();

public:
    Enemy();

    virtual ~Enemy();

    //Accessors
    const sf::Vector2f getPosition() const;
    const sf::FloatRect getGlobalBounds() const;
    sf::View view;

    //Modifiers
    void setPosition(const float x, const float y);
    void resetVelocityY();

    //Functions
    void move(const float direction_x, const float direction_y);
    void speed();
    void updatePhysics();
    void updateMovement();
    void updateAnimation();
    void update();
    void render(sf::RenderTarget& target);
};
