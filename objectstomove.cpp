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
    this->sprite.setScale(10.f,10.f);
}

ObjectsToMove::ObjectsToMove(float pos_x, float pos_y)
{
    this->createTexture();
    this->createSprite();

    auto[x,y] = getRandomPosition(pos_x,pos_y);
    this->sprite.setPosition(x,y);
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

std::pair<int, int> ObjectsToMove::getRandomPosition(size_t resolution_x, size_t resolution_y)
{
        size_t x = 0;
        size_t y = 0;
        do
        {
         x = rand() % resolution_x;
         y = rand() % resolution_y;
        }while((x > 0) && (x < resolution_x) && (y > 0) && (y < resolution_y));

        return std::pair<int,int>(x,y);
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
