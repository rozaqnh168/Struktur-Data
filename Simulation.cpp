#include "Simulation.hpp"
#include "Bruteforce.hpp"
#include <cstdlib>
#include <ctime>

Simulation::Simulation(int width, int height, int numBalls)
    : window(sf::VideoMode(width, height), "Physics Simulation") {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (int i = 0; i < numBalls; ++i) {
        float x = std::rand() % width;
        float y = std::rand() % height;
        float vx = ((std::rand() % 100) / 100.0f - 0.5f) * 2.0f;
        float vy = ((std::rand() % 100) / 100.0f - 0.5f) * 2.0f;
        balls.emplace_back(x, y, vx, vy);
    }
}

void Simulation::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (auto& b : balls)
            b.update(window.getSize().x, window.getSize().y);

        BruteForce::detectCollisions(balls);

        window.clear();
        for (auto& b : balls)
            b.draw(window);
        window.display();
    }
}
