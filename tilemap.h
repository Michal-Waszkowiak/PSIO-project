#pragma once
#include "library.h"


class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    TileMap();

    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    //Variables
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};
