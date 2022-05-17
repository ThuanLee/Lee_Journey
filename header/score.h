#ifndef SCORE_H
#define SCORE_H

#include "main.h"

class Score
{
private:
    float score;
    std::string scoreString;
    sf::Font scoreFont;
    sf::Text scoreText;
    
    void initVariables();
    void initFont();
    void initText();

public:
    Score();
    ~Score();

    void updateScore();
    void renderScore(sf::RenderTarget &target);

};

#endif