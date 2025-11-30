#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Ball.hpp"
#include "Bruteforce.hpp"
#include "Quadtree.hpp"

int main(int argc, char* argv[]) {
    // Setup window
    const int WIDTH = 800;
    const int HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Collision Simulation");
    window.setFramerateLimit(60);

    // Random seed
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Jumlah bola bisa diatur lewat argumen (default 50)
    int NUM_BALLS = 50;
    if (argc > 1) {
        NUM_BALLS = std::stoi(argv[1]); // contoh: ./simulasi 500
    }
// Buat bola
    std::vector<Ball> balls;
    for (int i = 0; i < NUM_BALLS; i++) {
        float x = std::rand() % WIDTH;
        float y = std::rand() % HEIGHT;
        float radius = 8 + std::rand() % 5;
        sf::Color color(rand() % 255, rand() % 255, rand() % 255);
        balls.emplace_back(x, y, radius, color);
    }

    // Mode algoritma (true = brute force, false = quadtree)
    bool useBruteForce = true;

    // Clock untuk delta time dan FPS
    sf::Clock clock;
    float fps = 1.0f;

    // Font untuk teks
    sf::Font font;
    font.loadFromFile("arial.ttf");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Toggle algoritma dengan tombol SPACE
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                useBruteForce = !useBruteForce;
            }
        }

        float dt = clock.restart().asSeconds();
        fps = 1.0f / dt;

        // Update bola
        for (auto& ball : balls) {
            ball.update(dt * 100); // kecepatan skala
            ball.checkBoundaryCollision(WIDTH, HEIGHT);
        }
         // Deteksi tabrakan
        if (useBruteForce) {
            Physics::checkCollisionsBruteForce(balls);
        } else {
            Quadtree quadtree(0, sf::FloatRect(0, 0, WIDTH, HEIGHT));
            for (auto& ball : balls) {
                quadtree.insert(&ball);
            }

            for (auto& ball : balls) {
                std::vector<Ball*> candidates;
                quadtree.retrieve(candidates, ball);
                for (auto* other : candidates) {
                    if (&ball != other && Physics::isColliding(ball, *other)) {
                        Physics::resolveCollision(ball, *other);
                    }
                }
            }
        }
// Render
        window.clear(sf::Color::Black);

        // Debug: tampilkan quadtree jika mode quadtree
        if (!useBruteForce) {
            Quadtree debugTree(0, sf::FloatRect(0, 0, WIDTH, HEIGHT));
            for (auto& ball : balls) {
                debugTree.insert(&ball);
            }
            debugTree.draw(window);
        }

        for (auto& ball : balls) {
            ball.draw(window);
        }

        // Info mode
        sf::Text modeText;
        modeText.setFont(font);
        modeText.setCharacterSize(16);
        modeText.setFillColor(sf::Color::White);
        modeText.setPosition(10, 10);
        modeText.setString(useBruteForce ? "Mode: Brute Force" : "Mode: Quadtree");
        window.draw(modeText);

        // FPS counter
        sf::Text fpsText;
        fpsText.setFont(font);
        fpsText.setCharacterSize(16);
        fpsText.setFillColor(sf::Color::Yellow);
        fpsText.setPosition(10, 30);
        fpsText.setString("FPS: " + std::to_string((int)fps));
        window.draw(fpsText);
 // Jumlah bola
        sf::Text ballCountText;
        ballCountText.setFont(font);
        ballCountText.setCharacterSize(16);
        ballCountText.setFillColor(sf::Color::Cyan);
        ballCountText.setPosition(10, 50);
        ballCountText.setString("Balls: " + std::to_string(NUM_BALLS));
        window.draw(ballCountText);

        window.display();
    }

    return 0;
}

