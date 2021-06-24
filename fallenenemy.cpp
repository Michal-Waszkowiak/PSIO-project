#include "fallenenemy.h"

void Fallenenemy::createVariables()
{
    this->pointCount = rand() % 8 + 3;
    this->type = 0;
    this->speed = static_cast<float>(this->pointCount);
    this->hpMax = static_cast<int>(this->pointCount/2);
    this->hp = this->hpMax;
    this->damage = this->pointCount;
    this->points = this->pointCount;
    this->losePoints = this->pointCount;
}

void Fallenenemy::createShape()
{
    this->shape.setRadius(this->pointCount*5);
    this->shape.setPointCount(this->pointCount);
    this->shape.setFillColor(sf::Color(rand()%255+1,rand()%255+1,rand()%255+1,255));
}

Fallenenemy::Fallenenemy(float pos_x, float pos_y)
{
    this->createVariables();
    this->createShape();

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

const int &Fallenenemy::getPoints() const
{
    return this->points;
}

const int &Fallenenemy::getDamage() const
{
    return this->damage;
}

const int &Fallenenemy::getLosePoints() const
{
    return this->losePoints;
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
