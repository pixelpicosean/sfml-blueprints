//
//  Collision.hpp
//  sfml-blueprint
//
//  Created by Sean on 1/17/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#ifndef Collision_hpp
#define Collision_hpp

#include <SFML/Graphics.hpp>

class Collision {
  public:
    Collision() = delete;
    Collision(const Collision&) = delete;
    Collision& operator=(const Collision&) = delete;

    static bool circleTest(const sf::Sprite& first, const sf::Sprite& second);
};

#endif /* Collision_hpp */
