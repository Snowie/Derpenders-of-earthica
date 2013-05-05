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


    bool allAbove  = true;
    bool allBelow  = true;
    bool allLeft   = true;
    bool allRight  = true;
    //If any exceptions, the conditional goes false
    //for(unsigned int i = 0; i < circle.getPointCount(); ++i)
    //{
    if(circle.getRadius() + circle.getPosition().y > -1*circle.getRadius()*4)
    {
        allAbove = false;
    }
    if(circle.getRadius() + circle.getPosition().y < 1030 + circle.getRadius()*2.5*2)
    {
        allBelow = false;
    }
    if(circle.getRadius() + circle.getPosition().x > -1*circle.getRadius()*4)
    {
        allLeft = false;
    }
    if(circle.getRadius() + circle.getPosition().x < 1920 + circle.getRadius()*2.5*2)
    {
        allRight = false;
    }

    //Loop around, asteroids style.
    if(allAbove)
    {
        y = 1030+circle.getRadius()*2;
        circle.setPosition(circle.getPosition().x, y);
    }
    if(allBelow)
    {
        y = -2*circle.getRadius();
        circle.setPosition(circle.getPosition().x, y);
    }
    if(allLeft)
    {
        x = 1920 + circle.getRadius()*2;
        circle.setPosition(x, circle.getPosition().y);
    }
    if(allRight)
    {
        x = -2*circle.getRadius();
        circle.setPosition(x, circle.getPosition().y);
    }

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
