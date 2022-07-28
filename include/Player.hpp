#include <SFML/Graphics.hpp>

class Player : public sf::Drawable {
    public:
        Player(const Player&) = delete;
        Player& operator=(const Player&) = delete;
        Player();
        Player(sf::Color color,sf::Keyboard::Key Up, sf::Keyboard::Key Left, sf::Keyboard::Key Right);

        template<typename ... Args> void setPosition(Args&& ... args) {
            _sprite.setPosition(std::forward<Args>(args)...);
        }

        void update(sf::Time deltaTime);
        void processEvents();

        bool isMoving;
        int rotation;

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::ConvexShape _sprite;
        sf::Vector2f _velocity;
        sf::Keyboard::Key controls[3];
};