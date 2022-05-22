#ifndef MENU_H
#define MENU_H

#include "main.h"

class Menu
{
private:
    sf::Font font;
    sf::Text newgameText, mainmenuText, continueText, exitText, scoreText;
    sf::Texture logo, background, gameOver;
    sf::Sprite menuLogo, menuBackground, gameOverSprite;
    sf::Color Grey;
    
    sf::SoundBuffer selectSoundBuffer;
    sf::Sound selectSound;

    //Logic variables
    bool mainMenu;
    bool isGameOver;

    //Init functions
    void initVariables();
    void initFont();
    void initText();
    void initSprite();
    void initSound();


public:
    Menu();
    ~Menu();

    bool isMainMenu();

    int updateMenu(sf::Vector2f mousePosition);
    void renderGameOver(sf::RenderTarget &target);
    void renderMenu(sf::RenderTarget &target);

};

#endif