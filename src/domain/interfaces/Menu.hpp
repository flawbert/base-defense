#pragma once // instead of ifndef and define
#include <memory>
#include <SFML/Graphics.hpp>
#include "structs.h"
#include "enums/MenuActions.h"
#include <iostream>

class Menu
{
private:
    /// @brief Index of current option
    int current;
    /// @brief True if menu has element pressed.
    bool pressed;
    /// @brief True if menu has 1 or more element selected
    bool selected;
    std::weak_ptr<sf::RenderWindow> window;
    std::unique_ptr<sf::Font> font;
    std::unique_ptr<sf::Texture> image;
    std::unique_ptr<sf::Sprite> bg;
    sf::Vector2f mouseCords;
    sf::Vector2f mousePosition;

    // TODO: improve this using structs or something
    std::unique_ptr<std::vector<const char *>> options;
    std::unique_ptr<std::vector<sf::Vector2f>> optionsCoords;
    std::unique_ptr<std::vector<sf::Text>> optionsTexts;
    std::unique_ptr<std::vector<std::size_t>> optionsSize;

protected:
    /// @brief Catch user actions with menu
    /// @return The action user selected
    /// @note This also handle interactions such as navigating through options (although this doesn't return any MenuAction object, just modifies the menu state)
    MenuActions handleActions();
    /// @brief Initialize many objects. Required on constructor
    void init();
    /// @brief Draws options and images on screen
    void drawAll();

public:
    Menu(std::shared_ptr<sf::RenderWindow> gameWindow)
    {
        window = gameWindow;
        font = std::make_unique<sf::Font>();
        image = std::make_unique<sf::Texture>();
        bg = std::make_unique<sf::Sprite>();
        init();
    }

    void showAbout();

    ~Menu() = default;
    bool run();
};
