#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class blob {
private:
    sf::CircleShape circle;
    sf::Vector2<float> pos{ 0., 0. };
    sf::Color color{ 255, 180, 0 };
    float speed = 2.0;
    float size = 10.0;
    
public:
    blob(sf::Vector2<float> pos, std::vector<blob>& shape_list, float size=10.0, bool rand_c=false);

    void set_position(const sf::Vector2<float>& pos);
    void set_color(sf::Color color);
    void set_size(float size);
    void set_speed(float speed);

    
    sf::Vector2<float> get_position() const;
    sf::Color get_color() const;
    float get_size() const;
    float get_speed() const;
    sf::CircleShape get_circle() const;

    void randomColor();
    bool checkOverlap(const sf::Vector2<float>& mousePos, float size) const;
    
    };
