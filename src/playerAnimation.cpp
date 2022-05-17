#include "player.h"

void Player::playerIdleAnimation()
{
    if (this->onGround && this->idleTimer.getElapsedTime().asSeconds() >= 0.12f)
    {
        this->frame.top = 0;
        this->frame.left += FRAME_WIDTH;
        if (this->frame.left >= FRAME_WIDTH * 4)
        {
            this->frame.left = 0;
        }  
        this->idleTimer.restart();
    }
}

void Player::playerMoveAnimation()
{
    if (this->onGround && this->runTimer.getElapsedTime().asSeconds() >= 0.09f)
    {   
        this->frame.top = FRAME_HEIGHT;
        this->frame.left += FRAME_WIDTH;
        if (this->frame.left >= FRAME_WIDTH * 6)
        {
            this->frame.left = 0;
        }
        this->runTimer.restart();
    }
}

void Player::playerJumpAnimation()
{
    if (this->jumpTimer.getElapsedTime().asSeconds() >= 0.15f)
    {
        this->frame.top = FRAME_HEIGHT * 2;
        this->frame.left = 0;
        this->jumpTimer.restart();
    }
}

void Player::playerFallAnimation()
{
    if (this->fallTimer.getElapsedTime().asSeconds() >= 0.15f)
    {
        this->frame.top = FRAME_HEIGHT * 3;
        this->frame.left += FRAME_WIDTH;
        if (this->frame.left >= FRAME_WIDTH * 2)
        {
            this->frame.left = 0;
        }
        this->fallTimer.restart();
    }
}

void Player::playerAttackAnimation()
{
    if (this->attackTimer.getElapsedTime().asSeconds() >= 0.12f)
    {
        this->frame.top = FRAME_HEIGHT * 5;
        this->frame.left += FRAME_WIDTH;
        if (this->frame.left >= FRAME_WIDTH * 5)
        {
            this->frame.left = 0;
        }
        this->attackTimer.restart();
    }
}