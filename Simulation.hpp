#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.hpp"
#include "Bruteforce.hpp"

class Simulation {
private:
    sf::RenderWindow window;
    std::vector<Ball> balls;

public:
    Simulation(int width, int height, int numBalls);
    void run();
};
