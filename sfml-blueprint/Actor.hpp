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

class Scene;
class Actor : public sf::Drawable {
  public:
    Actor(const Actor&) = delete;
    Actor& operator=(const Actor&) = delete;

    Actor(int texID, Scene* scene);
    virtual ~Actor();

    virtual bool isAlive() const;

    const sf::Vector2f& getPosition() const;
    template<typename ... Args>
    void setPosition(Args&& ... args);

    virtual bool isCollide(const Actor& other) const = 0;

    virtual void update(sf::Time delta) = 0;
    virtual void onDestroy();

  protected:
    sf::Sprite _sprite;
    sf::Vector2f _impulse;
    Scene *_scene;
    bool _alive;

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif /* Actor_hpp */
