//
//  Collision.cpp
//  sfml-blueprint
//
//  Created by Sean on 1/17/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#include "Collision.hpp"
#include <cmath>

bool Collision::circleTest(const sf::Sprite &first, const sf::Sprite &second) {
  sf::Vector2f firstRect(first.getTextureRect().width, first.getTextureRect().height);
  firstRect.x *= first.getScale().x;
  firstRect.y *= first.getScale().y;

  sf::Vector2f secondRect(second.getTextureRect().width, second.getTextureRect().height);
  secondRect.x *= second.getScale().x;
  secondRect.y *= second.getScale().y;

  float radius1 = (firstRect.x + firstRect.y) / 4;
  float radius2 = (secondRect.x + secondRect.y) / 4;
  float xd = first.getPosition().x - second.getPosition().x;
  float yd = first.getPosition().y - second.getPosition().y;

  return std::sqrt(xd * xd + yd * yd) <= radius1 + radius2;
}
