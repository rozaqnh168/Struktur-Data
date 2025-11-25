#include "Ball.hpp"

Ball::Ball(float x, float y, float vx, float vy, float r)
    : position(x, y), velocity(vx, vy), radius(r), shape(r) {
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Green);
}

void Ball::update(float windowWidth, float windowHeight) {
    position += velocity;

    if (position.x < 0 || position.x + radius * 2 > windowWidth)
        velocity.x *= -1;
    if (position.y < 0 || position.y + radius * 2 > windowHeight)
        velocity.y *= -1;

    shape.setPosition(position);
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

const sf::Vector2f& Ball::getPosition() const { return position; }
const sf::Vector2f& Ball::getVelocity() const { return velocity; }
void Ball::setVelocity(const sf::Vector2f& v) { velocity = v; }
float Ball::getRadius() const { return radius; }
