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

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "tag_puzzle.hpp"

using namespace std;

int main()
{
    sf::RenderWindow main_win(sf::VideoMode(600, 600), "Tag Puzzle");

    sf::Image mw_icon;
    if(!(mw_icon.loadFromFile("res/tag_icon.png"))) exit(1);

    main_win.setIcon(mw_icon.getSize().x, mw_icon.getSize().y, mw_icon.getPixelsPtr());

    sf::Event mw_event;

    sf::Font menu_font;
    if(!(menu_font.loadFromFile("res/DejaVuSansMono.ttf"))) exit(1);

    sf::Text menu_msg;
    menu_msg.setFont(menu_font);
    menu_msg.setScale(sf::Vector2f(0.4, 0.4));
    menu_msg.setString("ESC - exit / F2 - new game / F3 - Sound / Arrows - step        by KonstantIMP");
    menu_msg.setPosition(sf::Vector2f(24, 5));
    menu_msg.setFillColor(sf::Color(255, 186, 0));

    sf::Music mw_music;
    if(!(mw_music.openFromFile("res/Wallpaper.ogg"))) exit(4);
    mw_music.setLoop(true);
    mw_music.play();

    tag_puzzle game;
    game.field_init();
    game.setPosition(sf::Vector2f(24, 24));

    while(main_win.isOpen()){
        while(main_win.pollEvent(mw_event)){
            if(mw_event.type == sf::Event::Closed) main_win.close();

            if(mw_event.type == sf::Event::KeyPressed){
                if(mw_event.key.code == sf::Keyboard::Escape) main_win.close();

                if(mw_event.key.code == sf::Keyboard::Up) game.move_bit(UP);
                if(mw_event.key.code == sf::Keyboard::Down) game.move_bit(DOWN);
                if(mw_event.key.code == sf::Keyboard::Left) game.move_bit(LEFT);
                if(mw_event.key.code == sf::Keyboard::Right) game.move_bit(RIGHT);

                if(mw_event.key.code == sf::Keyboard::F2) game.field_init();

                if(mw_event.key.code == sf::Keyboard::F3){
                    if(mw_music.getStatus() == sf::Music::Playing) mw_music.pause();
                    else mw_music.play();
                }
            }
        }

        main_win.clear();

        main_win.draw(menu_msg);
        main_win.draw(game);

        main_win.display();
    }

    return 0;
}
