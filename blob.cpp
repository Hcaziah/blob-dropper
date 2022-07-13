#include "blob.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <stdlib.h> // rand
#include <cmath> // pow()

blob::blob(sf::Vector2<float> pos, std::vector<blob>& shape_list, float size, bool rand_c) {
    this->pos = pos;
    this->size = size;
    sf::CircleShape circle(this->size, 64);
    if (rand_c)
        this->randomColor();
    this->circle = circle;
    this->circle.setPosition(this->pos.x, this->pos.y);
    this->circle.setFillColor(this->color);
    this->circle.setOrigin(this->size, this->size);
    shape_list.push_back(*this);
    }

void blob::set_position(const sf::Vector2<float>& pos) { this->pos = pos; }
void blob::set_color(sf::Color color) { this->color = color; }
void blob::set_size(float size) { this->size = size; }
void blob::set_speed(float speed) { this->speed = speed; }

sf::Vector2<float> blob::get_position() const { return this->pos; }
sf::Color blob::get_color() const { return this->color; }
float blob::get_size() const { return this->size; };
float blob::get_speed() const { return this->speed; };
sf::CircleShape blob::get_circle() const { return this->circle; }


void blob::randomColor() {
    this->color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
    }

bool blob::checkOverlap(const sf::Vector2<float>& mousePos, float size) const {
    double x = mousePos.x - this->get_position().x;
    double y = mousePos.y - this->get_position().y;
    float r = this->get_size() + size;
    return (pow(x, 2) + pow(y, 2) < pow(r, 2));
    }
