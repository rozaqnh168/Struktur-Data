#include "Bruteforce.hpp"
#include <cmath>

void BruteForce::detectCollisions(std::vector<Ball>& balls) {
    for (size_t i = 0; i < balls.size(); ++i) {
        for (size_t j = i + 1; j < balls.size(); ++j) {
            float dx = balls[i].getPosition().x - balls[j].getPosition().x;
            float dy = balls[i].getPosition().y - balls[j].getPosition().y;
            float dist = std::sqrt(dx * dx + dy * dy);
            if (dist < balls[i].getRadius() + balls[j].getRadius()) {
                sf::Vector2f temp = balls[i].getVelocity();
                balls[i].setVelocity(balls[j].getVelocity());
                balls[j].setVelocity(temp);
            }
        }
    }
}
