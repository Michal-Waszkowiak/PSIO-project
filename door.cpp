#include "door.h"

void Door::createTexture()
{
    if(!this->textureSheet.loadFromFile("Images/drzwi.png"))
    {
        std::cout<<"Halo prosze wczytac drzwi!"<< std::endl;
    }
}

void Door::createSprite()
{
    this->sprite.setTexture(this->textureSheet);
    this->currentFrame = sf::IntRect(0,0,40,64);
    this->sprite.setTextureRect(this->currentFrame);
    this->sprite.setScale(3.f,3.f);
}

Door::Door()
{
    this->createTexture();
    this->createSprite();
}

Door::~Door()
{

}

const sf::Vector2f Door::getPos() const
{
    return this->sprite.getPosition();
}

const sf::FloatRect Door::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

void Door::setPosition(const float x, const float y)
{
    this->sprite.setPosition(x,y);
}

void Door::update()
{

}

void Door::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}
