//
//  Actor.hpp
//  sfml-blueprint
//
//  Created by Sean on 1/17/16.
//  Copyright © 2016 Sean. All rights reserved.
//

#ifndef Actor_hpp
#define Actor_hpp

#include <SFML/Graphics.hpp>

#include "Data.hpp"

class Scene;
class Actor : public sf::Drawable {
  public:
    sf::Sprite sprite;
    Scene& scene;

  public:
    Actor(const Actor&) = delete;
    Actor& operator=(const Actor&) = delete;

    Actor(Data::TEXTURES texID, Scene& scene);
    virtual ~Actor() {}

    virtual bool isAlive() const;

    const sf::Vector2f& getPosition() const;
    template<typename ... Args>
    void setPosition(Args&& ... args);

    virtual bool isCollide(const Actor& other) const = 0;

    virtual void update(sf::Time delta) = 0;
    virtual void onDestroy();

  protected:
    sf::Vector2f _impulse;
    bool _alive;

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#include "Actor_impl.hpp"

#endif /* Actor_hpp */
