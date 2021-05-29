#include "game.h"

void Game::createWindow()
{
    this->windowHeight = 1024;
    this->windowWidth = 800;
    this->window.create(sf::VideoMode(windowWidth,windowHeight), "Indiana Jones", sf::Style::Titlebar | sf::Style::Close);
    this->window.setFramerateLimit(60);

}

void Game::createPlayer()
{
    this->player = new Player();
}

void Game::createPlatform()
{
    this->platform = new Platform();
}

Game::Game()
{
    this->createWindow();
    this->createPlayer();
    this->createPlatform();
}

Game::~Game()
{
    delete this->player;
    delete this->platform;

}

void Game::updatePlayer()
{
    this->player->update();

}

void Game::updateCollision()
{
    //Collision with the floor screen
    if(this->player->getPosition().y + this->player->getGlobalBounds().height >= this->window.getSize().y)
    {
        this->player->resetVelocityY();
        this->player->setPosition(this->player->getPosition().x,
                                  this->window.getSize().y - this->player->getGlobalBounds().height);
    }

}

void Game::updateLevel()
{
    const int level[] =
    {
        1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 4, 0, 0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 4, 4, 4, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 4, 4, 4, 0, 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    };

    // create the tilemap from the level definition
    if (!map.load("Images/map01.png", sf::Vector2u(32, 32), level, 32, 16))
        return;
}

void Game::update()
{
    this->updatePlayer();
    this->updateLevel();

    //window events
    while(this->window.pollEvent(this->eve))
    {
        if(this->eve.type == sf::Event::Closed)
            this->window.close();
        else if(this->eve.type == sf::Event::KeyPressed && this->eve.key.code == sf::Keyboard::Escape)
            this->window.close();

    }

    this->updateCollision();

}

void Game::renderPlayer()
{
    this->player->render(this->window);

}

void Game::renderPlatform()
{
    this->platform->render(this->window);
}


void Game::render()
{
    //Clear window
    this->window.clear(sf::Color::Black);

    //Render
    this->window.draw(map);
    this->renderPlayer();
    this->window.setView(this->player->view);
    this->renderPlatform();


    //Display game
    this->window.display();
}

const sf::RenderWindow &Game::getWindow() const
{
    return this->window;
}
