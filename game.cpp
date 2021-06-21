#include "game.h"

void Game::createWindow()
{
    this->windowHeight = 800;
    this->windowWidth = 1000;
    this->window.create(sf::VideoMode(windowWidth,windowHeight), "Indiana Jones", sf::Style::Titlebar | sf::Style::Close);
    this->window.setFramerateLimit(60);

}

void Game::createPlayer()
{
    this->player = new Player();
}

void Game::createGUI()
{
    if(!this->font.loadFromFile("fonts/GistLight.otf"))
    {
        std::cout<<"ERROR!! WRONG FONTS HERE"<<std::endl;
    }

    this->pointText.setFont(this->font);
    this->pointText.setCharacterSize(32);
    this->pointText.setFillColor(sf::Color::White);
    this->pointText.setString("test");

    this->playerHPbar.setSize(sf::Vector2f(100.f,10.f));
    this->playerHPbar.setOrigin(sf::Vector2f(50.f,10.f));
    this->playerHPbar.setFillColor(sf::Color::Red);


    this->playerHPbarBack = this->playerHPbar;
    this->playerHPbarBack.setFillColor(sf::Color(50,50,50,150));
}

void Game::createSystems()
{
    this->points = 0;
}

void Game::createTextures()
{
    this->textures["BULLET"] = new sf::Texture();
    this->textures["BULLET"]->loadFromFile("images/kamien.png");
}

void Game::createFallenEnemies()
{
    this->spawnTimerMax = 50;
    this->spawnTimer = this->spawnTimerMax;
}

void Game::createMedkits()
{
    this->spawnTimerMaxMed = 1;
    this->spawnTimerMed = this->spawnTimerMax;
}

Game::Game()
{
    this->createWindow();
    this->createPlayer();
    this->createGUI();
    this->createSystems();
    this->createTextures();
    this->createFallenEnemies();
}

Game::~Game()
{
    delete this->player;

    for(auto &i : this->textures)
    {
        delete  i.second;
    }

    for(auto *i : this->bullets)
    {
        delete  i;
    }

    for(auto *i : this->fallenemies)
    {
        delete  i;
    }

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

    if(this->player->getPosition().x <= -1)
    {
        this->player->resetVelocityX();
        this->player->setPosition(-1,
                                  this->window.getSize().y - this->player->getGlobalBounds().height);
    }

    if(this->player->getPosition().x >= 2000)
    {
        this->player->resetVelocityX();
        this->player->setPosition(2000,
                                  this->window.getSize().y - this->player->getGlobalBounds().height);
    }

}

void Game::updateLevel()
{
    int level[] =
    {
        4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0,
        4, 4, 4, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 4,
        4, 4, 4, 4, 0, 0, 0, 4, 4, 4, 4, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 4, 4,
        4, 4, 0, 4, 4, 0, 4, 4, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 4, 4, 4,
        4, 4, 0, 0, 4, 4, 4, 0, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 4, 4, 4,
        4, 4, 0, 0, 0, 4, 0, 0, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 4, 4,
        4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 4,
        4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0, 0, 4, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 4, 4,
        4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0, 4, 4, 4, 0, 0, 4, 4, 4, 4, 4, 0, 4, 4, 4,
        4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 4, 4, 0, 0, 4, 4, 0, 4, 4, 0, 4, 4, 4, 4, 4, 0, 4, 4, 4,
        4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 4, 4, 0, 4, 4, 0, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 4, 4,
        4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 4,
        4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0,
    };

    // create the tilemap from the level definition
    if (!tilemap.load("Images/map01.png", sf::Vector2u(32, 32), level, 32, 13))
        return;
}

void Game::updateGUI()
{
    std::stringstream ss;
    this->pointText.setPosition(this->player->getPosition().x-450, this->player->getPosition().y-640);
    ss << "Twoje punkty: " << this->points;

    this->pointText.setString(ss.str());

    float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
    this->playerHPbar.setPosition(this->player->getPosition().x + this->player->getGlobalBounds().width/2, this->player->getPosition().y - 25.f);
    this->playerHPbarBack.setPosition(this->player->getPosition().x + this->player->getGlobalBounds().width/2, this->player->getPosition().y - 25.f);
    this->playerHPbar.setSize(sf::Vector2f(100.f * hpPercent, this->playerHPbar.getSize().y));
}

void Game::updateBullets()
{
    unsigned counter = 0;

    for(auto bullet : this->bullets)
    {
        bullet->update();

        if(bullet->getBounds().top + bullet->getBounds().height < 0.f)
        {
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin() + counter);
        }
    }

    ++counter;
}

void Game::updateFallenEnemies()
{
    this->spawnTimer += 1.5;
    if(this->spawnTimer >= this->spawnTimerMax)
    {
        this->fallenemies.push_back(new Fallenenemy(rand()% 1500 - 20, -100));
        this->spawnTimer = 0;
    }   

    unsigned counter = 0;

    for(auto *fallenemy : this->fallenemies)
    {
        fallenemy->update();

        if(fallenemy->getBounds().top > this->window.getSize().y)
        {
            delete this->fallenemies.at(counter);
            this->fallenemies.erase(this->fallenemies.begin() + counter);
        }
        else if(fallenemy->getBounds().intersects(this->player->getGlobalBounds()))
        {
            this->player->loseHp(this->fallenemies.at(counter)->getDamage());
            delete this->fallenemies.at(counter);
            this->fallenemies.erase(this->fallenemies.begin() + counter);
        }
    }

    ++counter;
}

void Game::updateMedkits()
{
unsigned counter = 0;

this->spawnTimerMed += 0.00001;
if(this->spawnTimerMed >= this->spawnTimerMaxMed)
{
    this->medkits.push_back(new Medkit(rand()% 1500 - 20, this->window.getSize().y - 32));
    this->spawnTimerMed = 0;
}
for(auto *meds : this->medkits)
{
    meds->update();
    if(meds->getBounds().intersects(this->player->getGlobalBounds()))
    {
        this->player->pickUpHp(this->medkits.at(counter)->getHp());
        delete this->medkits.at(counter);
        this->medkits.erase(this->medkits.begin() + counter);
    }
}
++counter;

}
void Game::updateCombat()
{
    for(size_t i = 0; i < this->fallenemies.size(); i++)
    {
        bool fallenenemyDeleted = false;
        for(size_t j = 0; j < this->bullets.size() && fallenenemyDeleted == false; j++)
        {
            if(this->fallenemies[i]->getBounds().intersects(this->bullets[j]->getBounds()))
            {
                this->points += this->fallenemies[i]->getPoints();

                delete  this->fallenemies[i];
                this->fallenemies.erase(this->fallenemies.begin() + i);

                delete  this->bullets[j];
                this->bullets.erase(this->bullets.begin() + j);

                fallenenemyDeleted = true;
            }
        }
    }
}

void Game::update()
{
    this->updatePlayer();
    this->updateLevel();
    this->updateCollision();
    this->updateBullets();
    this->updateFallenEnemies();
    this->updateMedkits();
    this->updateCombat();
    this->updateGUI();

    //window events
    while(this->window.pollEvent(this->eve))
    {
        if(this->eve.type == sf::Event::Closed)
            this->window.close();
        else if(this->eve.type == sf::Event::KeyPressed && this->eve.key.code == sf::Keyboard::Escape)
            this->window.close();

    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
    {
        this->bullets.push_back(new Bullet(this->textures["BULLET"],this->player->getPosition().x+this->player->getGlobalBounds().width/2,
                                this->player->getPosition().y+this->player->getGlobalBounds().height/2,0,-1,5));
    }

}

void Game::renderPlayer()
{
    this->player->render(this->window);

}

void Game::renderGUI()
{
    this->window.draw(this->pointText);
    this->window.draw(this->playerHPbarBack);
    this->window.draw(this->playerHPbar);
}

void Game::renderBulletes()
{
    for(auto bullet : this->bullets)
    {
        bullet->render(this->window);
    }
}

void Game::renderFallenEnemies()
{
    for(auto fenemies : this->fallenemies)
    {
        fenemies->render(this->window);
    }
}

void Game::renderMedkits()
{
    for(auto meds : this->medkits)
    {
        meds->render(this->window);
    }
}


void Game::render()
{
    //Clear window
    this->window.clear(sf::Color::Black);

    //Render
    this->window.draw(tilemap);
    this->renderPlayer();
    this->window.setView(this->player->view);
    this->renderBulletes();
    this->renderMedkits();
    this->renderFallenEnemies();
    this->renderGUI();


    //Display game
    this->window.display();
}

const sf::RenderWindow &Game::getWindow() const
{
    return this->window;
}
