//
//  Scene.cpp
//  sfml-blueprint
//
//  Created by Sean on 1/10/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#include "Scene.hpp"

Scene::Scene(float x, float y):
  _x(x), _y(y)
{

}

Scene::~Scene() {
  clear();
}

void Scene::add(Actor *actor) {
  _actors_tmp.push_back(actor);
}

void Scene::clear() {
  for (Actor *actor : _actors) {
    delete actor;
  }

  _actors.clear();

  for (Actor *actor : _actors_tmp) {
    delete actor;
  }

  _actors_tmp.clear();
}

bool Scene::isCollide(const Actor &other) {
  for (Actor *actor : _actors) {
    if (other.isCollide(*actor)) {
      return true;
    }
    return false;
  }
}

int Scene::size() {
  return _actors.size() + _actors_tmp.size();
}

int Scene::getX() const {
  return _x;
}

int Scene::getY() const {
  return _y;
}

std::list<Actor *> Scene::getActors() const {
  return _actors;
}

void Scene::update(sf::Time delta) {
  if (_actors_tmp.size() > 0) {
    _actors.merge(_actors_tmp);
  }

  for (Actor *actor_ptr : _actors) {
    Actor &actor = *actor_ptr;
    actor.update(delta);

    sf::Vector2f pos = actor.getPosition();
    if (pos.x < 0) {
      pos.x = _x;
      pos.y = _y - pos.y;
    }
    else if (pos.x > _x) {
      pos.x = 0;
      pos.y = _y - pos.y;
    }
    if (pos.y < 0) {
      pos.y = _y;
    }
    else if (pos.y > _y) {
      pos.y = 0;
    }

    actor.setPosition(pos);
  }

  const auto end = _actors.end();

  for (auto it_i = _actors.begin(); it_i != end; ++it_i) {
    Actor &actor_i = **it_i;

    auto it_j = it_i;
    it_j++;

    for (; it_j != end; ++it_j) {
      Actor &actor_j = **it_j;

      if (actor_i.isAlive() and actor_i.isCollide(actor_j)) {
        actor_i.onDestroy();
      }
      if (actor_j.isAlive() and actor_j.isCollide(actor_i)) {
        actor_j.onDestroy();
      }
    }

    for (auto it = _actors.begin(); it != _actors.end();) {
      if (not (*it)->isAlive()) {
        delete (*it);
        it = _actors.erase(it);
      }
      else {
        ++it;
      }
    }
  }
}

void Scene::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  for (Actor *actor: _actors) {
    target.draw(*actor, states);
  }
}
