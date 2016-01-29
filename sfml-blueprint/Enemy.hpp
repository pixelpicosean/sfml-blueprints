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

class Enemy : public Actor {
  public:
    Enemy(const Enemy&) = delete;
    Enemy& operator=(const Enemy&) = delete;

    Enemy(Data::TEXTURES texID, Scene& scene);

    virtual int getPoints() const = 0;
    virtual void onDestroy() override;
};

#endif /* Enemy_hpp */
