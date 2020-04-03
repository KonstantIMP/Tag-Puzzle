//Copyright 2020 KonstantIMP
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.

#include "tag_puzzle.hpp"

#include <string>

tag_puzzle::tag_puzzle() {
    if(!(num_font.loadFromFile("res/DejaVuSansMono.ttf")) && !(num_font.loadFromFile("/usr/share/tag_game/res/DejaVuSansMono.ttf"))) exit(0);
}

tag_puzzle::~tag_puzzle() {}

void tag_puzzle::field_init() {
    for(int i{0}; i < 16; i++) bits[i] = i + 1;

    null_index = 15;

    bits[null_index] = 0;

    timer.restart();

    srand(time(0));
    for(int i{0}; i < 500; i++) this->move_bit((Direction)(rand() % 4));
}

void tag_puzzle::move_bit(Direction step) {
    if(timer.getElapsedTime().asSeconds() > 1) if(is_win()) return;

    int row = null_index / 4;
    int collumn = null_index % 4;

    if((step == LEFT && collumn == 3) || (step == RIGHT && collumn == 0)) return;
    if((step == UP && row == 3) || (step == DOWN && row == 0)) return;

    switch (step) {
    case UP:
        null_index += 4;
        bits[null_index - 4] = bits[null_index];
        break;
    case RIGHT:
        null_index -= 1;
        bits[null_index + 1] = bits[null_index];
        break;
    case DOWN:
        null_index -= 4;
        bits[null_index + 4] = bits[null_index];
        break;
    case LEFT:
        null_index += 1;
        bits[null_index - 1] = bits[null_index];
        break;
    }

    bits[null_index] = 0;
}

void tag_puzzle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    sf::Color field_color = sf::Color(62, 230, 185);

    sf::RectangleShape field(sf::Vector2f(552, 552));
    field.setOutlineThickness(2);
    field.setOutlineColor(field_color);
    field.setFillColor(sf::Color::Transparent);

    target.draw(field, states);

    sf::RectangleShape bit(sf::Vector2f(132, 132));
    bit.setOutlineThickness(1);
    bit.setFillColor(sf::Color::Transparent);

    sf::Text bit_num("", num_font, 30);

    for(int i{0}; i < 16; i++){
        if(bits[i] == i + 1) {
            bit.setOutlineColor(sf::Color(102, 0, 255));
            bit.setFillColor(sf::Color::Transparent);
            bit_num.setFillColor(sf::Color(0, 255, 0));
        }
        else {
            bit.setOutlineColor(sf::Color(44, 117, 255));
            bit.setFillColor(sf::Color::Transparent);
            bit_num.setFillColor(sf::Color(0, 191, 255));
        }

        if(bits[i] == 0){
            bit.setOutlineColor(sf::Color::Transparent);
            bit.setFillColor(sf::Color(0, 191, 255));
            bit_num.setFillColor(sf::Color::Transparent);
        }

        bit.setPosition(sf::Vector2f(12 + (132 * (i % 4)), 12 + (132 * (i / 4))));
        bit_num.setPosition(sf::Vector2f(12 + (132 * (i % 4)) + 46, 12 + (132 * (i / 4)) + 46));

        bit_num.setString(std::to_string(bits[i]));

        target.draw(bit_num, states);
        target.draw(bit, states);
    }

    for(int i{0}; i < 15; i++){
        if(bits[i] != i + 1) return;
    }

    sf::RectangleShape win_place;
    win_place.setSize(sf::Vector2f(300, 200));
    win_place.setFillColor(sf::Color::Red);
    win_place.setPosition(sf::Vector2f(130, 175));
    win_place.setOutlineThickness(5.f);
    win_place.setOutlineColor(sf::Color::White);

    target.draw(win_place, states);

    bit_num.setString("You WIN!");
    bit_num.setCharacterSize(48);
    bit_num.setFillColor(sf::Color::White);
    bit_num.setPosition(sf::Vector2f(170, 200));

    target.draw(bit_num, states);

    bit_num.setString(std::to_string(((int)(((int)timer.getElapsedTime().asSeconds()) / 60))) + " : " + std::to_string(((int)(((int)timer.getElapsedTime().asSeconds()) % 60))));
    bit_num.setCharacterSize(48);
    bit_num.setPosition(sf::Vector2f(208, 260));

    target.draw(bit_num, states);

    bit_num.setString("Press F2 to restart & ESC to exit");
    bit_num.setCharacterSize(14);
    bit_num.setPosition(sf::Vector2f(150, 330));

    target.draw(bit_num, states);
}

bool tag_puzzle::is_win() {
    for(int i{0}; i < 15; i++){
        if(bits[i] != i + 1) return false;
    }

    return true;
}
