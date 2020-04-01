#include <SFML/Graphics.hpp>

#include "tag_puzzle.hpp"

using namespace std;

int main()
{
    sf::RenderWindow main_win(sf::VideoMode(600, 600), "Tag Puzzle");

    sf::Image mw_icon;
    if(!(mw_icon.loadFromFile("tag_icon.png"))) exit(1);

    main_win.setIcon(mw_icon.getSize().x, mw_icon.getSize().y, mw_icon.getPixelsPtr());

    sf::Event mw_event;

    sf::Font menu_font;
    if(!(menu_font.loadFromFile("DejaVuSansMono.ttf"))) exit(1);

    sf::Text menu_msg;
    menu_msg.setFont(menu_font);
    menu_msg.setScale(sf::Vector2f(0.45, 0.45));
    menu_msg.setString("ESC - exit / Arrows - step / F2 - new game");
    menu_msg.setPosition(sf::Vector2f(24, 5));
    menu_msg.setFillColor(sf::Color(255, 186, 0));

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
            }
        }

        main_win.clear();

        main_win.draw(menu_msg);
        main_win.draw(game);

        main_win.display();
    }

    return 0;
}
