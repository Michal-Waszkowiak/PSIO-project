#include "bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(sf::Texture* texture,float pos_x, float pos_y, float dir_x, float dir_y, float bullet_speed )
{
    this->sprite.setTexture(*texture);

    this->sprite.setPosition(pos_x,pos_y);
    this->direction.x = dir_x;
    this->direction.y = dir_y;
    this->bulletSpeed = bullet_speed;
}

Bullet::~Bullet()
{

}

const sf::FloatRect Bullet::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

void Bullet::update()
{
    //Movement
    this->sprite.move(this->bulletSpeed * this->direction);

}

void Bullet::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}
