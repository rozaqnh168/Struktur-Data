#include "Quadtree.hpp"

Quadtree::Quadtree(int level, sf::FloatRect bounds)
    : level(level), bounds(bounds) {
    for (int i = 0; i < 4; i++) {
        nodes[i] = nullptr;
    }
}

Quadtree::~Quadtree() {
    clear();
}

void Quadtree::clear() {
    objects.clear();
    for (int i = 0; i < 4; i++) {
        if (nodes[i] != nullptr) {
            nodes[i]->clear();
            delete nodes[i];
            nodes[i] = nullptr;
        }
    }
}

void Quadtree::split() {
    float subWidth = bounds.width / 2.0f;
    float subHeight = bounds.height / 2.0f;
    float x = bounds.left;
    float y = bounds.top;

    nodes[0] = new Quadtree(level + 1, sf::FloatRect(x + subWidth, y, subWidth, subHeight)); // kanan atas
    nodes[1] = new Quadtree(level + 1, sf::FloatRect(x, y, subWidth, subHeight));            // kiri atas
    nodes[2] = new Quadtree(level + 1, sf::FloatRect(x, y + subHeight, subWidth, subHeight));// kiri bawah
    nodes[3] = new Quadtree(level + 1, sf::FloatRect(x + subWidth, y + subHeight, subWidth, subHeight));// kanan bawah
}

int Quadtree::getIndex(const Ball& ball) const {
    int index = -1;
    double verticalMidpoint = bounds.left + bounds.width / 2.0;
    double horizontalMidpoint = bounds.top + bounds.height / 2.0;

    sf::Vector2f pos = ball.getPosition();
    float r = ball.getRadius();

    bool topQuadrant = (pos.y - r < horizontalMidpoint && pos.y + r < horizontalMidpoint);
    bool bottomQuadrant = (pos.y - r > horizontalMidpoint);

    if (pos.x - r < verticalMidpoint && pos.x + r < verticalMidpoint) {
        if (topQuadrant) index = 1; // kiri atas
        else if (bottomQuadrant) index = 2; // kiri bawah
    }
    else if (pos.x - r > verticalMidpoint) {
        if (topQuadrant) index = 0; // kanan atas
        else if (bottomQuadrant) index = 3; // kanan bawah
    }

    return index;
}

void Quadtree::insert(Ball* ball) {
    if (nodes[0] != nullptr) {
        int index = getIndex(*ball);
        if (index != -1) {
            nodes[index]->insert(ball);
            return;
        }
    }

    objects.push_back(ball);

    if (objects.size() > 5 && level < 5) { // threshold
        if (nodes[0] == nullptr) {
            split();
        }

        auto it = objects.begin();
        while (it != objects.end()) {
            int index = getIndex(**it);
            if (index != -1) {
                nodes[index]->insert(*it);
                it = objects.erase(it);
            } else {
                ++it;
            }
        }
    }
}

void Quadtree::retrieve(std::vector<Ball*>& returnObjects, const Ball& ball) {
    int index = getIndex(ball);
    if (index != -1 && nodes[0] != nullptr) {
        nodes[index]->retrieve(returnObjects, ball);
    }

    returnObjects.insert(returnObjects.end(), objects.begin(), objects.end());
}

void Quadtree::draw(sf::RenderWindow& window) {
    sf::RectangleShape rect;
    rect.setPosition(bounds.left, bounds.top);
    rect.setSize(sf::Vector2f(bounds.width, bounds.height));
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    window.draw(rect);

    for (int i = 0; i < 4; i++) {
        if (nodes[i] != nullptr) {
            nodes[i]->draw(window);
        }
    }
}

