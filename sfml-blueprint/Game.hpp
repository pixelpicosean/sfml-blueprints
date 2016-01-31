//
//  Game.hpp
//  sfml-blueprint
//
//  Created by Sean on 12/27/15.
//  Copyright © 2015 Sean. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <SFML/Graphics.hpp>

#include "spira/spira.hpp"

#include "Scene.hpp"

class Game {
  public:
    const int width;
    const int height;

  public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    Game(int w = 640, int h = 480);

    void run(int minFPS);

    void initLevel();

  private:
    void processEvents();
    void update(sf::Time delta);
    void render();

    void reset();

    sf::RenderWindow _window;

    spira::emitter<sf::Event> events;

    Scene _scene;
};

#endif /* Game_hpp */
