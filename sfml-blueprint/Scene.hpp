//
//  Scene.hpp
//  sfml-blueprint
//
//  Created by Sean on 1/10/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <SFML/Graphics.hpp>
#include <list>

#include "Actor.hpp"

class Scene : public sf::Drawable {
  public:
    Scene(float x, float y);
    ~Scene();

    Scene(const Scene&) = delete;
    Scene& operator=(const Scene&) = delete;

    void add(Actor *actor);
    void clear();
    bool isCollide(const Actor &other);
    int size();
    std::list<Actor *> getActors() const;

    int getX() const;
    int getY() const;

    void update(sf::Time delta);

  private:
    const int _x;
    const int _y;

    std::list<Actor *> _actors;
    std::list<Actor *> _actors_tmp;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif /* Scene_hpp */
