#include "medkit.h"

void Medkit::createVariables()
{
    this->giveHp = 1;
}

void Medkit::createShape()
{
    this->shape.setSize(sf::Vector2f(10,10));
    this->shape.setFillColor(sf::Color::Red);
}

Medkit::Medkit(float pos_x, float pos_y)
{
    this->createVariables();
    this->createShape();

    this->shape.setPosition(pos_x,pos_y);
}

Medkit::~Medkit()
{

}

const sf::FloatRect Medkit::getBounds() const
{
    return this->shape.getGlobalBounds();
}

const int &Medkit::getHp() const
{
    return this->giveHp;
}

void Medkit::update()
{

}

void Medkit::render(sf::RenderTarget &target)
{
    target.draw(this->shape);
}
