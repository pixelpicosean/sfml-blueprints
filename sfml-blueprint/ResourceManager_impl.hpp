//
//  ResourceManager_impl.hpp
//  sfml-blueprint
//
//  Created by Sean on 12/30/15.
//  Copyright © 2015 Sean. All rights reserved.
//

template <typename RESOURCE, typename IDENTIFIER>
template <typename ... Args>
void ResourceManager<RESOURCE, IDENTIFIER>::load(const IDENTIFIER& id, Args&& ... args) {
  std::unique_ptr<RESOURCE> ptr(new RESOURCE);

  if (not ptr->loadFromFile(std::forward<Args>(args) ...)) {
    throw std::runtime_error("Failed to load file");
  }

  _map.emplace(id, std::move(ptr));
}

template <typename RESOURCE, typename IDENTIFIER>
RESOURCE& ResourceManager<RESOURCE, IDENTIFIER>::get(const IDENTIFIER& id) const {
  return *_map.at(id);
}


template <typename IDENTIFIER>
template <typename ... Args>
void ResourceManager<sf::Music, IDENTIFIER>::load(const IDENTIFIER& id, Args&& ... args) {
  std::unique_ptr<sf::Music> ptr(new sf::Music);

  if (not ptr->openFromFile(std::forward<Args>(args)...)) {
    throw std::runtime_error("Failed to load music");
  }

  _map.emplace(id, std::move(ptr));
}

template <typename IDENTIFIER>
sf::Music& ResourceManager<sf::Music, IDENTIFIER>::get(const IDENTIFIER &id) const {
  return *_map.at(id);
}
