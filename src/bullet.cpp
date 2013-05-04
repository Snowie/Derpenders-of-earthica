#include "../include/bullet.h"

Bullet::Bullet()
{
    bulletState    = false;
    bulletVelocity = Vector(0.0, 0.0);
    rectangle.setSize(sf::Vector2f(10.0, 10.0));
    rectangle.setOrigin(rectangle.getSize().x/2.0, rectangle.getSize().y/2.0);
    //ctor
}
sf::RectangleShape Bullet::getRect() const
{
    return rectangle;
}

void Bullet::activate()
{
    bulletState    = true;
    bulletVelocity = Vector(8.0l, 270.0l);
}

bool Bullet::getState() const
{
    return bulletState;
}

void Bullet::setVelocity(Vector vel)
{
    bulletVelocity = vel;
}

void Bullet::resetBull(sf::Vector2f position)
{
    //Reset our state to not in the air!
    x              = position.x;
    y              = position.y;
    bulletState    = false;
    bulletVelocity = Vector(0.0l, 270.0l);

    rectangle.setPosition(x, y);
}

void Bullet::bulletLogic(sf::Time time)
{
    //If we are in bounds...
    if(y > 0 && y < 1030)
    {
        //Update our position
        x += bulletVelocity.getXComponent()*time.asSeconds();
        y += bulletVelocity.getYComponent()*time.asSeconds();
        rectangle.setPosition(x, y);
    }
    else
    {
        //Otherwise, reset!
        bulletState = false;
    }
}
Bullet::~Bullet()
{
    //dtor
}
