//
//  Actor_impl.hpp
//  sfml-blueprint
//
//  Created by Sean on 1/31/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#include <utility>

template <typename ... Args>
void Actor::setPosition(Args&& ... args) {
  this->sprite.setPosition(std::forward<Args>(args)...);
}
