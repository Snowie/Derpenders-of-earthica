#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

#include "vector.h"

class Bullet
{
    public:
        Bullet();
        virtual ~Bullet();
        sf::RectangleShape getRect() const;
        void resetBull(sf::Vector2f);
        void setVelocity(Vector);
        bool getState() const;
        void activate();
        void bulletLogic(sf::Time);
    protected:
    private:
        sf::RectangleShape rectangle;
        bool bulletState;
        double x, y;
        Vector bulletVelocity;
};

#endif // BULLET_H
