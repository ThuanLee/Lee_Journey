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
    this->Level[1] = 20;
    this->Level[2] = 50;
    this->Level[3] = 70;
    this->Level[4] = 100;
    this->Level[5] = 120;

    this->clock.restart();
}

void Score::initFont()
{
    if (!this->font.loadFromFile("assets/font/AznKnucklesTrial-z85pa.ttf"))
    {
        std::cout << "ERROR::SCORE::INITFONT::Can't load file!!!" << std::endl;
    }
}

void Score::initText()
{
    //Score text
    this->scoreText.setFont(this->font);
    this->scoreText.setCharacterSize(36);
    this->scoreText.setFillColor(sf::Color::Red);
    this->scoreText.setPosition(15.f, 5.f);

    //Your score text
    this->yourScoreText.setFont(this->font);
    this->yourScoreText.setCharacterSize(36);
    this->yourScoreText.setFillColor(sf::Color::Red);

    //Restart game text
    this->restartGameText.setFont(this->font);
    this->restartGameText.setCharacterSize(24);
    this->restartGameText.setFillColor(sf::Color::Black);
    this->restartGameText.setString("Press Escape to restart game...");
    this->restartGameText.setOrigin(this->restartGameText.getGlobalBounds().width / 2, 0.f);
    this->restartGameText.setPosition(640.f, 440.f);
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

    this->string = "Score " + std::to_string(int(score));
    this->scoreText.setString(this->string);

    this->string = "Your score is " + std::to_string(int(score));
    this->yourScoreText.setString(this->string);
    this->yourScoreText.setOrigin(this->yourScoreText.getGlobalBounds().width / 2, 0.f);
    this->yourScoreText.setPosition(640.f, 400.f);
}

void Score::renderScore(sf::RenderTarget &target, bool gameOver)
{
    if (gameOver)
    {
        target.draw(this->yourScoreText);
        if (this->clock.getElapsedTime().asSeconds() > 0.4f)
        {
            target.draw(this->restartGameText);
            if (this->clock.getElapsedTime().asSeconds() > 1.f)
            {
                this->clock.restart();
            }
        }
    }
    else
    {
        target.draw(this->scoreText);
    }
}