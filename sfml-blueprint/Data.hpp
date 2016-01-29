//
//  Data.h
//  sfml-blueprint
//
//  Created by Sean on 1/29/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#ifndef Data_h
#define Data_h

#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "ResourcePath.hpp"

class Data {
  public:
    Data() = delete;
    Data(const Data&) = delete;
    Data& operator=(const Data&) = delete;

    static void init();


    // Resource data
    enum TEXTURES : int {
      PLAYER,
    };

    static ResourceManager<sf::Texture, int> textures;

    // Persistent data
    static int lives;

    static int score;
    static void addScore(int score);


  private:
    static void initTextures();
};

ResourceManager<sf::Texture, int> Data::textures;

void Data::init() {
  Data::initTextures();

  Data::score = 0;
  Data::lives = 3;
}

void Data::addScore(int score) {
  Data::score += score;
}

void Data::initTextures() {
  textures.load(TEXTURES::PLAYER, resourcePath() + "ship.png");
}

#endif /* Data_h */
