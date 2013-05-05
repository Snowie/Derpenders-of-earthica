#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "vector.h"
#include "player.h"
#include "asteroid.h"

class Game
{
    public:
        Game();
        virtual ~Game();
        void init();
    protected:
    private:
        void initAsteroids();
        void loop();
        bool checkColl(sf::FloatRect, sf::FloatRect) const;
        bool restartGame();
        bool restart;
        bool gameOver;
        sf::Clock clock;
        sf::Time timeFrame;
        std::vector <Asteroid*> asteroids;
        void runEvents();
        Player player;
        sf::RenderWindow App;
};

#endif // GAME_H
