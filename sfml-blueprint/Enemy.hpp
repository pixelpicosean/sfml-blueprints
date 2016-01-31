//
//  Enemy.hpp
//  sfml-blueprint
//
//  Created by Sean on 1/29/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include "Actor.hpp"
#include "Data.hpp"

// Enemy base class
class Enemy : public Actor {
  public:
    Enemy(const Enemy&) = delete;
    Enemy& operator=(const Enemy&) = delete;

    Enemy(Data::TEXTURES texID, Scene& scene);

    virtual int getPoints() const = 0;
    virtual void onDestroy() override;
};


// Enemies
class Saucer : public Enemy {
  public:
    Saucer(const Saucer&) = delete;
    Saucer& operator=(const Saucer&) = delete;

    using Enemy::Enemy;

    bool isCollide(const Actor& other) const override;
    void update(sf::Time dt) override;
    void onDestroy() override;

    static void newSaucer(Scene& scene);
};

class SmallSaucer : public Saucer {
  public:
    SmallSaucer(Scene& scene);

    virtual int getPoints() const;
    virtual void update(sf::Time dt);

  private:
    sf::Time _timeSinceLastShoot;
};

class Meteor : public Enemy {
  public:
    Meteor(const Meteor&) = delete;
    Meteor& operator=(const Meteor&) = delete;

    using Enemy::Enemy;

    bool isCollide(const Enemy& other) const override;
    void update(sf::Time dt);
};

#endif /* Enemy_hpp */
