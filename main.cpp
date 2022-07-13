#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "blob.cpp"

int windowWidth = 1440;
int windowHeight = 900;

int main() {
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Bacteria Sim");
    window.setFramerateLimit(100);

    bool lMouse{ false };
    float mWheelSize{ 10.0 };

    std::vector<blob> shape_list{};

    while (window.isOpen()) {
        // get the current mouse position in the window
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

        // convert it to world coordinates
        sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !lMouse) {
                blob(worldPos, shape_list, mWheelSize);
                lMouse = true;
                }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shape_list.size() > 0) {
                window.clear();
                std::cout << "Removed " << shape_list.size() << " circles." << std::endl;
                shape_list.clear();
                }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                for (int i = 0; i < 100; i++) {
                    sf::Vector2<float> rand_pos(rand() % windowWidth, rand() % windowHeight);
                    blob(rand_pos, shape_list, rand() % 100 + 10, true);
                    }
                }
            if (event.type == event.MouseButtonReleased && lMouse) {
                lMouse = false;
                }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && event.type == sf::Event::MouseWheelMoved) {
                mWheelSize += (event.mouseWheel.delta * 10);
                }
            else if (event.type == sf::Event::MouseWheelMoved) {
                mWheelSize += (event.mouseWheel.delta * 5);
                }
            }
        
        sf::CircleShape grey(mWheelSize - 1, 64);
        grey.setOrigin(mWheelSize, mWheelSize);
        grey.setPosition(worldPos);

        window.clear();
        std::cout << std::string(20, '-') << std::endl;
        for (const blob &circ : shape_list) {
            
            window.draw(circ.get_circle());
            if (circ.checkOverlap(worldPos, mWheelSize)) {
                lMouse = true;
                grey.setOutlineColor(sf::Color(255, 0, 0, 180));
                }
            else {
                lMouse = false;
                grey.setOutlineColor(sf::Color(255, 255, 255, 180));
                }
            }

        grey.setFillColor(sf::Color(0, 0, 0, 0));
        grey.setOutlineThickness(2);

        window.draw(grey);
        window.display();
        }

    return 0;
    }
