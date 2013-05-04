#include "../include/player.h"
#include <iostream>
Player::Player()
{

    //Set up our player shape
    shape.setPointCount(3);
    shape.setPoint(0,sf::Vector2f(10, -20));
    shape.setPoint(1,sf::Vector2f(0,  0));
    shape.setPoint(2,sf::Vector2f(20, 0));
    shape.setOrigin(10,-10);
    x = 960;
    y = 900;
    shape.setPosition(x,y);
    //time = clock.restart();

    //ctor
}

void Player::control(sf::Time time)
{
    //If there is no input, our acceleration should be 0!
    acceleration = Vector();

    //Go forward!
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        acceleration = Vector(200, shape.getRotation()-90) + acceleration;
    }

    //Reverse!
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        acceleration = Vector(200, shape.getRotation()+90) + acceleration;
    }

    //Rotate left...
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        shape.rotate(-180.0*time.asSeconds());
    }

    //Rotate right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        shape.rotate(180.0*time.asSeconds());
    }

    //Eliminate the mineral scum!
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        //bullet.resetBull(shape.getPosition());
        bullet.activate();

        //We are in space, our bullets move with us!
        bullet.setVelocity(Vector(90, shape.getRotation()-90)+velocity);
    }

}

//Return a reference to the bullet such that its state can be modified.
Bullet * Player::getBullet()
{
    Bullet * pBull = &bullet;
    return pBull;
}

sf::ConvexShape Player::getShape() const
{
    return shape;
}

void Player::update(sf::Time time)
{
    //time = clock.restart();
    velocity = velocity + Vector(acceleration.getMagnitude()*time.asSeconds(),acceleration.getTheta());

    x += velocity.getXComponent()*time.asSeconds();
    y += velocity.getYComponent()*time.asSeconds();

    //Some variables to check if we are off screen, initally all true.
    bool allAbove  = true;
    bool allBelow  = true;
    bool allLeft   = true;
    bool allRight  = true;

    //If any exceptions, the conditional goes false
    for(unsigned int i = 0; i < shape.getPointCount(); ++i)
    {
        if(shape.getPoint(i).y + shape.getPosition().y > -40)
        {
            allAbove = false;
        }
        if(shape.getPoint(i).y + shape.getPosition().y < 1080)
        {
            allBelow = false;
        }
        if(shape.getPoint(i).x + shape.getPosition().x > -40)
        {
            allLeft = false;
        }
        if(shape.getPoint(i).x + shape.getPosition().x < 1970)
        {
            allRight = false;
        }
    }

    //Loop around, asteroids style.
    if(allAbove)
    {
        y = 1050;
        shape.setPosition(shape.getPosition().x,1050);
    }
    if(allBelow)
    {
        y = -20;
        shape.setPosition(shape.getPosition().x,-20);
    }
    if(allLeft)
    {
        x = 1940;
        shape.setPosition(1100,shape.getPosition().y);
    }
    if(allRight)
    {
        x = -20;
        shape.setPosition(-20,shape.getPosition().y);
    }

    if(!bullet.getState())
    {
        bullet.resetBull(shape.getPosition());
    }
    else
    {
        bullet.bulletLogic(time);
    }

    //Keep our shape up to date
    shape.setPosition(x, y);
}

Player::~Player()
{
    //dtor
}
