#include "score.h"

Score::Score()
{
    this->initVariables();
    this->initFont();
    this->initText();
}

Score::~Score()
{

}

void Score::initVariables()
{
    this->score = 0.f;
    this->lv = 0;

    this->Level[0] = 0;
    this->Level[1] = 30;
    this->Level[2] = 60;
    this->Level[3] = 100;
    this->Level[4] = 150;
    this->Level[5] = 200;
}

void Score::initFont()
{
    if (!this->scoreFont.loadFromFile("assets/font/AznKnucklesTrial-z85pa.ttf"));
    {
        std::cout << "ERROR::SCORE::INITFONT::Can't load file!!!" << std::endl;
    }
}

void Score::initText()
{
    this->scoreText.setFont(this->scoreFont);
    this->scoreText.setCharacterSize(36);
    this->scoreText.setFillColor(sf::Color::Red);
    this->scoreText.setPosition(15.f, 5.f);
}

bool Score::upDiffLevel()
{
    for (int i = 1; i < LEVEL_MAX; i++)
    {
        if (this->score > Level[i] && this->lv < i)
        {
            this->lv = i;
            std::cout << "HARDER" << std::endl;
            return true;
        }
    }
    return false;
}

void Score::updateScore()
{
    this->score += 0.01f;
    this->scoreString = "Score " + std::to_string(int(score));
    this->scoreText.setString(this->scoreString);
}

void Score::renderScore(sf::RenderTarget &target)
{
    target.draw(this->scoreText);
}