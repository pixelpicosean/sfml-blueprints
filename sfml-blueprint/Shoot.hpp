//
//  Shoot.hpp
//  sfml-blueprint
//
//  Created by Sean on 1/31/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#ifndef Shoot_hpp
#define Shoot_hpp

#include "Actor.hpp"

class Shoot : public Actor {
  public:
    Shoot(const Shoot&) = delete;
    Shoot& operator=(const Shoot&) = delete;

    using Actor::Actor;

    virtual void update(sf::Time dt) override;

  protected:
    sf::Time _duration;
};

class Player;
class ShootPlayer : public Shoot {
  public:
    ShootPlayer(const ShootPlayer&) = delete;
    ShootPlayer& operator=(const ShootPlayer&) = delete;

    ShootPlayer(Player& from);

    bool isCollide(const Actor& other) const override;
};

class SmallSaucer;
class ShootSaucer : public Shoot {
  public:
    ShootSaucer(const ShootSaucer&) = delete;
    ShootSaucer& operator=(const ShootSaucer&) = delete;

    ShootSaucer(SmallSaucer& from);

    bool isCollide(const Actor& other) const override;
};


#endif /* Shoot_hpp */
