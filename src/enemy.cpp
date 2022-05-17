#include "enemy.h"

//****************************Enemy*******************************//

Enemy::Enemy()
{
    this->initVariables();
}

Enemy::~Enemy()
{

}

void Enemy::initVariables()
{
    this->vel = 3.f;

    this->frameIdx = {0, 0};
    this->frameRect.width = ENEMY_FRAME_WIDTH;
    this->frameRect.height = ENEMY_FRAME_HEIGHT;

    this->fireTimer.restart();
    this->fireFrameTime = 0.007f; 

    this->randomDir();
    this->randomPos();

    this->canKillEnemy = false;
}

void Enemy::initSprite(sf::Texture *texture)
{
    this->sprite.setTexture(*texture);
}

void Enemy::randomDir()
{
    // 0 is LEFT, 1 is RIGHT
    dir = rand() % 2;
}

void Enemy::randomPos()
{
    if (this->dir == LEFT)
    {
        this->pos.x = -2 * ENEMY_FRAME_WIDTH;
    }
    else if (this->dir == RIGHT)
    {
        this->pos.x = WINDOW_WIDTH + 2 * ENEMY_FRAME_WIDTH;
    }
    this->pos.y = rand() % 600;
}

bool Enemy::killEnemy()
{
    return this->canKillEnemy;
}

void Enemy::enemyOutScreen()
{
    if (this->pos.x < -this->sprite.getGlobalBounds().width 
        || this->pos.x > WINDOW_WIDTH + this->sprite.getGlobalBounds().width)
    {
        this->canKillEnemy = true;
    }
}

void Enemy::updateCollision(Player *p)
{
    const float pHeight = p->getGlobalBounds().height;
    const float pWidth = p->getGlobalBounds().width;
    const float pLeft = p->getGlobalBounds().left;
    const float pTop = p->getGlobalBounds().top;

    const float eHeight = this->sprite.getGlobalBounds().height;
    const float eWidth = this->sprite.getGlobalBounds().width;
    const float eLeft = this->sprite.getGlobalBounds().left;
    const float eTop = this->sprite.getGlobalBounds().top;

    sf::FloatRect pGlobalBound(pLeft, pTop, pWidth, pHeight);
    sf::FloatRect eGlobalBound;

    if (this->dir == LEFT)
    {
        eGlobalBound = sf::FloatRect(eLeft + 90.f, eTop + 86.f, 56.f, 42.f);
    }
    else
    {
        eGlobalBound = sf::FloatRect(eLeft + 44.f, eTop + 86.f, 60.f, 42.f);
    }

    //Enemy out of screen
    this->enemyOutScreen();

    //Collision with enemy
    if (p->hurtStats() == false && pGlobalBound.intersects(eGlobalBound))
    {
        this->canKillEnemy = true;
        p->switchStatus();
    }
}

void Enemy::updatePos()
{
    if (dir == LEFT)
    {
        this->pos.x += this->vel;
    }
    else if (dir == RIGHT)
    {
        this->pos.x -= this->vel;
    }
}

void Enemy::updateFrameIdx()
{
    if (this->fireTimer.getElapsedTime().asSeconds() >= this->fireFrameTime)
    {
        if (this->frameIdx.first < 6)
        {
            this->frameIdx.first ++;
        }
        else
        {
            if (this->frameIdx.second < 6)
            {
                this->frameIdx.first = 0;
                this->frameIdx.second ++;
            }
            else
            {
                this->frameIdx = {0, 0};
            }
        }

        this->fireTimer.restart();
    }
}

void Enemy::updateSprite()
{
    this->updateFrameIdx();

    this->frameRect.top = this->frameIdx.first * ENEMY_FRAME_HEIGHT;
    this->frameRect.left = this->frameIdx.second * ENEMY_FRAME_WIDTH;
    this->sprite.setTextureRect(this->frameRect);
    this->sprite.setPosition(this->pos);

    if (this->dir == RIGHT)
    {
        this->sprite.setScale(-2.f, 2.f);
    }
    else
    {
        this->sprite.setScale(2.f, 2.f);
    }
}

void Enemy::updateEnemy(Player *p)
{
    this->updatePos();
    this->updateSprite();
    this->updateCollision(p);
}

void Enemy::renderEnemy(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}

//****************************Enemies*******************************//

Enemies::Enemies()
{
    this->initVariables();
    this->initTexture();
}

Enemies::~Enemies()
{

}

void Enemies::initVariables()
{
    this->enemies.clear();
    this->spawnTime = 0.8f;
    this->spawnTimer.restart(); 
}

void Enemies::initTexture()
{
    this->texture = new sf::Texture;
    if (!this->texture->loadFromFile("assets/enemy/fire_spritesheet.png"))
    {
        std::cout << "ERROR::ENEMIES::INITTEXTURE::Can't load image!!!" << "\n";
    }
}

void Enemies::spawnEnemy()
{
    if (this->spawnTimer.getElapsedTime().asSeconds() >= this->spawnTime)
    {
        Enemy newEnemy;
        newEnemy.initSprite(this->texture);
        this->enemies.push_back(newEnemy);
        this->spawnTimer.restart();
    }
}

void Enemies::updateEnemies(Player *p)
{
    this->spawnEnemy();

    auto it = this->enemies.begin();
    for (auto &enemy: this->enemies)
    {
        enemy.updateEnemy(p);

        if (enemy.killEnemy())
        {
            this->enemies.erase(it);
        }
        else
        {
            it++;
        }
    }
}

void Enemies::renderEnemies(sf::RenderTarget &target)
{
    for (auto enemy: this->enemies)
    {
        enemy.renderEnemy(target);
    }
}