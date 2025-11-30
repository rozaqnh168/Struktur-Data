#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP

#include <vector>
#include "Ball.hpp"

namespace Physics {

    // Mengecek apakah dua bola bertabrakan
    bool isColliding(const Ball& a, const Ball& b);

    // Menangani tabrakan dua bola (resolusi kecepatan)
    void resolveCollision(Ball& a, Ball& b);

    // Brute force collision detection untuk semua bola
    void checkCollisionsBruteForce(std::vector<Ball>& balls);

}

#endif // BRUTEFORCE_HPP
