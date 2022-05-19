#ifndef STATS_H
#define STATS_H

#include "main.h"

class Stats
{
private:

    int iHP;

    sf::Texture heartTexture;
    sf::Sprite heartSprite;
    sf::Texture borderTexture;
    sf::Sprite borderSprite;
    std::vector<sf::Sprite> HP;

    void initVariables();
    void initTexture();
    void initHP();

public:
    Stats();
    ~Stats();

    bool updateHP();
    void renderStats(sf::RenderTarget &target);
};

#endif