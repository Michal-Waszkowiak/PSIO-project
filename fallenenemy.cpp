#include "fallenenemy.h"

void Fallenenemy::createShape()
{
    this->shape.setRadius(rand() % 10 + 10);
    this->shape.setPointCount(rand() % 20 + 3);
    this->shape.setFillColor(sf::Color(rand()%255+1,rand()%255+1,rand()%255+1,255));
}

void Fallenenemy::createVariables()
{
    this->type = 0;
    this->speed = 5;
    this->hpMax = 10;
    this->hp = 0;
    this->damage = 1;
    this->points = 5;
}

Fallenenemy::Fallenenemy(float pos_x, float pos_y)
{
    this->createShape();
    this->createVariables();
    this->shape.setPosition(pos_x,pos_y);
}

Fallenenemy::~Fallenenemy()
{

}

//Accessor
const sf::FloatRect Fallenenemy::getBounds() const
{
    return this->shape.getGlobalBounds();

}

//Functions

void Fallenenemy::update()
{
    this->shape.move(0,this->speed);
}

void Fallenenemy::render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}
