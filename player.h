#pragma once
#include "library.h"

enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, ATTACK};

class Player
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
    float attackCooldown;
    float attackCooldownMax;
    int hp;
    int hpMax;


    void createVariables();
    void createTexture();
    void createSprite();
    void createView();
    void createAnimation();
    void createPhysics();

public:
    Player();

    virtual ~Player();

    //Accessors
    const sf::Vector2f getPosition() const;
    const sf::FloatRect getGlobalBounds() const;
    int getHp() const;
    int getHpMax() const;
    sf::View view;

    //Modifiers
    void setPosition(const float x, const float y);
    void resetVelocityY();
    void resetVelocityX();
    void setHp(const int hp_);
    void loseHp(const int value_);
    void pickUpHp(const int givehp_);

    //Functions
    bool canAttack();

    void move(const float direction_x, const float direction_y);
    void speed();
    void updatePhysics();
    void updateAttack();
    void updateMovement();
    void updateAnimation();
    void update();
    void render(sf::RenderTarget& target);
};

