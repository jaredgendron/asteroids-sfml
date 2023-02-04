#include <SFML/Graphics.hpp>

class Asteroid : public sf::Drawable {
    public:
        Asteroid();
        ~Asteroid();

        template<typename ... Args> void setPosition(Args&& ... args) {
            _sprite.setPosition(std::forward<Args>(args)...);
        }

        sf::Vector2f getPosition() {
            return _sprite.getPosition();
        }

        void update(sf::Time deltaTime);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::ConvexShape _sprite;
        sf::Vector2f _velocity;
        int x_vel, y_vel, rotation;
        
};