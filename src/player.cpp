#include "main.h"
#include "player.h"

Player::Player()
{
    this->initVariables();
    this->initObjects();
    this->initTexture();
    this->initSprite();
}

Player::~Player()
{

}

void Player::initVariables()
{
    this->frame = sf::IntRect(0, 0, FRAME_WIDTH, FRAME_HEIGHT);

    this->idleTimer.restart();
    this->runTimer.restart();
    this->jumpTimer.restart();
    this->fallTimer.restart();
    this->attackTimer.restart();
    
    this->startFrame = true;
    this->turnLeft = false;
    this->onGround = false;
    this->isFall = true;
    this->isHurt = false;
}

void Player::initObjects()
{
    this->physics = new Physics();
    this->stats = new Stats();
}

void Player::initTexture()
{
    if (!this->texture.loadFromFile("assets/character/playerSpriteSheet.png"))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Can't load image!!!" << "\n";
    }
}

void Player::initSprite()
{
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(100.f, 300.f);
}

sf::FloatRect Player::getGlobalBounds()
{
    return this->sprite.getGlobalBounds();
}

void Player::setVelocity(float v, bool dir_x)
{
    this->physics->setVelocity(v, dir_x);
}

void Player::setPosition(float pos, bool dir_x)
{
    if (dir_x)
    {
        this->sprite.setPosition(pos, this->sprite.getPosition().y);
    }
    else
    {
        this->sprite.setPosition(this->sprite.getPosition().x, pos);
    }
}

bool Player::hurtStats()
{
    return this->isHurt;
}

void Player::switchStatus()
{
    this->stats->updateHP();
    this->isHurt = true;
    this->hurtTimer.restart();
}

void Player::switchJumpState()
{
    this->onGround = true;
    this->isFall = false;
}

void Player::updatePlayer()
{
    this->updateMovement();
    this->updateSprite();
    this->physics->updatePhysics();
}

void Player::renderPlayer(sf::RenderTarget &target)
{
    //Render character
    target.draw(this->sprite);

    //Render stats
    this->stats->renderStats(target);   
}