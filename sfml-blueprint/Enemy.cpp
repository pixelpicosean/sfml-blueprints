//
//  Enemy.cpp
//  sfml-blueprint
//
//  Created by Sean on 1/29/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#include "Enemy.hpp"
#include "Scene.hpp"
#include "Collision.hpp"
#include "Utils.hpp"

Enemy::Enemy(Data::TEXTURES texID, Scene& scene): Actor(texID, scene) {
  float angle = lp::random(0.0f, 2.0f * M_PI);
  this->_impulse = sf::Vector2f(std::cos(angle), std::sin(angle));
}

void Enemy::onDestroy() {
  Actor::onDestroy();

  Data::addScore(this->getPoints());
}

// = Saucer ==============================================================
bool Saucer::isCollide(const Actor &other) const {
  if (dynamic_cast<const ShootSaucer*>(&other) == nullptr) {
    return Collision::circleTest(this->_sprite, other._sprite);
  }

  return false;
}

void Saucer::update(sf::Time dt) {
  float seconds = dt.asSeconds();

  Actor *near = nullptr;
  float nearDistance = 300.0f;

  for (Actor *actorPtr : this->_scene.getActors()) {
    if (actorPtr != this and (dynamic_cast<const Meteor *>(actorPtr) or (dynamic_cast<const ShootPlayer *>(actorPtr)))) {
      float x = this->getPosition().x - actorPtr->getPosition().x;
      float y = this->getPosition().y - actorPtr->getPosition().y;
      float dist = std::sqrt(x * x + y * y);
      if (dist < nearDistance) {
        nearDistance = dist;
        near = actorPtr;
      }
    }
  }

  if (near != nullptr) {
    sf::Vector2f pos = near->getPosition();
    float angleRad = std::atan2(pos.y, pos.x);
    this->_impulse -= sf::Vector2f(std::cos(angleRad), std::sin(angleRad)) * 300.0f * seconds;
  }
  else {
    sf::Vector2f pos = Data::player->getPosition() - this->getPosition();
    float angleRad = std::atan2(pos.y, pos.x);
    this->_impulse += sf::Vector2f(std::cos(angleRad), std::sin(angleRad)) * 300.0f * seconds;
  }

  this->_sprite.move(seconds * this->_impulse);
}

void Saucer::onDestroy() {
  Enemy::onDestroy();

  // TODO: play boom sound
}

void Saucer::newSaucer(Scene &scene) {
  Saucer *res = nullptr;
  if (util::random(0.0f, 1.0f) > Data::getScore() / 4000.0f) {
    res = new BigSaucer(scene);
  }
  else {
    res = new SmallSaucer(scene);
  }

  res->setPosition(util::random(0, 1) * scene.getX(), util::random(0.0f, (float)scene.getY()));

  scene.add(res);
}

// = Small Saucer =========================================================
SmallSaucer::SmallSaucer(Scene& scene): Saucer(Data::TEXTURES::SMALL_SAUCER, scene) {
  this->_timeSinceLastShoot = sf::Time::Zero;
  this->_impulse *= 400.0f;

  // TODO: play shoot sound
}

int SmallSaucer::getPoints() const {
  return 200;
}

void SmallSaucer::update(sf::Time dt) {
  Saucer::update(dt);

  this->_timeSinceLastShoot += dt;
  if (this->_timeSinceLastShoot > sf::seconds(1.5)) {
    if (Data::player != nullptr) {
      this->_world.add(new ShootSaucer(*this));
      this->_timeSinceLastShoot = sf::Time::Zero;
    }
  }
}

// = Meteor ==============================================================
bool Meteor::isCollide(const Enemy &other) const {
  if (dynamic_cast<const Meteor*>(&other) == nullptr) {
    return Collision::circleTest(this->_sprite, other._sprite);
  }

  return false;
}

void Meteor::update(sf::Time dt) {
  float seconds = dt.asSeconds();
  this->_sprite.move(this->_impulse * seconds);
}
