#include "library.h"
#include "enemy.h"

void Enemy::createVariables()
{
    this ->animationStates = ENEMY_ANIMATION_STATES::IDLE;
}

void Enemy::createTexture()
{
    if(!this->textureSheet.loadFromFile("Images/mumia_ruch.png"))
    {
        std::cout<<"Halo prosze wczytac gracza!"<< std::endl;
    }

}

void Enemy::createSprite()
{
    this->sprite.setTexture(this->textureSheet);
    this->currentFrame = sf::IntRect(0,0,32,64);
    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setScale(2.f,2.f);

}

void Enemy::createAnimation()
{
    this->animationTime.restart();

}

void Enemy::createPhysics()
{
    this->velMax = 4.f;
    this->velMin = 0.5f;
    this->acceleration = 1.f;
    this->drag = 0.6f;
    this->gravity = 6.f;
    this->velocityMaxY = 10.f;

}


Enemy::Enemy()
{
    this->createVariables();
    this->createTexture();
    this->createSprite();
    this->createAnimation();
    this->createPhysics();

}

Enemy::~Enemy()
{

}

const sf::Vector2f Enemy::getPosition() const
{
    return this->sprite.getPosition();
}

const sf::FloatRect Enemy::getGlobalBounds() const
{
    return this->sprite.getGlobalBounds();
}

void Enemy::setPosition(const float x, const float y)
{
    this->sprite.setPosition(x,y);
}

void Enemy::resetVelocityY()
{
    this->velocity.y = 0.f;
}

void Enemy::move(const float direction_x, const float direction_y)
{
    //Acceleration
    this->velocity.x += direction_x * this->acceleration;

    //Limit vel
    if(std::abs(this->velocity.x) > this->velMax)
    {
        this->velocity.x = this->velMax * ((this->velocity.x) < 0.f ? -1.f : 1.f);
    }

}


void Enemy::speed()
{
    this->velMax = 15.f;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //left
        this->move(-1.f,0.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //right
        this->move(1.f,0.f);
}


void Enemy::updatePhysics()
{
    //Gravity
    this->velocity.y += 1.0 * this->gravity;
    if(std::abs(this->velocity.y) > this->velocityMaxY)
    {
        this->velocity.y = this->velocityMaxY * ((this->velocity.y) < 0.f ? -1.f : 1.f);
    }

    //Deceleration
    this->velocity *= this->drag;

    //Limit deceleceration
    if(std::abs(this->velocity.x) < this->velMin)
    {
        this->velocity.x = 0.f;
    }
    if(std::abs(this->velocity.y) < this->velMin)
    {
        this->velocity.y = 0.f;
    }

    this->sprite.move(this->velocity);
}

void Enemy::updateMovement()
{
    this->animationStates = ENEMY_ANIMATION_STATES::IDLE;
    //X Axis movement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //left
    {
        this->move(-1.f,0.f);
        this->animationStates = ENEMY_ANIMATION_STATES::MOVING_LEFT;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //right
    {
        this->move(1.f,0.f);
        this->animationStates = ENEMY_ANIMATION_STATES::MOVING_RIGHT;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
    {
        this->speed();
    }

}

void Enemy::updateAnimation()
{
    if(this->animationStates == ENEMY_ANIMATION_STATES::IDLE)
    {
        if(this->animationTime.getElapsedTime().asSeconds() >= 0.5f)
        {
            this->currentFrame.top = 0.f;
            this->currentFrame.left += 32.f;
            if(this->currentFrame.left >= 128.f)
                this->currentFrame.left = 0;

            this->animationTime.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
    }
    else if(this->animationStates == ENEMY_ANIMATION_STATES::MOVING_RIGHT)
    {
        if(this->animationTime.getElapsedTime().asSeconds() >= 0.3f)
        {
            this->currentFrame.top = 64.f;
            this->currentFrame.left += 32.f;
            if(this->currentFrame.left >= 128.f)
                this->currentFrame.left = 0;

            this->animationTime.restart();
            this->sprite.setTextureRect(this->currentFrame);
            this->sprite.setScale(2.f,2.f);
            this->sprite.setOrigin(0.f,0.f);
        }


    }
    else if(this->animationStates == ENEMY_ANIMATION_STATES::MOVING_LEFT)
    {
        if(this->animationTime.getElapsedTime().asSeconds() >= 0.3f)
        {
            this->currentFrame.top = 64.f;
            this->currentFrame.left += 32.f;
            if(this->currentFrame.left >= 128.f)
                this->currentFrame.left = 0;

            this->animationTime.restart();
            this->sprite.setTextureRect(this->currentFrame);
            this->sprite.setScale(-2.f,2.f);
            this->sprite.setOrigin(this->sprite.getGlobalBounds().width/2.f, 0);
        }
    }
    else
        this->animationTime.restart();

}


void Enemy::update()
{
    this->updateMovement();
    this->updateAnimation();
    this->updatePhysics();

}

void Enemy::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}
