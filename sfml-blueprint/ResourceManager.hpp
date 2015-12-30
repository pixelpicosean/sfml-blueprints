//
//  ResourceManager.hpp
//  sfml-blueprint
//
//  Created by Sean on 12/30/15.
//  Copyright © 2015 Sean. All rights reserved.
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <unordered_map>

#include <SFML/Audio.hpp>

template <typename RESOURCE, typename IDENTIFIER = int>
class ResourceManager {
  public:
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    ResourceManager() = default;

    template<typename ... Args>
    void load(const IDENTIFIER& id, Args&& ... args);

    RESOURCE& get(const IDENTIFIER& id) const;

  private:
    std::unordered_map<IDENTIFIER, std::unique_ptr<RESOURCE> > _map;
};


template <typename IDENTIFIER>
class ResourceManager<sf::Music, IDENTIFIER> {
  public:
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    ResourceManager() = default;

    template<typename ... Args>
    void load(const IDENTIFIER& id, Args&& ... args);

    sf::Music& get(const IDENTIFIER& id) const;

  private:
    std::unordered_map<IDENTIFIER, std::unique_ptr<sf::Music> > _map;
};

#include "ResourceManager_impl.hpp"

#endif /* ResourceManager_hpp */
