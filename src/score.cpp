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
    this->scoreText.setCharacterSize(48);
    this->scoreText.setFillColor(sf::Color::Red);
    this->scoreText.setPosition(15.f, 5.f);
}

void Score::updateScore()
{
    this->score += 0.01f;
    this->scoreString = "Score: " + std::to_string(int(score));
    this->scoreText.setString(this->scoreString);
}

void Score::renderScore(sf::RenderTarget &target)
{
    target.draw(this->scoreText);
}