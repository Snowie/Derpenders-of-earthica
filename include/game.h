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

        //These set up the state of the game
        bool restartGame();
        void initAsteroids();

        //These are the functions that continually run...
        void loop();
        bool checkColl(sf::FloatRect, sf::FloatRect) const;
        void runEvents();

        //Miscellaneous state variables
        bool restart;
        bool gameOver;

        //SFML stuffs
        sf::RenderWindow App;
        sf::Clock clock;
        sf::Time timeFrame;

        //The only two special objects
        std::vector <Asteroid> asteroids;
        Player player;
};

#endif // GAME_H
