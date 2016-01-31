//
//  Meteor.hpp
//  sfml-blueprint
//
//  Created by Sean on 1/31/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#ifndef Meteor_hpp
#define Meteor_hpp

#include "Enemy.hpp"

class Meteor : public Enemy {
  public:
    Meteor(const Meteor&) = delete;
    Meteor& operator=(const Meteor&) = delete;

    using Enemy::Enemy;

    virtual bool isCollide(const Actor& other) const override;
    void update(sf::Time dt) override;
};

class BigMeteor : public Meteor {
  public:
    BigMeteor(Scene& scene);

    int getPoints() const override;
    void onDestroy() override;
};

class MediumMeteor : public Meteor {
  public:
    MediumMeteor(Scene& scene);

    int getPoints() const override;
    void onDestroy() override;
};

class SmallMeteor : public Meteor {
  public:
    SmallMeteor(Scene& scene);

    int getPoints() const override;
    void onDestroy() override;
};

#endif /* Meteor_hpp */
