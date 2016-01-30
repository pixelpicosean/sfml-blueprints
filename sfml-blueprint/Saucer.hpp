//
//  Saucer.hpp
//  sfml-blueprint
//
//  Created by Sean on 1/29/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#ifndef Saucer_hpp
#define Saucer_hpp

#include "Enemy.hpp"

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

#endif /* Saucer_hpp */
