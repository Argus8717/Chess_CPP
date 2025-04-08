#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Window.h"

void moveSpriteToTarget(sf::Sprite& sprite, float targetX, float targetY)
{
    float currentX = sprite.getPosition().x;
    float currentY = sprite.getPosition().y;

    float changeX = targetX - currentX;
    float changeY = targetY - currentY;

    sprite.move(changeX, changeY);
}

struct NamedPosition
{
    std::string name;
    sf::Vector2f position;
};


//Create vectors to store positions into cells
sf::Vector2f A8(42.f, 6.f), B8(168.f, 6.f), C8(294.f, 6.f), D8(420.f, 6.f), E8(546.f, 6.f), F8(672.f, 6.f), G8(798.f, 6.f), H8(924.f, 6.f);
sf::Vector2f A7(42.f, 132.f), B7(168.f, 132.f), C7(294.f, 132.f), D7(420.f, 132.f), E7(546.f, 132.f), F7(672.f, 132.f), G7(798.f, 132.f), H7(924.f, 132.f);
sf::Vector2f A6(42.f, 258.f), B6(168.f, 258.f), C6(294.f, 258.f), D6(420.f, 258.f), E6(546.f, 258.f), F6(672.f, 258.f), G6(798.f, 258.f), H6(924.f, 258.f);
sf::Vector2f A5(42.f, 384.f), B5(168.f, 384.f), C5(294.f, 384.f), D5(420.f, 384.f), E5(546.f, 384.f), F5(672.f, 384.f), G5(798.f, 384.f), H5(924.f, 384.f);
sf::Vector2f A4(42.f, 510.f), B4(168.f, 510.f), C4(294.f, 510.f), D4(420.f, 510.f), E4(546.f, 510.f), F4(672.f, 510.f), G4(798.f, 510.f), H4(924.f, 510.f);
sf::Vector2f A3(42.f, 636.f), B3(168.f, 636.f), C3(294.f, 636.f), D3(420.f, 636.f), E3(546.f, 636.f), F3(672.f, 636.f), G3(798.f, 636.f), H3(924.f, 636.f);
sf::Vector2f A2(42.f, 762.f), B2(168.f, 762.f), C2(294.f, 762.f), D2(420.f, 762.f), E2(546.f, 762.f), F2(672.f, 762.f), G2(798.f, 762.f), H2(924.f, 762.f);
sf::Vector2f A1(42.f, 888.f), B1(168.f, 888.f), C1(294.f, 888.f), D1(420.f, 888.f), E1(546.f, 888.f), F1(672.f, 888.f), G1(798.f, 888.f), H1(924.f, 888.f);


//Convert cell position vectors to strings
std::vector<NamedPosition> namedPositions =
        {
                {"A8", A8}, {"B8", B8}, {"C8", C8}, {"D8", D8}, {"E8", E8}, {"F8", F8}, {"G8", G8}, {"H8", H8},
                {"A7", A7}, {"B7", B7}, {"C7", C7}, {"D7", D7}, {"E7", E7}, {"F7", F7}, {"G7", G7}, {"H7", H7},
                {"A6", A6}, {"B6", B6}, {"C6", C6}, {"D6", D6}, {"E6", E6}, {"F6", F6}, {"G6", G6}, {"H6", H6},
                {"A5", A5}, {"B5", B5}, {"C5", C5}, {"D5", D5}, {"E5", E5}, {"F5", F5}, {"G5", G5}, {"H5", H5},
                {"A4", A4}, {"B4", B4}, {"C4", C4}, {"D4", D4}, {"E4", E4}, {"F4", F4}, {"G4", G4}, {"H4", H4},
                {"A3", A3}, {"B3", B3}, {"C3", C3}, {"D3", D3}, {"E3", E3}, {"F3", F3}, {"G3", G3}, {"H3", H3},
                {"A2", A2}, {"B2", B2}, {"C2", C2}, {"D2", D2}, {"E2", E2}, {"F2", F2}, {"G2", G2}, {"H2", H2},
                {"A1", A1}, {"B1", B1}, {"C1", C1}, {"D1", D1}, {"E1", E1}, {"F1", F1}, {"G1", G1}, {"H1", H1}
        };

//Create vectors to store bound positions of cells
sf::Vector2f A8_bounds(A8.x + 120.f, A8.y + 120.f);
sf::Vector2f B8_bounds(B8.x + 120.f, B8.y + 120.f);
sf::Vector2f C8_bounds(C8.x + 120.f, C8.y + 120.f);
sf::Vector2f D8_bounds(D8.x + 120.f, D8.y + 120.f);
sf::Vector2f E8_bounds(E8.x + 120.f, E8.y + 120.f);
sf::Vector2f F8_bounds(F8.x + 120.f, F8.y + 120.f);
sf::Vector2f G8_bounds(G8.x + 120.f, G8.y + 120.f);
sf::Vector2f H8_bounds(H8.x + 120.f, H8.y + 120.f);

sf::Vector2f A7_bounds(A7.x + 120.f, A7.y + 120.f);
sf::Vector2f B7_bounds(B7.x + 120.f, B7.y + 120.f);
sf::Vector2f C7_bounds(C7.x + 120.f, C7.y + 120.f);
sf::Vector2f D7_bounds(D7.x + 120.f, D7.y + 120.f);
sf::Vector2f E7_bounds(E7.x + 120.f, E7.y + 120.f);
sf::Vector2f F7_bounds(F7.x + 120.f, F7.y + 120.f);
sf::Vector2f G7_bounds(G7.x + 120.f, G7.y + 120.f);
sf::Vector2f H7_bounds(H7.x + 120.f, H7.y + 120.f);

sf::Vector2f A6_bounds(A6.x + 120.f, A6.y + 120.f);
sf::Vector2f B6_bounds(B6.x + 120.f, B6.y + 120.f);
sf::Vector2f C6_bounds(C6.x + 120.f, C6.y + 120.f);
sf::Vector2f D6_bounds(D6.x + 120.f, D6.y + 120.f);
sf::Vector2f E6_bounds(E6.x + 120.f, E6.y + 120.f);
sf::Vector2f F6_bounds(F6.x + 120.f, F6.y + 120.f);
sf::Vector2f G6_bounds(G6.x + 120.f, G6.y + 120.f);
sf::Vector2f H6_bounds(H6.x + 120.f, H6.y + 120.f);

sf::Vector2f A5_bounds(A5.x + 120.f, A5.y + 120.f);
sf::Vector2f B5_bounds(B5.x + 120.f, B5.y + 120.f);
sf::Vector2f C5_bounds(C5.x + 120.f, C5.y + 120.f);
sf::Vector2f D5_bounds(D5.x + 120.f, D5.y + 120.f);
sf::Vector2f E5_bounds(E5.x + 120.f, E5.y + 120.f);
sf::Vector2f F5_bounds(F5.x + 120.f, F5.y + 120.f);
sf::Vector2f G5_bounds(G5.x + 120.f, G5.y + 120.f);
sf::Vector2f H5_bounds(H5.x + 120.f, H5.y + 120.f);

sf::Vector2f A4_bounds(A4.x + 120.f, A4.y + 120.f);
sf::Vector2f B4_bounds(B4.x + 120.f, B4.y + 120.f);
sf::Vector2f C4_bounds(C4.x + 120.f, C4.y + 120.f);
sf::Vector2f D4_bounds(D4.x + 120.f, D4.y + 120.f);
sf::Vector2f E4_bounds(E4.x + 120.f, E4.y + 120.f);
sf::Vector2f F4_bounds(F4.x + 120.f, F4.y + 120.f);
sf::Vector2f G4_bounds(G4.x + 120.f, G4.y + 120.f);
sf::Vector2f H4_bounds(H4.x + 120.f, H4.y + 120.f);

sf::Vector2f A3_bounds(A3.x + 120.f, A3.y + 120.f);
sf::Vector2f B3_bounds(B3.x + 120.f, B3.y + 120.f);
sf::Vector2f C3_bounds(C3.x + 120.f, C3.y + 120.f);
sf::Vector2f D3_bounds(D3.x + 120.f, D3.y + 120.f);
sf::Vector2f E3_bounds(E3.x + 120.f, E3.y + 120.f);
sf::Vector2f F3_bounds(F3.x + 120.f, F3.y + 120.f);
sf::Vector2f G3_bounds(G3.x + 120.f, G3.y + 120.f);
sf::Vector2f H3_bounds(H3.x + 120.f, H3.y + 120.f);

sf::Vector2f A2_bounds(A2.x + 120.f, A2.y + 120.f);
sf::Vector2f B2_bounds(B2.x + 120.f, B2.y + 120.f);
sf::Vector2f C2_bounds(C2.x + 120.f, C2.y + 120.f);
sf::Vector2f D2_bounds(D2.x + 120.f, D2.y + 120.f);
sf::Vector2f E2_bounds(E2.x + 120.f, E2.y + 120.f);
sf::Vector2f F2_bounds(F2.x + 120.f, F2.y + 120.f);
sf::Vector2f G2_bounds(G2.x + 120.f, G2.y + 120.f);
sf::Vector2f H2_bounds(H2.x + 120.f, H2.y + 120.f);

sf::Vector2f A1_bounds(A1.x + 120.f, A1.y + 120.f);
sf::Vector2f B1_bounds(B1.x + 120.f, B1.y + 120.f);
sf::Vector2f C1_bounds(C1.x + 120.f, C1.y + 120.f);
sf::Vector2f D1_bounds(D1.x + 120.f, D1.y + 120.f);
sf::Vector2f E1_bounds(E1.x + 120.f, E1.y + 120.f);
sf::Vector2f F1_bounds(F1.x + 120.f, F1.y + 120.f);
sf::Vector2f G1_bounds(G1.x + 120.f, G1.y + 120.f);
sf::Vector2f H1_bounds(H1.x + 120.f, H1.y + 120.f);

//Convert cell bound vectors to strings
std::vector<NamedPosition> namedBoundsPositions =
        {
                {"A8_bounds", A8_bounds}, {"B8_bounds", B8_bounds}, {"C8_bounds", C8_bounds}, {"D8_bounds", D8_bounds}, {"E8_bounds", E8_bounds}, {"F8_bounds", F8_bounds}, {"G8_bounds", G8_bounds}, {"H8_bounds", H8_bounds},
                {"A7_bounds", A7_bounds}, {"B7_bounds", B7_bounds}, {"C7_bounds", C7_bounds}, {"D7_bounds", D7_bounds}, {"E7_bounds", E7_bounds}, {"F7_bounds", F7_bounds}, {"G7_bounds", G7_bounds}, {"H7_bounds", H7_bounds},
                {"A6_bounds", A6_bounds}, {"B6_bounds", B6_bounds}, {"C6_bounds", C6_bounds}, {"D6_bounds", D6_bounds}, {"E6_bounds", E6_bounds}, {"F6_bounds", F6_bounds}, {"G6_bounds", G6_bounds}, {"H6_bounds", H6_bounds},
                {"A5_bounds", A5_bounds}, {"B5_bounds", B5_bounds}, {"C5_bounds", C5_bounds}, {"D5_bounds", D5_bounds}, {"E5_bounds", E5_bounds}, {"F5_bounds", F5_bounds}, {"G5_bounds", G5_bounds}, {"H5_bounds", H5_bounds},
                {"A4_bounds", A4_bounds}, {"B4_bounds", B4_bounds}, {"C4_bounds", C4_bounds}, {"D4_bounds", D4_bounds}, {"E4_bounds", E4_bounds}, {"F4_bounds", F4_bounds}, {"G4_bounds", G4_bounds}, {"H4_bounds", H4_bounds},
                {"A3_bounds", A3_bounds}, {"B3_bounds", B3_bounds}, {"C3_bounds", C3_bounds}, {"D3_bounds", D3_bounds}, {"E3_bounds", E3_bounds}, {"F3_bounds", F3_bounds}, {"G3_bounds", G3_bounds}, {"H3_bounds", H3_bounds},
                {"A2_bounds", A2_bounds}, {"B2_bounds", B2_bounds}, {"C2_bounds", C2_bounds}, {"D2_bounds", D2_bounds}, {"E2_bounds", E2_bounds}, {"F2_bounds", F2_bounds}, {"G2_bounds", G2_bounds}, {"H2_bounds", H2_bounds},
                {"A1_bounds", A1_bounds}, {"B1_bounds", B1_bounds}, {"C1_bounds", C1_bounds}, {"D1_bounds", D1_bounds}, {"E1_bounds", E1_bounds}, {"F1_bounds", F1_bounds}, {"G1_bounds", G1_bounds}, {"H1_bounds", H1_bounds}
        };



void Window::initWindow()
    {
        width = 1920u;
        height = 1080u;
        title = "Chess";
        vm = sf::VideoMode({width, height});
        window = new sf::RenderWindow(vm,title);
        window->setFramerateLimit(60);
    }

void Window::rendering()
{

//Load Chessboard
    sf::Texture boardTexture;
    boardTexture.loadFromFile("Board.png");
    sf::Sprite boardSprite(boardTexture);

//Below is code to load the pieces and set initial positions

//Load blackRook
    sf::Texture blackRookTexture;
    blackRookTexture.loadFromFile("BlackRook.png");
    sf::Sprite blackRookSprite(blackRookTexture);

//Set position
    blackRookSprite.setPosition(sf::Vector2f(42.f, 6.f));

//Load blackKnight
    sf::Texture blackKnightTexture;
    blackKnightTexture.loadFromFile("BlackKnight.png");
    sf::Sprite blackKnightSprite(blackKnightTexture);

//Set position
    blackKnightSprite.setPosition(sf::Vector2f(168.f,6.f));

//Load blackBishop
    sf::Texture blackBishopTexture;
    blackBishopTexture.loadFromFile("BlackBishop.png");
    sf::Sprite blackBishopSprite(blackBishopTexture);

//Set position
    blackBishopSprite.setPosition(sf::Vector2f(294.f,6.f));

//Load blackQueen
    sf::Texture blackQueenTexture;
    blackQueenTexture.loadFromFile("BlackQueen.png");
    sf::Sprite blackQueenSprite(blackQueenTexture);

//Set position
    blackQueenSprite.setPosition(sf::Vector2f(420.f,6.f));

//Load blackKing
    sf::Texture blackKingTexture;
    blackKingTexture.loadFromFile("BlackKing.png");
    sf::Sprite blackKingSprite(blackKingTexture);

//Set position
    blackKingSprite.setPosition(sf::Vector2f(546.f,6.f));

//Load blackBishop2
    sf::Texture blackBishop2Texture;
    blackBishop2Texture.loadFromFile("BlackBishop2.png");
    sf::Sprite blackBishop2Sprite(blackBishop2Texture);

//Set position
    blackBishop2Sprite.setPosition(sf::Vector2f(672.f,6.f));

//Load blackKnight2
    sf::Texture blackKnight2Texture;
    blackKnight2Texture.loadFromFile("BlackKnight2.png");
    sf::Sprite blackKnight2Sprite(blackKnight2Texture);

//Set position
    blackKnight2Sprite.setPosition(sf::Vector2f(798.f,6.f));

//Load blackRook
    sf::Texture blackRook2Texture;
    blackRook2Texture.loadFromFile("BlackRook2.png");
    sf::Sprite blackRook2Sprite(blackRook2Texture);

//Set position
    blackRook2Sprite.setPosition(sf::Vector2f(924.f,6.f));

//Load blackPawn
    sf::Texture blackPawnTexture;
    blackPawnTexture.loadFromFile("BlackPawn.png");
    sf::Sprite blackPawnSprite(blackPawnTexture);

//Set position
    blackPawnSprite.setPosition(sf::Vector2f(42.f,132.f));

//Load blackPawn2
    sf::Texture blackPawn2Texture;
    blackPawn2Texture.loadFromFile("BlackPawn2.png");
    sf::Sprite blackPawn2Sprite(blackPawn2Texture);

//Set position
    blackPawn2Sprite.setPosition(sf::Vector2f(168.f,132.f));

//Load blackPawn3
    sf::Texture blackPawn3Texture;
    blackPawn3Texture.loadFromFile("BlackPawn3.png");
    sf::Sprite blackPawn3Sprite(blackPawn3Texture);

//Set position
    blackPawn3Sprite.setPosition(sf::Vector2f(294.f,132.f));

//Load blackPawn4
    sf::Texture blackPawn4Texture;
    blackPawn4Texture.loadFromFile("BlackPawn4.png");
    sf::Sprite blackPawn4Sprite(blackPawn4Texture);

//Set position
    blackPawn4Sprite.setPosition(sf::Vector2f(420.f,132.f));

//Load blackPawn5
    sf::Texture blackPawn5Texture;
    blackPawn5Texture.loadFromFile("BlackPawn5.png");
    sf::Sprite blackPawn5Sprite(blackPawn5Texture);

//Set position
    blackPawn5Sprite.setPosition(sf::Vector2f(546.f,132.f));

//Load blackPawn6
    sf::Texture blackPawn6Texture;
    blackPawn6Texture.loadFromFile("BlackPawn6.png");
    sf::Sprite blackPawn6Sprite(blackPawn6Texture);

//Set position
    blackPawn6Sprite.setPosition(sf::Vector2f(672.f,132.f));

//Load blackPawn7
    sf::Texture blackPawn7Texture;
    blackPawn7Texture.loadFromFile("BlackPawn7.png");
    sf::Sprite blackPawn7Sprite(blackPawn7Texture);

//Set position
    blackPawn7Sprite.setPosition(sf::Vector2f(798.f,132.f));

//Load blackPawn8
    sf::Texture blackPawn8Texture;
    blackPawn8Texture.loadFromFile("BlackPawn8.png");
    sf::Sprite blackPawn8Sprite(blackPawn8Texture);

//Set position
    blackPawn8Sprite.setPosition(sf::Vector2f(924.f,132.f));

//Load whiteRook
    sf::Texture whiteRookTexture;
    whiteRookTexture.loadFromFile("WhiteRook.png");
    sf::Sprite whiteRookSprite(whiteRookTexture);

//Set position
    whiteRookSprite.setPosition(sf::Vector2f(42.f,888.f));

//Load whiteKnight
    sf::Texture whiteKnightTexture;
    whiteKnightTexture.loadFromFile("WhiteKnight.png");
    sf::Sprite whiteKnightSprite(whiteKnightTexture);

//Set position
    whiteKnightSprite.setPosition(sf::Vector2f(168.f,888.f));

//Load whiteBishop
    sf::Texture whiteBishopTexture;
    whiteBishopTexture.loadFromFile("WhiteBishop.png");
    sf::Sprite whiteBishopSprite(whiteBishopTexture);

//Set position
    whiteBishopSprite.setPosition(sf::Vector2f(294.f,888.f));

//Load whiteQueen
    sf::Texture whiteQueenTexture;
    whiteQueenTexture.loadFromFile("WhiteQueen.png");
    sf::Sprite whiteQueenSprite(whiteQueenTexture);

//Set position
    whiteQueenSprite.setPosition(sf::Vector2f(420.f,888.f));

//Load whiteKing
    sf::Texture whiteKingTexture;
    whiteKingTexture.loadFromFile("WhiteKing.png");
    sf::Sprite whiteKingSprite(whiteKingTexture);

//Set position
    whiteKingSprite.setPosition(sf::Vector2f(546.f,888.f));

//Load whiteBishop2
    sf::Texture whiteBishop2Texture;
    whiteBishop2Texture.loadFromFile("WhiteBishop2.png");
    sf::Sprite whiteBishop2Sprite(whiteBishop2Texture);

//Set position
    whiteBishop2Sprite.setPosition(sf::Vector2f(672.f,888.f));

//Load whiteKnight2
    sf::Texture whiteKnight2Texture;
    whiteKnight2Texture.loadFromFile("WhiteKnight2.png");
    sf::Sprite whiteKnight2Sprite(whiteKnight2Texture);

//Set position
    whiteKnight2Sprite.setPosition(sf::Vector2f(798.f,888.f));

//Load whiteRook
    sf::Texture whiteRook2Texture;
    whiteRook2Texture.loadFromFile("WhiteRook2.png");
    sf::Sprite whiteRook2Sprite(whiteRook2Texture);

//Set position
    whiteRook2Sprite.setPosition(sf::Vector2f(924.f,888.f));

//Load whitePawn
    sf::Texture whitePawnTexture;
    whitePawnTexture.loadFromFile("WhitePawn.png");
    sf::Sprite whitePawnSprite(whitePawnTexture);

//Set position
    whitePawnSprite.setPosition(sf::Vector2f(42.f,762.f));

//Load whitePawn2
    sf::Texture whitePawn2Texture;
    whitePawn2Texture.loadFromFile("WhitePawn2.png");
    sf::Sprite whitePawn2Sprite(whitePawn2Texture);

//Set position
    whitePawn2Sprite.setPosition(sf::Vector2f(168.f,762.f));

//Load whitePawn3
    sf::Texture whitePawn3Texture;
    whitePawn3Texture.loadFromFile("WhitePawn3.png");
    sf::Sprite whitePawn3Sprite(whitePawn3Texture);

//Set position
    whitePawn3Sprite.setPosition(sf::Vector2f(294.f,762.f));

//Load whitePawn4
    sf::Texture whitePawn4Texture;
    whitePawn4Texture.loadFromFile("WhitePawn4.png");
    sf::Sprite whitePawn4Sprite(whitePawn4Texture);

//Set position
    whitePawn4Sprite.setPosition(sf::Vector2f(420.f,762.f));

//Load whitePawn5
    sf::Texture whitePawn5Texture;
    whitePawn5Texture.loadFromFile("WhitePawn5.png");
    sf::Sprite whitePawn5Sprite(whitePawn5Texture);

//Set position
    whitePawn5Sprite.setPosition(sf::Vector2f(546.f,762.f));

//Load whitePawn6
    sf::Texture whitePawn6Texture;
    whitePawn6Texture.loadFromFile("WhitePawn6.png");
    sf::Sprite whitePawn6Sprite(whitePawn6Texture);

//Set position
    whitePawn6Sprite.setPosition(sf::Vector2f(672.f,762.f));

//Load whitePawn7
    sf::Texture whitePawn7Texture;
    whitePawn7Texture.loadFromFile("WhitePawn7.png");
    sf::Sprite whitePawn7Sprite(whitePawn7Texture);

//Set position
    whitePawn7Sprite.setPosition(sf::Vector2f(798.f,762.f));

//Load whitePawn8
    sf::Texture whitePawn8Texture;
    whitePawn8Texture.loadFromFile("WhitePawn8.png");
    sf::Sprite whitePawn8Sprite(whitePawn8Texture);

//Set position
    whitePawn8Sprite.setPosition(sf::Vector2f(924.f,762.f));

    //Load highlight
    sf::Texture pieceHighlightTexture;
    pieceHighlightTexture.loadFromFile("PieceHighlight.png");
    sf::Sprite pieceHighlightSprite(pieceHighlightTexture);


    window->clear();

    //Drawing!
    window->draw(boardSprite);
    window->draw(whiteKingSprite);
    window->draw(blackKingSprite);
    window->draw(whiteQueenSprite);
    window->draw(blackQueenSprite);
    window->draw(whiteRookSprite);
    window->draw(blackRookSprite);
    window->draw(whiteRook2Sprite);
    window->draw(blackRook2Sprite);
    window->draw(whiteKnightSprite);
    window->draw(blackKnightSprite);
    window->draw(whiteKnight2Sprite);
    window->draw(blackKnight2Sprite);
    window->draw(whiteBishopSprite);
    window->draw(blackBishopSprite);
    window->draw(whiteBishop2Sprite);
    window->draw(blackBishop2Sprite);
    window->draw(whitePawnSprite);
    window->draw(blackPawnSprite);
    window->draw(whitePawn2Sprite);
    window->draw(blackPawn2Sprite);
    window->draw(whitePawn3Sprite);
    window->draw(blackPawn3Sprite);
    window->draw(whitePawn4Sprite);
    window->draw(blackPawn4Sprite);
    window->draw(whitePawn5Sprite);
    window->draw(blackPawn5Sprite);
    window->draw(whitePawn6Sprite);
    window->draw(blackPawn6Sprite);
    window->draw(whitePawn7Sprite);
    window->draw(blackPawn7Sprite);
    window->draw(whitePawn8Sprite);
    window->draw(blackPawn8Sprite);

    window->draw(pieceHighlightSprite);

    window->display();
}

void Window::pollEvents()
    {
        //Load highlight
        sf::Texture pieceHighlightTexture;
        pieceHighlightTexture.loadFromFile("PieceHighlight.png");
        sf::Sprite pieceHighlightSprite(pieceHighlightTexture);


    if (window->hasFocus())
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
                sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
                for (size_t i = 0; i < namedPositions.size(); ++i)
                {
                    sf::Vector2f topLeft = namedPositions[i].position;
                    sf::Vector2f bottomRight = namedBoundsPositions[i].position;

                    if (mousePosF.x >= topLeft.x && mousePosF.x <= bottomRight.x &&
                        mousePosF.y >= topLeft.y && mousePosF.y <= bottomRight.y)
                    {
                        pieceHighlightSprite.setPosition(sf::Vector2f (mousePosition.x, mousePosition.y));
                        break;
                    }
                }
            } else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
            {

            }
        }

        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            } else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                {
                    window->close();
                }
            }
        }
    }

void Window::updating()
    {
        pollEvents();
    }


Window::Window()
    {
        initWindow();
    }

Window::~Window()
    {
        delete window;
    }

void Window::running()

{
    while (window->isOpen())
    {
        updating();
        rendering();
    }
}
