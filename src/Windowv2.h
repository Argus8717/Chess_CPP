#include <string.h>

#include <SFML/Graphics.hpp>

#ifndef CMAKESFMLPROJECT_WINDOW_H
#define CMAKESFMLPROJECT_WINDOW_H

#endif //CMAKESFMLPROJECT_WINDOW_H

class Window
{
private:
    unsigned int width;
    unsigned int height;
    std::string title;
    sf::VideoMode vm;
    sf::RenderWindow *window;


    void loadTextures();

    void initWindow();

    void pollEvents();

    void updating();
    void rendering();


public:
    Window();
    ~Window();

    void running();
};
