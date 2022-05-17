#ifndef MAP_H
#define MAP_H

#include "main.h"
#include "player.h"

class Map
{
    
private:

    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    std::vector<sf::FloatRect> colliders;

    void initMap();
    void initCollider();

public:
    Map();
    ~Map();

    void checkCollision(Player *p);
    void renderMap(sf::RenderTarget &target);    

};


#endif