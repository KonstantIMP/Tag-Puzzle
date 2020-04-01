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
