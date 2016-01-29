//
//  Enemy.cpp
//  sfml-blueprint
//
//  Created by Sean on 1/29/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#include "Enemy.hpp"
#include "Scene.hpp"
#include "Utils.hpp"

Enemy::Enemy(Data::TEXTURES texID, Scene& scene): Actor(texID, scene) {
  float angle = lp::random(0.0f, 2.0f * M_PI);
  this->_impulse = sf::Vector2f(std::cos(angle), std::sin(angle));
}

void Enemy::onDestroy() {
  Actor::onDestroy();

  Data::addScore(this->getPoints());
}
