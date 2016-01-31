//
//  Data.cpp
//  sfml-blueprint
//
//  Created by Sean on 1/31/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#include "Data.hpp"

ResourceManager<sf::Texture, int> Data::textures;
int Data::lives;
int Data::score;
Actor *Data::player;

void Data::init() {
  Data::initTextures();
  Data::reset();
}

void Data::reset() {
  // Persistent
  Data::score = 0;
  Data::lives = 3;

  // Session
  Data::player = nullptr;
}

void Data::addScore(int score) {
  Data::score += score;
}

void Data::initTextures() {
  textures.load(TEXTURES::PLAYER, resourcePath() + "/Player/Ship.png");
  textures.load(TEXTURES::PLAYER_LIFE, resourcePath() + "/Player/life.png");
  textures.load(TEXTURES::SHOOT_PLAYER, resourcePath() + "/Shoot/Player.png");

  textures.load(TEXTURES::SAUCER, resourcePath() + "/Saucer/Big.png");
  textures.load(TEXTURES::SMALL_SAUCER, resourcePath() + "/Saucer/Small.png");
  textures.load(TEXTURES::SHOOT_SAUCER, resourcePath() + "/Shoot/Saucer.png");

  textures.load(TEXTURES::BIG_METEOR_1, resourcePath() + "/Meteor/Big1.png");
  textures.load(TEXTURES::BIG_METEOR_2, resourcePath() + "/Meteor/Big2.png");
  textures.load(TEXTURES::BIG_METEOR_3, resourcePath() + "/Meteor/Big3.png");
  textures.load(TEXTURES::BIG_METEOR_4, resourcePath() + "/Meteor/Big4.png");

  textures.load(TEXTURES::MEDIUM_METEOR_1, resourcePath() + "/Meteor/Medium1.png");
  textures.load(TEXTURES::MEDIUM_METEOR_2, resourcePath() + "/Meteor/Medium2.png");

  textures.load(TEXTURES::SMALL_METEOR_1, resourcePath() + "/Meteor/Small1.png");
  textures.load(TEXTURES::SMALL_METEOR_2, resourcePath() + "/Meteor/Small2.png");
  textures.load(TEXTURES::SMALL_METEOR_3, resourcePath() + "/Meteor/Small3.png");
  textures.load(TEXTURES::SMALL_METEOR_4, resourcePath() + "/Meteor/Small4.png");
}
