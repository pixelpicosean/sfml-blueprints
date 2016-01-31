//
//  Actor.cpp
//  sfml-blueprint
//
//  Created by Sean on 1/17/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#include "Actor.hpp"

Actor::Actor(Data::TEXTURES texID, Scene& scene): scene(scene) {
  sf::Texture& tex = Data::textures.get(texID);
  sprite.setTexture(tex);
  sprite.setOrigin(tex.getSize().x / 2, tex.getSize().y / 2);
}

bool Actor::isAlive() const {
  return _alive;
}

const sf::Vector2f& Actor::getPosition() const {
  return sprite.getPosition();
}

void Actor::onDestroy() {
  _alive = false;
}

void Actor::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(this->sprite, states);
}
