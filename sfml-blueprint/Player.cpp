//
//  Player.cpp
//  sfml-blueprint
//
//  Created by Sean on 12/27/15.
//  Copyright © 2015 Sean. All rights reserved.
//

#include "Player.hpp"

#include "Scene.hpp"
//#include "Shoot.hpp"

//#include "Collision.hpp"
//#include "Utils.hpp"

Player::Player(Scene& scene): Actor(Data::TEXTURES::PLAYER, scene) {
  // TODO: setup input
}

bool Player::isCollide(const Actor &other) const {
//  if (dynamic_cast<const ShootPlayer *>(&other) == nullptr) {
//    return Collision::circleTest(this->sprite, other.sprite);
//  }

  return false;
}

void Player::update(sf::Time dt) {
  float seconds = dt.asSeconds();
  this->_timeSinceLastShoot += dt;

  if (this->_rotation != 0) {
    float angle = this->_rotation * 250 * seconds;
    this->sprite.rotate(angle);
  }

  if (this->_isMoving) {
    float angle = this->sprite.getRotation() / 180 * M_PI - M_PI_2;
    this->_impulse += sf::Vector2f(std::cos(angle), std::sin(angle)) * 300.0f * seconds;
  }

  this->sprite.move(this->_impulse);
}

void Player::shoot() {
  if (this->_timeSinceLastShoot > sf::seconds(0.3)) {
//    this->scene.add(new ShootPlayer(*this));
    this->_timeSinceLastShoot = sf::Time::Zero;
  }
}

void Player::goToHyperspace() {
  this->_impulse = sf::Vector2f(0, 0);
//  this->setPosition(lp::random(0, this->scene.getX()), lp::random(0, this->scene.getY()));

  // TODO: play jump sound
}

void Player::onDestroy() {
  Actor::onDestroy();

  Data::lives -= 1;

  // TODO: play boom sound
}
