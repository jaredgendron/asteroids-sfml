#include <SFML/Graphics.hpp>
#include "Asteroid.hpp"

class Level : public sf::Drawable{
    public:
        Level(const Level&) = delete;
        Level& operator=(const Level&) = delete;
        Level(int x,int y);
        void update(sf::Time deltaTime);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        Asteroid _asteroid[10];
        sf::Vector2i positions[10];
};