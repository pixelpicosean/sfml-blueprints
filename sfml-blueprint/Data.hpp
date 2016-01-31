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

class Actor;
class Data {
  public:
    Data() = delete;
    Data(const Data&) = delete;
    Data& operator=(const Data&) = delete;

    static void init();
    static void reset();


    // Resource data
    enum TEXTURES : int {
      PLAYER,
      PLAYER_LIFE,
      SHOOT_PLAYER,

      SAUCER,
      SMALL_SAUCER,
      SHOOT_SAUCER,

      BIG_METEOR_1,
      BIG_METEOR_2,
      BIG_METEOR_3,
      BIG_METEOR_4,

      MEDIUM_METEOR_1,
      MEDIUM_METEOR_2,

      SMALL_METEOR_1,
      SMALL_METEOR_2,
      SMALL_METEOR_3,
      SMALL_METEOR_4,
    };

    static ResourceManager<sf::Texture, int> textures;

    // Persistent data
    static int lives;

    static int score;
    static void addScore(int score);

    // Session data
    static Actor *player;


  private:
    static void initTextures();
};

#endif /* Data_h */
