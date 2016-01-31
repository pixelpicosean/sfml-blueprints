//
//  Player.hpp
//  sfml-blueprint
//
//  Created by Sean on 12/27/15.
//  Copyright © 2015 Sean. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "Actor.hpp"

class Scene;
class Player: public Actor {
  public:
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    Player(Scene& scene);

    bool isCollide(const Actor& other) const override;
    void update(sf::Time dt) override;
    void processEvents() {}
    void shoot();
    void goToHyperspace();
    void onDestroy() override;

  private:
    bool _isMoving = false;
    int _rotation = 0;
    sf::Time _timeSinceLastShoot;
};

#endif /* Player_hpp */
