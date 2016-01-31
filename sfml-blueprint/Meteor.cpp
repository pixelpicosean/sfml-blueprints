//
//  Meteor.cpp
//  sfml-blueprint
//
//  Created by Sean on 1/31/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#include "Meteor.hpp"

#include "Collision.hpp"
#include "Utils.hpp"
#include "Scene.hpp"

bool Meteor::isCollide(const Actor &other) const {
  if (dynamic_cast<const Meteor*>(&other) == nullptr) {
    return Collision::circleTest(this->sprite, other.sprite);
  }

  return false;
}

void Meteor::update(sf::Time dt) {
  float seconds = dt.asSeconds();
  this->sprite.move(this->_impulse * seconds);
}

// = Big Meteor ==========================================================
BigMeteor::BigMeteor(Scene& scene): Meteor((Data::TEXTURES)lp::random(Data::TEXTURES::BIG_METEOR_1, Data::TEXTURES::BIG_METEOR_4), scene) {
  this->_impulse *= 100.0f;
}

int BigMeteor::getPoints() const {
  return 20;
}

void BigMeteor::onDestroy() {
  Meteor::onDestroy();

  int nb = lp::random(2, 3);
  for (int i = 0; i < nb; ++i) {
    auto meteor = new MediumMeteor(this->scene);
    meteor->setPosition(this->getPosition());
    this->scene.add(meteor);
  }

  // TODO: play explosion sound
}

// = Medium Meteor ==========================================================
MediumMeteor::MediumMeteor(Scene& scene): Meteor((Data::TEXTURES)lp::random(Data::TEXTURES::BIG_METEOR_1, Data::TEXTURES::BIG_METEOR_4), scene) {
  this->_impulse *= 200.0f;
}

int MediumMeteor::getPoints() const {
  return 60;
}

void MediumMeteor::onDestroy() {
  Meteor::onDestroy();

  int nb = lp::random(1, 2);
  for (int i = 0; i < nb; ++i) {
    auto meteor = new SmallMeteor(this->scene);
    meteor->setPosition(this->getPosition());
    this->scene.add(meteor);
  }

  // TODO: play explosion sound
}

// = Small Meteor ==========================================================
SmallMeteor::SmallMeteor(Scene& scene): Meteor((Data::TEXTURES)lp::random(Data::TEXTURES::BIG_METEOR_1, Data::TEXTURES::BIG_METEOR_4), scene) {
  this->_impulse *= 300.0f;
}

int SmallMeteor::getPoints() const {
  return 100;
}

void SmallMeteor::onDestroy() {
  Meteor::onDestroy();

  // TODO: play explosion sound
}
