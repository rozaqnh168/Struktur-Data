#ifndef QUADTREE_HPP
#define QUADTREE_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "Ball.hpp"

class Quadtree {
public:
    Quadtree(int level, sf::FloatRect bounds);
    ~Quadtree();

    void clear();
    void split();
    int getIndex(const Ball& ball) const;
    void insert(Ball* ball);
    void retrieve(std::vector<Ball*>& returnObjects, const Ball& ball);

    // Debug: menggambar batas quadtree
    void draw(sf::RenderWindow& window);

private:
    int level;                          // kedalaman node
    std::vector<Ball*> objects;         // bola yang ada di node ini
    sf::FloatRect bounds;               // area node
    Quadtree* nodes[4];                 // anak node (4 kuadran)
};
#endif // QUADTREE_HPP