//
//  Utils.h
//  sfml-blueprint
//
//  Created by Sean on 1/29/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#ifndef Utils_h
#define Utils_h

#include <cmath>

namespace lp {

  float random(float min, float max) {
    return (std::rand() * 1.0 / RAND_MAX) * (max - min) + min;
  }

}

#endif /* Utils_h */
