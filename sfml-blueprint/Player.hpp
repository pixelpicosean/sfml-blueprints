//
//  Player.hpp
//  sfml-blueprint
//
//  Created by Sean on 12/27/15.
//  Copyright © 2015 Sean. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>
#include <cmath>

class Player: public sf::Drawable {
  public:
    bool isMoving = false;
    int rotation = 0;
    float speed = 200.0f;

    sf::Vector2f anchor = { 0.5f, 0.5f };

  public:
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;
    Player();

    template <typename ... Args>
    void setPosition(Args&& ... args) {
      _sprite.setPosition(std::forward<Args>(args) ...);
    }

    void update(sf::Time dt);

    void setTexture(const sf::Texture& tex);

  private:
    sf::Sprite _sprite;
    sf::Vector2f _velocity;

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif /* Player_hpp */
