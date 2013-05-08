#include "../include/asteroid.h"

Asteroid::Asteroid(Vector velocity, long double radius, long double x, long double y)
{
    this->velocity = velocity;
    this->x        = x;
    this->y        = y;

    circle.setRadius(radius);
    circle.setOrigin(radius, radius);
    circle.setPosition(this->x, this->y);

    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(3.5);
    circle.setFillColor(sf::Color::Green);
}

//To break the asteroid into smaller ones before it is deleted.
std::vector <Asteroid> Asteroid::destroy() const
{
    std::vector <Asteroid> asteroids;
    unsigned int numAsteroids = circle.getRadius()/10;

    for(unsigned int i = 0; i < numAsteroids; ++i)
    {
        unsigned int toModX=rand()%10 + 1;
        unsigned int toModY=rand()%10 + 1;

        if(toModX < 5)
            toModX = -1;
        else
            toModX = 1;

        if(toModY < 5)
            toModY = -1;
        else
            toModY = 1;

        Vector newVelocity = Vector(rand() % 80 + 41,rand()%360+1)+velocity;

        unsigned int newRadius = rand()%int(circle.getRadius())+1;

        long double newX = rand()%10*toModX + x;
        long double newY = rand()%10*toModY + y;


        asteroids.push_back(Asteroid(newVelocity, newRadius, newX, newY));
    }

    return asteroids;
}

void Asteroid::update(sf::Time time)
{
    x+=velocity.getXComponent()*time.asSeconds();
    y+=velocity.getYComponent()*time.asSeconds();


    bool allAbove  = true;
    bool allBelow  = true;
    bool allLeft   = true;
    bool allRight  = true;

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
