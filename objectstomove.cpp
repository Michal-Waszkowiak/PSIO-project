#include "objectstomove.h"

void ObjectsToMove::createTexture()
{
    if(!this->texture.loadFromFile("Images/boss.png"))
    {
        std::cout<<"Halo prosze wczytac objekt!"<< std::endl;
    }
}

void ObjectsToMove::createSprite()
{
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(3.f,3.f);
}

ObjectsToMove::ObjectsToMove(float pos_x, float pos_y)
{
    this->createTexture();
    this->createSprite();

    this->sprite.setPosition(pos_x,pos_y);
}

ObjectsToMove::~ObjectsToMove()
{

}

const sf::Vector2f ObjectsToMove::getPos() const
{
    return this->sprite.getPosition();
}

const sf::FloatRect ObjectsToMove::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

bool ObjectsToMove::isClicked(const sf::Vector2f &mouse_position) const
{
        sf::FloatRect rectangle_bounds = getBounds();

        if(mouse_position.x > rectangle_bounds.left && mouse_position.x < rectangle_bounds.left + rectangle_bounds.width)
        {
            if(mouse_position.y > rectangle_bounds.top && mouse_position.y < rectangle_bounds.top + rectangle_bounds.height)
            {
                return true;
            }
        }
        return false;
}

void ObjectsToMove::setPos(const float x, const float y)
{
    this->sprite.setPosition(x,y);
}

void ObjectsToMove::changePos(const size_t x_, const size_t y_)
{
    this->sprite.setPosition(rand()% x_, rand()% y_);
}

void ObjectsToMove::update()
{

}

void ObjectsToMove::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}
