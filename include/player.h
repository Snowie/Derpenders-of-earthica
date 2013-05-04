#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "vector.h"
#include "bullet.h"

class Player
{
    public:
        Player();
        virtual ~Player();
        void control(sf::Time time);
        void update(sf::Time time);
        sf::ConvexShape getShape() const;
        Bullet * getBullet();

    protected:
    private:

        Bullet bullet;
        sf::ConvexShape shape;
        Vector velocity;
        Vector acceleration;

        double x, y;
};

#endif // PLAYER_H
