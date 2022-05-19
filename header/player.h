#ifndef PLAYER_H
#define PLAYER_H

#include "main.h"
#include "physics.h"
#include "stats.h"

#define FRAME_WIDTH 20
#define FRAME_HEIGHT 30

class Player
{
    
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect frame;

    sf::SoundBuffer soundBuffer;
    sf::Sound sound;

    Physics *physics;
    Stats *stats;
    
    //Movement and animation variables
    sf::Clock idleTimer, runTimer, jumpTimer, fallTimer, attackTimer, hurtTimer;

    //Game logics
    bool startFrame;
    bool turnLeft;
    bool onGround;
    bool isFall;
    bool isHurt;
    bool isDie;

    //Player inits
    void initVariables();
    void initObjects();
    void initTexture();
    void initSprite();
    void initSound();

public:
    Player();
    ~Player();

    //Getter and Setter functions
    sf::FloatRect getGlobalBounds();
    void setVelocity(float v, bool dir_x);
    void setPosition(float pos, bool dir_x);
    bool hurtStats();
    bool die();

    //Player status functions
    void switchStatus();
    void switchJumpState();

    //Movement functions
    void hurtSprite();
    void setSpriteFrame();
    void resetFrameRect(sf::Event ev);
    void updateMovement();
    void updateSprite();
    
    //Animation functions
    void playerIdleAnimation();
    void playerMoveAnimation();
    void playerAttackAnimation();
    void playerJumpAnimation();
    void playerFallAnimation();


    //Core functions
    void updatePlayer();
    void renderPlayer(sf::RenderTarget &target);

};

#endif