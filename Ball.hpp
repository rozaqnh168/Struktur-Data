#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::Vector2f velocity;
    sf::CircleShape shape;

public:
    Ball(float x, float y, float radius, sf::Color color);

    void update(float dt);
    void draw(sf::RenderWindow& window);
    void checkBoundaryCollision(float width, float height);

    sf::Vector2f getPosition() const;
    sf::Vector2f getVelocity() const;
    float getRadius() const;
    sf::Color getColor() const;

    void setVelocity(sf::Vector2f vel);
    void setPosition(sf::Vector2f pos);
};

#endif
