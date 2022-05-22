#ifndef GAME_H
#define GAME_h

#include "main.h"
#include "player.h"
#include "map.h"
#include "menu.h"
#include "enemy.h"
#include "score.h"
#include "stats.h"

class Game
{
    
private:
    sf::RenderWindow *window;
    sf::Event ev;
    sf::Mouse mouse;
    sf::Vector2f mousePosition;

    sf::Music themeSong;

    //Objects
    Player *player;
    Map *map;
    Menu *menu;
    Enemies *enemies;
    Score *score;

    //Game logic
    bool isGamePause;
    bool isGameRestart;
    bool isGameOver;

    //Game inits
    void initVariables();
    void initWindow();
    void initOjects();
    void initThemeSong();

public:
    //Constructor, Destructor
    Game();
    ~Game();

    //Game functions
    bool running();
    void gameRestart();
    void getEvent();
    
    void updateMousePosition();
    void updateDifficulty();

    void update();
    void render();
};

#endif