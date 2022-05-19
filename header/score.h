#ifndef SCORE_H
#define SCORE_H

#include "main.h"

#define LEVEL_MAX 6

class Score
{
private:
    float score;
    std::string scoreString;
    sf::Font scoreFont;
    sf::Text scoreText;

    unsigned int lv;
    int Level[LEVEL_MAX];
    
    void initVariables();
    void initFont();
    void initText();


public:
    Score();
    ~Score();

    bool upDiffLevel();

    void updateScore();
    void renderScore(sf::RenderTarget &target);

};

#endif