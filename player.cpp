#include "library.h"
#include "player.h"

void Player::createVariables()
{
    this ->animationStates = PLAYER_ANIMATION_STATES::IDLE;
}

void Player::createTexture()
{
    if(!this->textureSheet.loadFromFile("Images/postac_animacje_prawo.png"))
    {
        std::cout<<"Halo prosze wczytac gracza!"<< std::endl;
    }

}

void Player::createSprite()
{
    this->sprite.setTexture(this->textureSheet);
    this->currentFrame = sf::IntRect(0,0,32,64);
    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setScale(2.f,2.f);

}

void Player::createView()
{
    this->view.reset(sf::FloatRect(0.f,0.f,1000.f,800.f));
    this->view.setCenter(this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2.f,
                         this->sprite.getPosition().y + this->sprite.getGlobalBounds().height - 368.f);

}

void Player::createAnimation()
{
    this->animationTime.restart();

}

void Player::createPhysics()
{
    this->velMax = 5.f;
    this->velMin = 1.f;
    this->acceleration = 1.5f;
    this->drag = 0.8f;
    this->gravity = 4.f;
    this->velocityMaxY = 15.f;
    this->attackCooldownMax = 10;
    this->attackCooldown = this->attackCooldownMax;
    this->hpMax = 100;
    this->hp = this->hpMax;

}



Player::Player()
{
    this->createVariables();
    this->createTexture();
    this->createSprite();
    this->createView();
    this->createAnimation();
    this->createPhysics();

}

Player::~Player()
{

}

const sf::Vector2f Player::getPosition() const
{
    return this->sprite.getPosition();
}

const sf::FloatRect Player::getGlobalBounds() const
{
    return this->sprite.getGlobalBounds();
}

int Player::getHp() const
{
    return this->hp;
}

int Player::getHpMax() const
{
    return this->hpMax;
}

void Player::setPosition(const float x, const float y)
{
    this->sprite.setPosition(x,y);
}

void Player::resetVelocityY()
{
    this->velocity.y = 0.f;
}

void Player::resetVelocityX()
{
    this->velocity.x = 0.f;
}

void Player::setHp(const int hp_)
{
    this->hp = hp_;
}

void Player::loseHp(const int value_)
{
    this->hp -= value_;
    if(this->hp < 0)
    {
        this->hp = 0;
    }
}

bool Player::canAttack()
{
    if(this->attackCooldown >= this->attackCooldownMax)
    {
        this->attackCooldown = 0;
        return true;
    }
    return false;
}

void Player::move(const float direction_x, const float direction_y)
{
    //Acceleration
    this->velocity.x += direction_x * this->acceleration;

    //Limit vel
    if(std::abs(this->velocity.x) > this->velMax)
    {
        this->velocity.x = this->velMax * ((this->velocity.x) < 0.f ? -1.f : 1.f);
    }

}


void Player::speed()
{
    this->velMax = 15.f;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //left
        this->move(-1.f,0.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //right
        this->move(1.f,0.f);
}


void Player::updatePhysics()
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

void Player::updateAttack()
{
    if(this->attackCooldown < this->attackCooldownMax)
    {
        this->attackCooldown += 0.5;
    }

}

void Player::updateMovement()
{
    this->animationStates = PLAYER_ANIMATION_STATES::IDLE;
    //X Axis movement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //left
    {
        this->move(-1.f,0.f);
        this->animationStates = PLAYER_ANIMATION_STATES::MOVING_LEFT;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //right
    {
        this->move(1.f,0.f);
        this->animationStates = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
    {
        this->speed();
    }

}

void Player::updateAnimation()
{
    if(this->animationStates == PLAYER_ANIMATION_STATES::IDLE)
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
    else if(this->animationStates == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
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
    else if(this->animationStates == PLAYER_ANIMATION_STATES::MOVING_LEFT)
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


void Player::update()
{
    this->updateMovement();
    this->updateAnimation();
    this->createView();
    this->updatePhysics();
    this->updateAttack();

}

void Player::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}
