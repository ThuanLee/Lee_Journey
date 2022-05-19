#include "map.h"

Map::Map()
{
    this->initMap();
    this->initCollider();
}

Map::~Map()
{

}

void Map::initMap()
{
    if (!this->mapTexture.loadFromFile("assets/map/platform.png"))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Can't load image!!!" << "\n";
    }
    this->mapSprite.setTexture(this->mapTexture);
    this->mapSprite.scale(2.f, 2.f);
}

void Map::initCollider()
{
    this->colliders.push_back(sf::FloatRect(0.f, 604.f, 430.f, 114.f));     //platform 1
    this->colliders.push_back(sf::FloatRect(430.f, 668.f, 184.f, 50.f));    //platform 2
    this->colliders.push_back(sf::FloatRect(614.f, 604.f, 670.f, 114.f));   //platform 3
    this->colliders.push_back(sf::FloatRect(682.f, 476.f, 122.f, 8.f));     //platform 4
    this->colliders.push_back(sf::FloatRect(402.f, 340.f, 162.f, 44.f));    //platform 5
    this->colliders.push_back(sf::FloatRect(852.f, 350.f, 152.f, 42.f));    //platform 6
    this->colliders.push_back(sf::FloatRect(76.f, 218.f, 222.f, 58.f));     //platform 7
    this->colliders.push_back(sf::FloatRect(662.f, 208.f, 104.f, 36.f));    //platform 8
    this->colliders.push_back(sf::FloatRect(936.f, 122.f, 168.f, 44.f));    //platform 9
}

void Map::checkCollision(Player *p)
{
    const float pHeight = p->getGlobalBounds().height;
    const float pWidth = p->getGlobalBounds().width;
    const float pLeft = p->getGlobalBounds().left;
    const float pRight = p->getGlobalBounds().left + pWidth;
    const float pTop = p->getGlobalBounds().top;
    const float pBottom = p->getGlobalBounds().top + pHeight - 2.f; //Error playerSprite
    sf::FloatRect pGlobalBound(pLeft, pTop, pWidth, pHeight);

    const bool dir_x = true, dir_y = false;

    //Collision with left window
    if (pLeft < 0.f)
    {
        p->setVelocity(0.f, dir_x);
        p->setPosition(0.f, dir_x);
    }

    //Collision with right window
    if (pLeft + pWidth > WINDOW_WIDTH)
    {
        p->setVelocity(0.f, dir_x);
        p->setPosition(WINDOW_WIDTH - pWidth, dir_x);
    }
    
    //Collision with collider
    for (auto collider: this->colliders)
    {
        if (pGlobalBound.intersects(collider))
        {
            //Collision with top of collider
            if (pTop < collider.top
                && pLeft < collider.left + collider.width
                && pRight > collider.left
                && pBottom < collider.top + collider.height)
            {
                p->switchJumpState();
                p->setVelocity(0.f, dir_y);
                p->setPosition(collider.top - pHeight + 1.f, dir_y);
            }
            //Collison with bottom of collider
            else if (pTop > collider.top
                && pLeft < collider.left + collider.width
                && pRight > collider.left
                && pBottom > collider.top + collider.height)
            {
                p->setVelocity(0.f, dir_y);
                p->setPosition(collider.top + collider.height, dir_y);
            }

            //Collision with left of collider
            if (pTop < collider.top + collider.height
                && pLeft < collider.left
                && pRight < collider.left + collider.width
                && pBottom > collider.top)
            {
                //p->setVelocity(0.f, dir_x);
                p->setPosition(collider.left - pWidth - 1.f, dir_x);
            }
            //Collision with right of collider
            else if (pTop < collider.top + collider.height
                && pLeft > collider.left
                && pRight > collider.left + collider.width
                && pBottom > collider.top)
            {
                //p->setVelocity(0.f, dir_x);
                p->setPosition(collider.left + collider.width + 1.f, dir_x);
            }
        }
    }

}

void Map::renderMap(sf::RenderTarget &target)
{
    target.draw(this->mapSprite);
}