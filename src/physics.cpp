#include "physics.h"

Physics::Physics()
{
    this->initVariables();
}

Physics::~Physics()
{

}

void Physics::initVariables()
{
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->maxVelocity_X = 3.25f;
    this->maxVelocity_Y = 10.f;
    this->minVelocity = 0.055f;

    this->acceleration_X = 0.2f;
    this->jumpVelocity = -4.5f;
    this->friction = 0.905f;
    this->gravity = 0.07;
}

sf::Vector2f Physics::getVelocity()
{
    return this->velocity;
}

void Physics::setVelocity(float v, bool dir_x)
{
    if (dir_x)
    {
        this->velocity.x = v;
    }
    else
    {
        this->velocity.y = v;
    }
}

void Physics::jump()
{
    this->velocity.y = this->jumpVelocity;
}

void Physics::move(const float dir_x, const float dir_y)
{
    //Acceleration x
    if (std::abs(this->velocity.x) < this->maxVelocity_X)
    {
        this->velocity.x += dir_x * this->acceleration_X;
    }
    else 
    {
        this->velocity.x = std::abs(this->velocity.x) / this->velocity.x * this->maxVelocity_X;
    }
    
}

void Physics::updatePhysics()
{
    //Deceleration x
    this->velocity.x *= this->friction;

    if (std::abs(this->velocity.x) < this->minVelocity)
    {
        this->velocity.x = 0.f;
    }
    if (std::abs(this->velocity.y) < this->minVelocity)
    {
        this->velocity.y = 0.f;
    }

    //Gravity
    if (abs(this->velocity.y) < this->maxVelocity_Y)
    {
            this->velocity.y += this->gravity;
    }
}