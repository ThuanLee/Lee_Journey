#include "player.h"

void Player::updateMovement()
{
    bool isIdle = true;
    bool isAttack = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->onGround)
    {
        this->onGround = false;
        this->playerJumpAnimation();
        this->physics->jump();
        isIdle = false;
    }
    else if (this->physics->getVelocity().y > 0.f)  //Check player fall
    {
        this->isFall = true;
        this->onGround = false;
        this->playerFallAnimation();
        isIdle = false;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && this->onGround)
    {
        this->playerAttackAnimation();     
        this->sprite.move(0.05f * (this->turnLeft ? -1 : 1), 0.f);
        isIdle = false;
        isAttack = true;
    }

    if (!isAttack)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            this->turnLeft = false;
            this->playerMoveAnimation();
            this->physics->move(1.f, 0.f);
            isIdle = false;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            this->turnLeft = true;
            this->playerMoveAnimation();
            this->physics->move(-1.f, 0.f);
            isIdle = false;
        }
        else if (isIdle)
        {
            this->playerIdleAnimation();
        }
    }

}

void Player::hurtSprite()
{
    if (this->isHurt)
    {
        this->sprite.setColor(sf::Color::Red);
    }

    if (this->hurtTimer.getElapsedTime().asSeconds() >= 0.2f)
    {
        this->sprite.setColor(sf::Color::White);
        this->isHurt = false;
    }
}

void Player::setSpriteFrame()
{
    this->sprite.setTextureRect(this->frame);
    if (this->turnLeft)
    {   
        //Flip sprite
        this->sprite.setScale(-2.f, 2.f);
        this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.f, 0.f);
    }
    else
    {
        this->sprite.setScale(2.f, 2.f);
        this->sprite.setOrigin(0.f, 0.f);
    }  
}

void Player::resetFrameRect(sf::Event ev)
{
    if (ev.type == sf::Event::KeyPressed
        || ev.type == sf::Event::KeyReleased)
    {
        if (ev.key.code == sf::Keyboard::D
        || ev.key.code == sf::Keyboard::A
        || ev.key.code == sf::Keyboard::Space
        || ev.key.code == sf::Keyboard::J)
        {
            this->startFrame = true;
        }
    }
}

void Player::updateSprite()
{
    //Set up sprite frame
    this->setSpriteFrame();

    //If player hurt or not
    this->hurtSprite();

    //Move player sprite
    this->sprite.move(this->physics->getVelocity());
}