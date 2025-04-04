#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Set window
    sf::RenderWindow window(sf::VideoMode({1920u, 1080u}), "Chessboard Display");
    window.setFramerateLimit(144);

    // Load chessboard image
    sf::Texture boardTexture;
    if (!boardTexture.loadFromFile("Board.png"))
        return -1; // Error if file not found

    sf::Sprite boardSprite(boardTexture);

    // Load pawn image
    sf::Texture whitePawnTexture;
    if (!whitePawnTexture.loadFromFile("WhitePawn.png"))
        return -1; // Error if file not found

    sf::Sprite whitePawnSprite(whitePawnTexture);

    // Set pawn position (example: on e2 square, adjust as needed)
    whitePawnSprite.setPosition(sf::Vector2f(127.f, 127.f));

    // Load pawn image
    sf::Texture blackPawnTexture;
    if (!blackPawnTexture.loadFromFile("BlackPawn.png"))
        return -1; // Error if file not found

    sf::Sprite blackPawnSprite(blackPawnTexture);

    // Set pawn position (example: on e2 square, adjust as needed)
    blackPawnSprite.setPosition(sf::Vector2f(327.f, 327.f));

    // Main Loop
    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        window.draw(boardSprite); // Draw the chessboard
        window.draw(whitePawnSprite);  // Draw the pawn
        window.draw(blackPawnSprite);  // Draw the pawn
        window.display();
    }

    return 0;
}
