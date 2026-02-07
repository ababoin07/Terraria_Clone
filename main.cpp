#include <iostream>
#include <filesystem>

#include <SFML/Graphics.hpp>

#include "PerlinNoise.h"
#include "Vector2.h"
#include "Prng.h"

constexpr int TileSize = 16;
constexpr int TileMargin = 2;

sf::IntRect GetBlockTexture(int UIdx, int VIdx)
{
    return sf::IntRect{(TileSize + TileMargin) * UIdx, (TileSize + TileMargin) * VIdx, (TileSize + TileMargin) * (UIdx + 1) - TileMargin, (TileSize + TileMargin) * (VIdx + 1) - TileMargin};
}

PerlinNoiseGenerator PerlinNoiseGen{123};
Vec2 VectorA = {12.34, 34.34};
Vec2 VectorB = {23.45, 45.56};

PrngGenerator Random{27};

int main()
{
    sf::RenderWindow Window(sf::VideoMode(800, 600), "SFML_test");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Texture Texture;
    if (!Texture.loadFromFile("../Assets/Blocks/Blocks.png"))
        return EXIT_FAILURE;

    sf::Sprite Sprite(Texture);
    Sprite.setTextureRect(GetBlockTexture(0, 0));

    std::cout << "Current path is: " << std::filesystem::current_path() << std::endl;

    while (Window.isOpen())
    {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                Window.close();
            else if (event.type == sf::Event::Resized) {
                sf::FloatRect newView(0, 0, event.size.width, event.size.height);
                Window.setView(sf::View(newView));
            }
        }

        Window.clear();
        Window.draw(shape);
        Sprite.setPosition(sf::Mouse::getPosition(Window).x, sf::Mouse::getPosition(Window).y);
        Window.draw(Sprite);
        Window.display();
    }

    return 0;
}
