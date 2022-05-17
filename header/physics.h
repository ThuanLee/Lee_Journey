#ifndef PHYSICS_H
#define PHYSICS_H

#include "main.h"

class Physics
{

private:
    sf::Vector2f velocity;
    float maxVelocity_X;
    float maxVelocity_Y;
    float minVelocity;

    float acceleration_X;
    float jumpVelocity;
    float friction;
    float gravity;

    void initVariables();

public:
    //Constructor, Destructor
    Physics();
    ~Physics();

    sf::Vector2f getVelocity();
    void setVelocity(float v, bool dir_x);

    void jump();
    void move(const float dir_x, const float dir_y);
    void updatePhysics();

};

#endif