//
//  Player.cpp
//  sfml-blueprint
//
//  Created by Sean on 12/27/15.
//  Copyright © 2015 Sean. All rights reserved.
//

#include "Player.hpp"

Player::Player(float x, float y) {
  _sprite.setOrigin(50, 38);
  _sprite.move(x, y);
}

void Player::update(sf::Time dt) {
  float sec = dt.asSeconds();

  if (rotation != 0) {
    float angle = (rotation > 0 ? 1 : -1) * 180 * sec;
    _sprite.rotate(angle);
  }

  if (isMoving) {
    float angle = _sprite.getRotation() / 180 * M_PI - M_PI_2;

    _velocity.x = std::cos(angle) * speed;
    _velocity.y = std::sin(angle) * speed;

    _sprite.move(_velocity.x * sec, _velocity.y * sec);
  }
}

void Player::setTexture(const sf::Texture &tex) {
  _sprite.setTexture(tex);
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(_sprite, states);
}
