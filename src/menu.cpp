#include "menu.h"

Menu::Menu()
{
    this->initVariables();
    this->initFont();
    this->initText();
    this->initSprite();
    this->initSound();
}    

Menu::~Menu()
{

}

void Menu::initVariables()
{
    this->Grey.r = 150;
    this->Grey.g = 150;
    this->Grey.b = 150;

    this->mainMenu = true;
    this->isGameOver = false;
}

void Menu::initFont()
{
    if (!this->font.loadFromFile("assets/font/manaspc.ttf"))
    {
        std::cout << "ERROR::MENU::INITFONT::Can't load file!!" << std::endl;
    }
}

void Menu::initText()
{
    //START GAME text
    this->newgameText.setFont(this->font);
    this->newgameText.setString("NEW GAME");
    this->newgameText.setCharacterSize(60);
    this->newgameText.setFillColor(sf::Color::White);
    this->newgameText.setOrigin(this->newgameText.getGlobalBounds().width / 2, 0.f);
    this->newgameText.setPosition(640.f, 350.f);

    //MAIN MENU text
    this->mainmenuText.setFont(this->font);
    this->mainmenuText.setString("MAIN MENU");
    this->mainmenuText.setCharacterSize(60);
    this->mainmenuText.setFillColor(Grey);
    this->mainmenuText.setOrigin(this->mainmenuText.getGlobalBounds().width / 2, 0.f);
    this->mainmenuText.setPosition(640.f, 350.f);

    //CONTINUE text
    this->continueText.setFont(this->font);
    this->continueText.setString("CONTINUE");
    this->continueText.setCharacterSize(60);
    this->continueText.setFillColor(Grey);
    this->continueText.setOrigin(this->continueText.getGlobalBounds().width / 2, 0.f);
    this->continueText.setPosition(640.f, 425.f);

    //EXIT text
    this->exitText.setFont(this->font);
    this->exitText.setString("EXIT");
    this->exitText.setCharacterSize(60);
    this->exitText.setFillColor(sf::Color::White);
    this->exitText.setOrigin(this->exitText.getGlobalBounds().width / 2, 0.f);
    this->exitText.setPosition(640.f, 500.f);
}


void Menu::initSprite()
{
    //Load menu logo
    if (!this->logo.loadFromFile("assets/menu/lee's journey.png"))
    {
        std::cout << "ERROR::MENU::INITSPRITE::Can't load file!!" << std::endl;
    }
    this->menuLogo.setTexture(this->logo);
    this->menuLogo.setPosition(200.f, 30.f);
    this->menuLogo.setScale(2.2f, 2.2f);

    //Load menu background
    if (!this->background.loadFromFile("assets/menu/menuBackground.png"))
    {
        std::cout << "ERROR::MENU::INITSPRITE::Can't load file!!" << std::endl;
    }
    this->menuBackground.setTexture(this->background);
    this->menuBackground.scale(2.f, 2.2f);
    this->menuBackground.setPosition(0.f, 0.f); 

    //Load game over background
    if (!this->gameOver.loadFromFile("assets/menu/gameover.png"))
    {
        std::cout << "ERROR::MENU::INITSPRITE::Can't load file!!" << std::endl;
    }
    this->gameOverSprite.setTexture(this->gameOver);
    this->gameOverSprite.scale(2.f, 1.5f);
    this->gameOverSprite.setPosition(0.f, 150.f);
}

void Menu::initSound()
{
    if (!this->selectSoundBuffer.loadFromFile("assets/sound/selectSound.wav"))
    {
        std::cout << "ERROR::MENU::INITSOUND::Can't load file!!" << std::endl;
    }
    this->selectSound.setBuffer(this->selectSoundBuffer);
    this->selectSound.setVolume(50.f);
}

bool Menu::isMainMenu()
{
    return this->mainMenu;
}

int Menu::updateMenu(sf::Vector2f mousePosition)
{
    static sf::Clock clock;  //Clock fix error more button pressed in one click 

    //New game
    if (this->mainMenu)
    {
        if (this->newgameText.getGlobalBounds().contains(mousePosition))
        {
            this->newgameText.setFillColor(sf::Color::Red);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && clock.getElapsedTime().asSeconds() >= 0.15f) 
            {
                this->selectSound.play();
                this->mainMenu = false;
                return 1;
            }
        }
        else
        {
            this->newgameText.setFillColor(sf::Color::White);
        }
    }
    //Return main menu
    else
    {
        if (this->mainmenuText.getGlobalBounds().contains(mousePosition))
        {
            this->mainmenuText.setFillColor(sf::Color::Red);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                this->selectSound.play();
                this->mainMenu = true;
                clock.restart();
                return 2;
            }
        }
        else
        {
            this->mainmenuText.setFillColor(sf::Color::White);
        }
    }

    //Continue game
    if (!this->mainMenu)
    {
        if (this->continueText.getGlobalBounds().contains(mousePosition))
        {
            this->continueText.setFillColor(sf::Color::Red);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                this->selectSound.play();
                return 3;
            }
        }
        else
        {
            this->continueText.setFillColor(sf::Color::White);
        }
    }
    else
    {
        this->continueText.setFillColor(this->Grey);
    }

    //Exit game
    if (this->exitText.getGlobalBounds().contains(mousePosition))
    {
        this->exitText.setFillColor(sf::Color::Red);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            return -1;
        }
    }
    else
    {
        this->exitText.setFillColor(sf::Color::White);
    }

    return 0;
}

void Menu::renderGameOver(sf::RenderTarget &target)
{
    target.draw(this->gameOverSprite);
}

void Menu::renderMenu(sf::RenderTarget &target)
{
    if (this->mainMenu)
    {
        target.draw(this->menuBackground);
        target.draw(this->newgameText);
    }
    else
    {
        target.draw(this->mainmenuText);
    }
    target.draw(this->menuLogo);
    target.draw(this->continueText);
    target.draw(this->exitText);
}
