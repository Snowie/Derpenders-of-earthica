#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>

#include "vector.h"

class Asteroid
{
    public:
        Asteroid(Vector, long double, long double, long double);
        virtual ~Asteroid();
        sf::CircleShape getCircle() const;
        void update(sf::Time time);
    protected:
    private:
        Vector velocity;
        sf::CircleShape circle;
        long double x;
        long double y;

};

#endif // ASTEROID_H
