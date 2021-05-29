#include "platform.h"

void Platform::createTexture()
{
    if(!this->platformSpriteSheet.loadFromFile("Images/podlogalochy.png"))
    {
        std::cout<<"Halo prosze wczytac podloge!"<< std::endl;
    }

}

void Platform::createSprite()
{
    this->platformSprite.setTexture(this->platformSpriteSheet);
    this->currentFrame = sf::IntRect(0,0,32,16);
    this->platformSprite.setTextureRect(this->currentFrame);
    this->platformSprite.setScale(3.f,3.f);

}



Platform::Platform()
{
    this->createTexture();
    this->createSprite();
}

Platform::~Platform()
{

}

const sf::Vector2f Platform::getPosition() const
{
    return this->platformSprite.getPosition();
}

const sf::FloatRect Platform::getGlobalBounds() const
{
    return this->platformSprite.getGlobalBounds();
}

void Platform::setPosition(const float x, const float y)
{
    this->platformSprite.setPosition(x,y);
}

void Platform::render(sf::RenderTarget &target)
{
    target.draw(this->platformSprite);

    this->platformSprite.setPosition(50.f,0.f);
}
