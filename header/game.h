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

    enum MENU {STARTGAME = 1, EXIT = -1};

    //Objects
    Player *player;
    Map *map;
    Menu *menu;
    Enemies *enemies;
    Score *score;

    //Game logic
    bool isGamePause;
    bool isGameRestart;

    //Game inits
    void initVariables();
    void initWindow();
    void initOjects();

public:
    //Constructor, Destructor
    Game();
    ~Game();

    //Game functions
    bool running();
    void gameRestart();
    void getEvent();
    void updateMousePosition();
    void update();
    void render();


};

#endif