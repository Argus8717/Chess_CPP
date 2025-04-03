#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //Set window
    sf::RenderWindow window(sf::VideoMode({1920u, 1080u}), "Chessboard Display");
    window.setFramerateLimit(144);

    //Load chessboard image
    sf::Texture texture;
    if (!texture.loadFromFile("Board.png"))
        return -1; //Error if file not found

        //Create Sprite for texture
    sf::Sprite sprite(texture);

    //Main Loop
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
        window.draw(sprite);
        window.display();
    }

    return 0;
}
