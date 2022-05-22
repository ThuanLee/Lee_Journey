#include "game.h"

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initOjects();
    this->initThemeSong();
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

void Game::initThemeSong()
{
    if (!this->themeSong.openFromFile("assets/sound/themeSong.wav"))
    {
        std::cout << "ERROR::GAME::INITTHEMESONG::Can't load file!!!" << std::endl;
    }
    this->themeSong.setLoop(true);
    this->themeSong.setVolume(25.f);
    this->themeSong.play();
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
                this->themeSong.pause();
                break;

            case sf::Event::GainedFocus:
                
                this->themeSong.play();
                break;

            case sf::Event::KeyPressed:

                if (this->ev.key.code == sf::Keyboard::Escape)
                {
                    if (this->isGameOver)
                    {
                        this->isGameOver = false;
                        this->isGamePause = false;
                        this->gameRestart();
                    }
                    else
                    {
                        if (!this->isGamePause)
                        {
                            this->isGamePause = true;
                        }
                        else if (!this->menu->isMainMenu())
                        {
                            this->isGamePause = false;
                        }
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

void Game::updateDifficulty()
{
    if (this->score->upDiffLevel())
    {
        this->enemies->enemyStronger();
    } 
}

void Game::update()
{
    this->getEvent();
    this->updateMousePosition();
    this->updateDifficulty();
    
    //Game Over
    if (this->player->die())
    {
        this->isGameOver = true;
        this->isGamePause = true;
    }

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
    this->score->renderScore(*this->window, this->isGameOver);

    if (this->isGamePause)
    {
        if (this->isGameOver)
        {
            this->menu->renderGameOver(*this->window);
        }
        else
        {
            this->menu->renderMenu(*this->window);
        }
    }

    this->window->display();
}