#ifndef ENEMY_H
#define ENEMY_H

#include "main.h"
#include "player.h"

#define ENEMY_FRAME_WIDTH 100
#define ENEMY_FRAME_HEIGHT 100

class Enemy
{
private:
    sf::Sprite sprite;
    sf::Vector2f pos;
    std::pair<int, int> frameIdx;
    sf::IntRect frameRect;
    sf::Clock fireTimer;
    float fireFrameTime;
    float vel;
    bool dir;
    bool canKillEnemy;

    //sf::RectangleShape shape;

    void initVariables();

public:
    Enemy();
    ~Enemy();

    void initSprite(sf::Texture *texture);
    void randomPos();
    void randomDir();

    bool killEnemy();
    void enemyOutScreen();
    void insVel(float newVel);

    void updateCollision(Player *p);
    void updatePos();
    void updateFrameIdx();
    void updateSprite();
    void updateEnemy(Player *p);

    void renderEnemy(sf::RenderTarget &target);

};

class Enemies
{
private:
    sf::Texture *texture;
    std::vector<Enemy> enemies;
    sf::Clock spawnTimer;
    float spawnTime;

public:
    Enemies();
    ~Enemies();

    void initVariables();
    void initTexture();
    void spawnEnemy();

    void enemyStronger();
    void updateEnemies(Player *p);
    void renderEnemies(sf::RenderTarget &target);
};

#endif