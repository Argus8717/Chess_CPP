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
#include "Window.h"

/*
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
};*/

int main()
{
    Window *window = new Window();

    window->running();

    return 0;
}
