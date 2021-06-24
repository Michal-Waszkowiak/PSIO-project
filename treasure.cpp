#include "treasure.h"

void Treasure::createTexture()
{
    if(!this->texture.loadFromFile("Images/skarb.png"))
    {
        std::cout<<"Halo prosze wczytac drzwi!"<< std::endl;
    }
}

void Treasure::createSprite()
{
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(1.f,1.f);
}

Treasure::Treasure()
{
    this->createTexture();
    this->createSprite();
}

Treasure::~Treasure()
{

}

const sf::Vector2f Treasure::getPos() const
{
    return this->sprite.getPosition();
}

const sf::FloatRect Treasure::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

bool Treasure::isClicked(const sf::Vector2f &mouse_position) const
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

void Treasure::setPosition(const float x, const float y)
{
    this->sprite.setPosition(x,y);
}

void Treasure::update()
{

}

void Treasure::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}
