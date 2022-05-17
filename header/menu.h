#ifndef MENU_H
#define MENU_H

#include "main.h"

class Menu
{
private:
    sf::Font font;
    sf::Text newgameText, mainmenuText, continueText, exitText;
    sf::Texture logo, background;
    sf::Sprite menuLogo, menuBackground;
    sf::Color Grey;
    
    //Logic variables
    bool mainMenu;

    //Init functions
    void initVariables();
    void initFont();
    void initText();
    void initSprite();


public:
    Menu();
    ~Menu();

    int updateMenu(sf::Vector2f mousePosition);
    void renderMenu(sf::RenderTarget &target);

};

#endif