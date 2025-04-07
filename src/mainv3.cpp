// Coder/Developers: Benjamin Hall & Ryne Gall
// Class: COP 2006, Spring 2024
// Date: April 8, 2024
// Description: C Program to Play Chess!
// Log: March, 2024: Pixel Art Creation & Raylib Troubleshooting
// Log: April 1, 2024: Switched to SFML, tested the program
// Log: April 3, 2024: Created basic main loop to open window, added all files
// Log: April 4, 2024: Drew all pieces + chessboard, found their positions
// Log: April 5, 2024: Created main game loop

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <SFML/Window/Keyboard.hpp> 
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class Piece {
public:
    virtual std::vector<sf::Vector2f> getValidMoves(sf::Vector2f position, bool isWhite) = 0; // Pure virtual method for valid moves
    virtual bool isWhitePiece() const = 0;  // Return whether the piece is white or black
    virtual std::string getType() const = 0; // Return the type of piece (King, Queen, etc.)
    virtual ~Piece() {}
};


class King : public Piece {
public:
    std::vector<sf::Vector2f> getValidMoves(sf::Vector2f position, bool isWhite) override {
        std::vector<sf::Vector2f> validMoves;

        // Normal moves: One square in any direction
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;  // Skip the current position
                sf::Vector2f move(position.x + dx * 42.f, position.y + dy * 42.f); // Assuming each square is 42px
                validMoves.push_back(move);
            }
        }

        // Castling logic (simplified for now, does not check for check or other castling rules)
        if (isWhite) {
            // Can castle on White's side if no pieces are in between and the king hasn't moved
            // The logic to handle castling will need further conditions depending on game rules
        } else {
            // Same for Black's side
        }

        return validMoves;
    }

    bool isWhitePiece() const override {
        return true; // or false, depending on the piece color
    }

    std::string getType() const override {
        return "King";
    }
};

class Queen : public Piece {
public:
    std::vector<sf::Vector2f> getValidMoves(sf::Vector2f position, bool isWhite) override {
        std::vector<sf::Vector2f> validMoves;

        // Rook-like moves (vertical and horizontal)
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                for (int i = 1; i <= 7; ++i) {
                    sf::Vector2f move(position.x + dx * 42.f * i, position.y + dy * 42.f * i);
                    validMoves.push_back(move);
                }
            }
        }

        return validMoves;
    }

    bool isWhitePiece() const override {
        return true;  // or false depending on the piece color
    }

    std::string getType() const override {
        return "Queen";
    }
};

class Rook : public Piece {
public:
    std::vector<sf::Vector2f> getValidMoves(sf::Vector2f position, bool isWhite) override {
        std::vector<sf::Vector2f> validMoves;

        // Rook-like moves (vertical and horizontal)
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx != 0 && dy != 0) continue; // Skip diagonal moves
                for (int i = 1; i <= 7; ++i) {
                    sf::Vector2f move(position.x + dx * 42.f * i, position.y + dy * 42.f * i);
                    validMoves.push_back(move);
                }
            }
        }

        return validMoves;
    }

    bool isWhitePiece() const override {
        return true;
    }

    std::string getType() const override {
        return "Rook";
    }
};

class Bishop : public Piece {
public:
    std::vector<sf::Vector2f> getValidMoves(sf::Vector2f position, bool isWhite) override {
        std::vector<sf::Vector2f> validMoves;

        // Diagonal moves (4 directions)
        for (int dx = -1; dx <= 1; dx += 2) {
            for (int dy = -1; dy <= 1; dy += 2) {
                for (int i = 1; i <= 7; ++i) {
                    sf::Vector2f move(position.x + dx * 42.f * i, position.y + dy * 42.f * i);
                    validMoves.push_back(move);
                }
            }
        }

        return validMoves;
    }

    bool isWhitePiece() const override {
        return true;
    }

    std::string getType() const override {
        return "Bishop";
    }
};

class Knight : public Piece {
public:
    std::vector<sf::Vector2f> getValidMoves(sf::Vector2f position, bool isWhite) override {
        std::vector<sf::Vector2f> validMoves;

        // Knight moves in an L shape: 2 squares in one direction, 1 square perpendicular
        int moves[8][2] = {
                {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
        };

        for (auto& move : moves) {
            sf::Vector2f newPos(position.x + move[0] * 42.f, position.y + move[1] * 42.f);
            validMoves.push_back(newPos);
        }

        return validMoves;
    }

    bool isWhitePiece() const override {
        return true;
    }

    std::string getType() const override {
        return "Knight";
    }
};

class Pawn : public Piece {
public:
    bool isWhitePiece() const override {
        return true;
    }

    std::string getType() const override {
        return "Pawn";
    }

    std::vector<sf::Vector2f> getValidMoves(sf::Vector2f position, bool isWhite) override {
        std::vector<sf::Vector2f> validMoves;

        // Pawn moves: One square forward
        int direction = isWhite ? -1 : 1;  // White pawns move up, black down

        // Standard move
        sf::Vector2f oneSquareMove(position.x, position.y + direction * 42.f);
        validMoves.push_back(oneSquareMove);

        // First move can be two squares forward
        if ((isWhite && position.y == 762.f) || (!isWhite && position.y == 132.f)) {
            sf::Vector2f twoSquareMove(position.x, position.y + direction * 84.f);
            validMoves.push_back(twoSquareMove);
        }

        // Capturing moves
        sf::Vector2f captureLeft(position.x - 42.f, position.y + direction * 42.f);
        sf::Vector2f captureRight(position.x + 42.f, position.y + direction * 42.f);
        validMoves.push_back(captureLeft);
        validMoves.push_back(captureRight);

        return validMoves;
    }
};

class Check {
public:
    bool isOccupied(sf::Vector2f position, const std::vector<Piece*>& pieces) {
        // Check if a square is occupied by any piece
        for (const auto& piece : pieces) {
            // Here we would also need to check if the piece occupies this position
            // based on its current position, not just type
        }
        return false; // Example
    }

    bool isCheck(std::vector<Piece*>& pieces, bool isWhite) {
        // Logic to check if the king is in check (simplified)
        for (auto& piece : pieces) {
            if (piece->isWhitePiece() != isWhite) {
                // Check if the piece can move to the position of the king
            }
        }
        return false; // Simplified
    }

    bool isCheckmate(std::vector<Piece*>& pieces, bool isWhite) {
        // Logic for checkmate: if the king can't move or escape check
        return false; // Simplified
    }
};

int main()
{
    struct NamedPosition
    {
        std::string name;
        sf::Vector2f position;
    };

    //Create Window
    sf::RenderWindow window(sf::VideoMode({1920u, 1080u}), "Window");
    window.setFramerateLimit(144);

    //Load Chessboard
    sf::Texture boardTexture;
    if (!boardTexture.loadFromFile("Board.png"))
        return -1; //Error if file not found

    sf::Sprite boardSprite(boardTexture);

    //Below is code to load the pieces and set initial positions

    //Load blackRook
    sf::Texture blackRookTexture;
    if (!blackRookTexture.loadFromFile("BlackRook.png"))
        return -1; //Error if file not found

    sf::Sprite blackRookSprite(blackRookTexture);

    //Set position
    blackRookSprite.setPosition(sf::Vector2f(42.f, 6.f));

    //Load blackKnight
    sf::Texture blackKnightTexture;
    if (!blackKnightTexture.loadFromFile("BlackKnight.png"))
        return -1; //Error if file not found

    sf::Sprite blackKnightSprite(blackKnightTexture);

    //Set position
    blackKnightSprite.setPosition(sf::Vector2f(168.f,6.f));

    //Load blackBishop
    sf::Texture blackBishopTexture;
    if (!blackBishopTexture.loadFromFile("BlackBishop.png"))
        return -1; //Error if file not found

    sf::Sprite blackBishopSprite(blackBishopTexture);

    //Set position
    blackBishopSprite.setPosition(sf::Vector2f(294.f,6.f));

    //Load blackQueen
    sf::Texture blackQueenTexture;
    if (!blackQueenTexture.loadFromFile("BlackQueen.png"))
        return -1; //Error if file not found

    sf::Sprite blackQueenSprite(blackQueenTexture);

    //Set position
    blackQueenSprite.setPosition(sf::Vector2f(420.f,6.f));

    //Load blackKing
    sf::Texture blackKingTexture;
    if (!blackKingTexture.loadFromFile("BlackKing.png"))
        return -1; //Error if file not found

    sf::Sprite blackKingSprite(blackKingTexture);

    //Set position
    blackKingSprite.setPosition(sf::Vector2f(546.f,6.f));

    //Load blackBishop2
    sf::Texture blackBishop2Texture;
    if (!blackBishop2Texture.loadFromFile("BlackBishop2.png"))
        return -1; //Error if file not found

    sf::Sprite blackBishop2Sprite(blackBishop2Texture);

    //Set position
    blackBishop2Sprite.setPosition(sf::Vector2f(672.f,6.f));

    //Load blackKnight2
    sf::Texture blackKnight2Texture;
    if (!blackKnight2Texture.loadFromFile("BlackKnight2.png"))
        return -1; //Error if file not found

    sf::Sprite blackKnight2Sprite(blackKnight2Texture);

    //Set position
    blackKnight2Sprite.setPosition(sf::Vector2f(798.f,6.f));

    //Load blackRook
    sf::Texture blackRook2Texture;
    if (!blackRook2Texture.loadFromFile("BlackRook2.png"))
        return -1; //Error if file not found

    sf::Sprite blackRook2Sprite(blackRook2Texture);

    //Set position
    blackRook2Sprite.setPosition(sf::Vector2f(924.f,6.f));

    //Load blackPawn
    sf::Texture blackPawnTexture;
    if (!blackPawnTexture.loadFromFile("BlackPawn.png"))
        return -1; //Error if file not found

    sf::Sprite blackPawnSprite(blackPawnTexture);

    //Set position
    blackPawnSprite.setPosition(sf::Vector2f(42.f,132.f));

    //Load blackPawn2
    sf::Texture blackPawn2Texture;
    if (!blackPawn2Texture.loadFromFile("BlackPawn2.png"))
        return -1; //Error if file not found

    sf::Sprite blackPawn2Sprite(blackPawn2Texture);

    //Set position
    blackPawn2Sprite.setPosition(sf::Vector2f(168.f,132.f));

    //Load blackPawn3
    sf::Texture blackPawn3Texture;
    if (!blackPawn3Texture.loadFromFile("BlackPawn3.png"))
        return -1; //Error if file not found

    sf::Sprite blackPawn3Sprite(blackPawn3Texture);

    //Set position
    blackPawn3Sprite.setPosition(sf::Vector2f(294.f,132.f));

    //Load blackPawn4
    sf::Texture blackPawn4Texture;
    if (!blackPawn4Texture.loadFromFile("BlackPawn4.png"))
        return -1; //Error if file not found

    sf::Sprite blackPawn4Sprite(blackPawn4Texture);

    //Set position
    blackPawn4Sprite.setPosition(sf::Vector2f(420.f,132.f));

    //Load blackPawn5
    sf::Texture blackPawn5Texture;
    if (!blackPawn5Texture.loadFromFile("BlackPawn5.png"))
        return -1; //Error if file not found

    sf::Sprite blackPawn5Sprite(blackPawn5Texture);

    //Set position
    blackPawn5Sprite.setPosition(sf::Vector2f(546.f,132.f));

    //Load blackPawn6
    sf::Texture blackPawn6Texture;
    if (!blackPawn6Texture.loadFromFile("BlackPawn6.png"))
        return -1; //Error if file not found

    sf::Sprite blackPawn6Sprite(blackPawn6Texture);

    //Set position
    blackPawn6Sprite.setPosition(sf::Vector2f(672.f,132.f));

    //Load blackPawn7
    sf::Texture blackPawn7Texture;
    if (!blackPawn7Texture.loadFromFile("BlackPawn7.png"))
        return -1; //Error if file not found

    sf::Sprite blackPawn7Sprite(blackPawn7Texture);

    //Set position
    blackPawn7Sprite.setPosition(sf::Vector2f(798.f,132.f));

    //Load blackPawn8
    sf::Texture blackPawn8Texture;
    if (!blackPawn8Texture.loadFromFile("BlackPawn8.png"))
        return -1; //Error if file not found

    sf::Sprite blackPawn8Sprite(blackPawn8Texture);

    //Set position
    blackPawn8Sprite.setPosition(sf::Vector2f(924.f,132.f));

    //Load whiteRook
    sf::Texture whiteRookTexture;
    if (!whiteRookTexture.loadFromFile("WhiteRook.png"))
        return -1; //Error if file not found

    sf::Sprite whiteRookSprite(whiteRookTexture);

    //Set position
    whiteRookSprite.setPosition(sf::Vector2f(42.f,888.f));

    //Load whiteKnight
    sf::Texture whiteKnightTexture;
    if (!whiteKnightTexture.loadFromFile("WhiteKnight.png"))
        return -1; //Error if file not found

    sf::Sprite whiteKnightSprite(whiteKnightTexture);

    //Set position
    whiteKnightSprite.setPosition(sf::Vector2f(168.f,888.f));

    //Load whiteBishop
    sf::Texture whiteBishopTexture;
    if (!whiteBishopTexture.loadFromFile("WhiteBishop.png"))
        return -1; //Error if file not found

    sf::Sprite whiteBishopSprite(whiteBishopTexture);

    //Set position
    whiteBishopSprite.setPosition(sf::Vector2f(294.f,888.f));

    //Load whiteQueen
    sf::Texture whiteQueenTexture;
    if (!whiteQueenTexture.loadFromFile("WhiteQueen.png"))
        return -1; //Error if file not found

    sf::Sprite whiteQueenSprite(whiteQueenTexture);

    //Set position
    whiteQueenSprite.setPosition(sf::Vector2f(420.f,888.f));

    //Load whiteKing
    sf::Texture whiteKingTexture;
    if (!whiteKingTexture.loadFromFile("WhiteKing.png"))
        return -1; //Error if file not found

    sf::Sprite whiteKingSprite(whiteKingTexture);

    //Set position
    whiteKingSprite.setPosition(sf::Vector2f(546.f,888.f));

    //Load whiteBishop2
    sf::Texture whiteBishop2Texture;
    if (!whiteBishop2Texture.loadFromFile("WhiteBishop2.png"))
        return -1; //Error if file not found

    sf::Sprite whiteBishop2Sprite(whiteBishop2Texture);

    //Set position
    whiteBishop2Sprite.setPosition(sf::Vector2f(672.f,888.f));

    //Load whiteKnight2
    sf::Texture whiteKnight2Texture;
    if (!whiteKnight2Texture.loadFromFile("WhiteKnight2.png"))
        return -1; //Error if file not found

    sf::Sprite whiteKnight2Sprite(whiteKnight2Texture);

    //Set position
    whiteKnight2Sprite.setPosition(sf::Vector2f(798.f,888.f));

    //Load whiteRook
    sf::Texture whiteRook2Texture;
    if (!whiteRook2Texture.loadFromFile("WhiteRook2.png"))
        return -1; //Error if file not found

    sf::Sprite whiteRook2Sprite(whiteRook2Texture);

    //Set position
    whiteRook2Sprite.setPosition(sf::Vector2f(924.f,888.f));

    //Load whitePawn
    sf::Texture whitePawnTexture;
    if (!whitePawnTexture.loadFromFile("WhitePawn.png"))
        return -1; //Error if file not found

    sf::Sprite whitePawnSprite(whitePawnTexture);

    //Set position
    whitePawnSprite.setPosition(sf::Vector2f(42.f,762.f));

    //Load whitePawn2
    sf::Texture whitePawn2Texture;
    if (!whitePawn2Texture.loadFromFile("WhitePawn2.png"))
        return -1; //Error if file not found

    sf::Sprite whitePawn2Sprite(whitePawn2Texture);

    //Set position
    whitePawn2Sprite.setPosition(sf::Vector2f(168.f,762.f));

    //Load whitePawn3
    sf::Texture whitePawn3Texture;
    if (!whitePawn3Texture.loadFromFile("WhitePawn3.png"))
        return -1; //Error if file not found

    sf::Sprite whitePawn3Sprite(whitePawn3Texture);

    //Set position
    whitePawn3Sprite.setPosition(sf::Vector2f(294.f,762.f));

    //Load whitePawn4
    sf::Texture whitePawn4Texture;
    if (!whitePawn4Texture.loadFromFile("WhitePawn4.png"))
        return -1; //Error if file not found

    sf::Sprite whitePawn4Sprite(whitePawn4Texture);

    //Set position
    whitePawn4Sprite.setPosition(sf::Vector2f(420.f,762.f));

    //Load whitePawn5
    sf::Texture whitePawn5Texture;
    if (!whitePawn5Texture.loadFromFile("WhitePawn5.png"))
        return -1; //Error if file not found

    sf::Sprite whitePawn5Sprite(whitePawn5Texture);

    //Set position
    whitePawn5Sprite.setPosition(sf::Vector2f(546.f,762.f));

    //Load whitePawn6
    sf::Texture whitePawn6Texture;
    if (!whitePawn6Texture.loadFromFile("WhitePawn6.png"))
        return -1; //Error if file not found

    sf::Sprite whitePawn6Sprite(whitePawn6Texture);

    //Set position
    whitePawn6Sprite.setPosition(sf::Vector2f(672.f,762.f));

    //Load whitePawn7
    sf::Texture whitePawn7Texture;
    if (!whitePawn7Texture.loadFromFile("WhitePawn7.png"))
        return -1; //Error if file not found

    sf::Sprite whitePawn7Sprite(whitePawn7Texture);

    //Set position
    whitePawn7Sprite.setPosition(sf::Vector2f(798.f,762.f));

    //Load whitePawn8
    sf::Texture whitePawn8Texture;
    if (!whitePawn8Texture.loadFromFile("WhitePawn8.png"))
        return -1; //Error if file not found

    sf::Sprite whitePawn8Sprite(whitePawn8Texture);




    //Set position
    whitePawn8Sprite.setPosition(sf::Vector2f(924.f,762.f));

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

        // Drawing logic (happens every frame)
        window.clear();
        window.draw(boardSprite);
        window.draw(whiteKingSprite);
        window.draw(blackKingSprite);
        window.draw(whiteQueenSprite);
        window.draw(blackQueenSprite);
        window.draw(whiteRookSprite);
        window.draw(blackRookSprite);
        window.draw(whiteRook2Sprite);
        window.draw(blackRook2Sprite);
        window.draw(whiteKnightSprite);
        window.draw(blackKnightSprite);
        window.draw(whiteKnight2Sprite);
        window.draw(blackKnight2Sprite);
        window.draw(whiteBishopSprite);
        window.draw(blackBishopSprite);
        window.draw(whiteBishop2Sprite);
        window.draw(blackBishop2Sprite);
        window.draw(whitePawnSprite);
        window.draw(blackPawnSprite);
        window.draw(whitePawn2Sprite);
        window.draw(blackPawn2Sprite);
        window.draw(whitePawn3Sprite);
        window.draw(blackPawn3Sprite);
        window.draw(whitePawn4Sprite);
        window.draw(blackPawn4Sprite);
        window.draw(whitePawn5Sprite);
        window.draw(blackPawn5Sprite);
        window.draw(whitePawn6Sprite);
        window.draw(blackPawn6Sprite);
        window.draw(whitePawn7Sprite);
        window.draw(blackPawn7Sprite);
        window.draw(whitePawn8Sprite);
        window.draw(blackPawn8Sprite);

        window.display();


    }

    return 0;
}
