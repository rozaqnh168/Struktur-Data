#pragma once
#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    float radius;
    sf::CircleShape shape;

public:
    Ball(float x, float y, float vx, float vy, float r = 5.0f);

    void update(float windowWidth, float windowHeight);
    void draw(sf::RenderWindow& window);

    const sf::Vector2f& getPosition() const;
    const sf::Vector2f& getVelocity() const;
    void setVelocity(const sf::Vector2f& v);
    float getRadius() const;
};
