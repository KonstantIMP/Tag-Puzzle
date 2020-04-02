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

#ifndef TAG_PUZZLE_HPP
#define TAG_PUZZLE_HPP

#include <SFML/Graphics.hpp>

enum Direction{UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3};

class tag_puzzle : public sf::Drawable, public sf::Transformable
{
public:
    tag_puzzle();
    ~tag_puzzle();

    void field_init();

    void move_bit(Direction);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::Font num_font;

    int bits[16];

    int null_index;
};

#endif // TAG_PUZZLE_HPP
