#include "Ball.hpp"

Ball::Ball(float x, float y,float radius,sf::Color color){
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOrigin(radius, radius); // Center origin
    shape.setPosition(x, y);

    velocity.x = (rand() % 200 - 100) / 100.0f;
    velocity.y = (rand() % 200 - 100) / 100.0f;

}

void Ball::update(float dt) {
    shape.move(velocity * dt);  
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
void Ball::checkBoundaryCollision(float width, float height) {
    sf::Vector2f pos = shape.getPosition();
    float r = shape.getRadius();

    if (pos.x - r < 0 || pos.x + r > width) {
        velocity.x *= -1;
        pos.x = std::max(r, std::min(pos.x, width - r));
    }

    if (pos.y - r < 0 || pos.y + r > height) {
        velocity.y *= -1;
        pos.y = std::max(r, std::min(pos.y, height - r));
    }

    shape.setPosition(pos);
}

sf::Vector2f Ball::getPosition() const {
    return shape.getPosition();
}

sf::Vector2f Ball::getVelocity() const {
    return velocity;
}

float Ball::getRadius() const {
    return shape.getRadius();
}

sf::Color Ball::getColor() const {
    return shape.getFillColor();
}

void Ball::setVelocity(sf::Vector2f vel) {
    velocity = vel;
}

void Ball::setPosition(sf::Vector2f pos) {
    shape.setPosition(pos);
}