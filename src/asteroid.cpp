#include "../include/asteroid.h"

Asteroid::Asteroid(Vector velocity, long double radius, long double x, long double y)
{
    this->velocity = velocity;
    this->x        = x;
    this->y        = y;
    circle.setRadius(radius);
    circle.setOrigin(radius, radius);
    circle.setPosition(this->x, this->y);
    //ctor
}

void Asteroid::update(sf::Time time)
{
    x+=velocity.getXComponent()*time.asSeconds();
    y+=velocity.getYComponent()*time.asSeconds();
    circle.setPosition(x, y);
}

sf::CircleShape Asteroid::getCircle() const
{
    return circle;
}

Asteroid::~Asteroid()
{
    //dtor
}
