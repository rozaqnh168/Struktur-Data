#include "Bruteforce.hpp"
#include <cmath>

namespace Physics {

    bool isColliding(const Ball& a, const Ball& b) {
        sf::Vector2f posA = a.getPosition();
        sf::Vector2f posB = b.getPosition();

        float dx = posA.x - posB.x;
        float dy = posA.y - posB.y;
        float distance = std::sqrt(dx * dx + dy * dy);

        return distance < (a.getRadius() + b.getRadius());
    }

    void resolveCollision(Ball& a, Ball& b) 
    {
        sf::Vector2f posA = a.getPosition();
        sf::Vector2f posB = b.getPosition();
        sf::Vector2f delta = posA - posB;

        float dist = std::sqrt(delta.x * delta.x + delta.y * delta.y);
        float combinedRadius = a.getRadius() + b.getRadius();

        if (dist < combinedRadius && dist > 0.0f) {
        // Koreksi posisi agar tidak overlap
        float overlap = 0.5f * (combinedRadius - dist);
        sf::Vector2f correction = (delta / dist) * overlap;
        a.setPosition(posA + correction);
        b.setPosition(posB - correction);

        // Normal dan tangent
        sf::Vector2f normal = delta / dist;
        sf::Vector2f tangent(-normal.y, normal.x);

        // Proyeksi velocity ke normal & tangent
        float v1n = a.getVelocity().x * normal.x + a.getVelocity().y * normal.y;
        float v2n = b.getVelocity().x * normal.x + b.getVelocity().y * normal.y;

        float v1t = a.getVelocity().x * tangent.x + a.getVelocity().y * tangent.y;
        float v2t = b.getVelocity().x * tangent.x + b.getVelocity().y * tangent.y;

        float m1 = a.getRadius(); // atau gunakan mass properti
        float m2 = b.getRadius();

        // Rumus momentum 1D untuk komponen normal
        float newV1n = (v1n * (m1 - m2) + 2.0f * m2 * v2n) / (m1 + m2);
        float newV2n = (v2n * (m2 - m1) + 2.0f * m1 * v1n) / (m1 + m2);

        // Gabungkan kembali ke velocity 2D
        sf::Vector2f velA = tangent * v1t + normal * newV1n;
        sf::Vector2f velB = tangent * v2t + normal * newV2n;

        a.setVelocity(velA);
        b.setVelocity(velB);
        }
    }
    void checkCollisionsBruteForce(std::vector<Ball>& balls) {
        for (size_t i = 0; i < balls.size(); ++i) {
            for (size_t j = i + 1; j < balls.size(); ++j) {
                if (isColliding(balls[i], balls[j])) {
                    resolveCollision(balls[i], balls[j]);
                }
            }
        }
    }

}
