#include "game.h"

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initOjects();
}

Game::~Game()
{
    delete this->window;
    delete this->player;
    delete this->map;
    delete this->menu;
    delete this->enemies;
    delete this->score;
}

void Game::initVariables()
{
    this->isGamePause = true;
    this->isGameRestart = false;
}

void Game::initWindow()
{
    this->window = nullptr;
    
    sf::VideoMode videoMode;
    videoMode.height = WINDOW_HEIGHT;
    videoMode.width = WINDOW_WIDTH;

    this->window = new sf::RenderWindow(videoMode, "Lee's Journey", sf::Style::Titlebar | sf::Style::Close);
    this->window->setKeyRepeatEnabled(false);
    this->window->setFramerateLimit(FPS);
}

void Game::initOjects()
{
    this->player = new Player();
    this->map = new Map();
    this->menu = new Menu();
    this->enemies = new Enemies();
    this->score = new Score();
}

bool Game::running()
{
    return this->window->isOpen();
}

void Game::gameRestart()
{
    this->player = new Player();
    this->map = new Map();
    this->enemies = new Enemies();
    this->score = new Score();
}

void Game::getEvent()
{
    while (this->window->pollEvent(this->ev))
    {
        //Close window
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::LostFocus:
                this->isGamePause = true;
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                {
                    if (!this->isGamePause)
                    {
                        this->isGamePause = true;
                    }
                    else
                    {
                        this->isGamePause = false;
                    }
                }
        }
        //Reset frame of sprite rect
        this->player->resetFrameRect(this->ev);
    }
    
}

void Game::updateMousePosition()
{
    this->mousePosition = this->window->mapPixelToCoords(this->mouse.getPosition(*this->window));
}

void Game::update()
{
    this->getEvent();
    this->updateMousePosition();
    
    //Handle menu update while game paused
    if (this->isGamePause)
    {
        int menuCheck = this->menu->updateMenu(this->mousePosition);
        switch (menuCheck)
        {
            case 1:  //New game
                this->isGamePause = false;
                this->gameRestart();
                break;
            case 2:  //Main menu
                this->isGamePause = true;
                break;
            case 3:  //Continue
                this->isGamePause = false;
                break;
            case -1:  //Exit
                this->window->close();
                break;
        }
    }
    //While game not pause
    else
    {
        this->player->updatePlayer();
        this->map->checkCollision(this->player);
        this->enemies->updateEnemies(this->player);
        this->score->updateScore();
    }
}

void Game::render()
{
    this->window->clear();

    //Draw
    this->map->renderMap(*this->window);
    this->player->renderPlayer(*this->window);
    this->enemies->renderEnemies(*this->window);
    this->score->renderScore(*this->window);

    if (this->isGamePause)
    {
        this->menu->renderMenu(*this->window);
    }

    this->window->display();
}