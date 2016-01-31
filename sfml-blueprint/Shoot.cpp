//
//  Shoot.cpp
//  sfml-blueprint
//
//  Created by Sean on 1/31/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#include "Shoot.hpp"

#include "Player.hpp"
#include "Enemy.hpp"
#include "Saucer.hpp"

#include "Collision.hpp"
#include "Utils.hpp"

void Shoot::update(sf::Time dt) {
  this->_duration -= dt;
  if (this->_duration < sf::Time::Zero) {
    this->_alive = false;
  }
  else {
    this->sprite.move(this->_impulse * dt.asSeconds());
  }
}

ShootPlayer::ShootPlayer(Player& from): Shoot(Data::TEXTURES::SHOOT_PLAYER, from.scene) {
  float angle = from.sprite.getRotation() / 180 * M_PI - M_PI_2;

  // Set velocity
  this->_duration = sf::seconds(5);
  this->_impulse = sf::Vector2f(std::cos(angle), std::sin(angle)) * 500.0f;

  // Set position and rotation to the same as shooter
  this->setPosition(from.getPosition());
  this->sprite.setRotation(from.sprite.getRotation());

  // TODO: play shoot sound
}

bool ShootPlayer::isCollide(const Actor &other) const {
  if (dynamic_cast<const Enemy*>(&other) != nullptr) {
    return Collision::circleTest(this->sprite, other.sprite);
  }

  return false;
}

ShootSaucer::ShootSaucer(SmallSaucer& from): Shoot(Data::TEXTURES::SHOOT_SAUCER, from.scene) {
  this->_duration = sf::seconds(5);
  sf::Vector2f pos = Data::player->getPosition() - from.getPosition();

  float accuracyLost = lp::random(-1.0f, 1.0f) * M_PI / ((200 + Data::score) / 100.0f);

  float angleRad = std::atan2(pos.y, pos.x) + accuracyLost;
  float angleDeg = angleRad * 180 / M_PI;

  this->_impulse = sf::Vector2f(std::cos(angleRad), std::sin(angleRad)) * 500.0f;

  this->setPosition(from.getPosition());
  this->sprite.setRotation(angleDeg + 90);

  // TODO: player enemy shooting sound
}

bool ShootSaucer::isCollide(const Actor &other) const {
  if (dynamic_cast<const Player*>(&other) != nullptr) {
    return Collision::circleTest(this->sprite, other.sprite);
  }

  return false;
}
