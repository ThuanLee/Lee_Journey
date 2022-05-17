#include "stats.h"

Stats::Stats()
{
    this->initVariables();
    this->initTexture();
    this->initHP();
}

Stats::~Stats()
{

}

void Stats::initVariables()
{
    this->iHP = 3;
}

void Stats::initTexture()
{
    //Heart
    if (!this->heartTexture.loadFromFile("assets/icon/heart.png"))
    {
        std::cout << "ERROR::STATS::INITTEXTURE::Can't load file!!!" << "\n";
    }

    //Border
    if (!this->borderTexture.loadFromFile("assets/icon/border.png"))
    {
        std::cout << "ERROR::STATS::INITTEXTURE::Can't load file!!!" << "\n";
    }
}

void Stats::initHP()
{
    this->heartSprite.setTexture(this->heartTexture);
    this->heartSprite.setScale(2.f, 2.f);
    this->borderSprite.setTexture(this->borderTexture);
    this->borderSprite.setScale(1.7f, 1.7f);
    
    this->heartSprite.setPosition(1160.f, 5.f);
    this->HP.push_back(this->heartSprite);
    
    this->heartSprite.setPosition(1200.f, 5.f);
    this->HP.push_back(this->heartSprite);

    this->heartSprite.setPosition(1240.f, 5.f);
    this->HP.push_back(this->heartSprite);
}

void Stats::updateHP()
{
    if (this->iHP != 0)
    {
        this->borderSprite.setPosition(this->HP[iHP - 1].getPosition());
        this->HP.erase(this->HP.begin() + this->iHP - 1);
        this->HP.push_back(this->borderSprite);
        this->iHP --;
    }
}

void Stats::renderStats(sf::RenderTarget &target)
{
    for (auto heart: this->HP)
    {
        target.draw(heart);
    }
}
