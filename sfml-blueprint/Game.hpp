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
#include "ResourceManager.hpp"
#include "ResourcePath.hpp"

#include "Player.hpp"

class Game {
  public:
    enum TEXTURES: int { PLAYER };
    ResourceManager<sf::Texture, int> textures;

    const int width;
    const int height;

  public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    Game(int w = 640, int h = 480);

    void run(int minFPS);

  private:
    void processEvents();
    void update(sf::Time delta);
    void render();

    void initTextures();

    sf::RenderWindow _window;
    Player _player;

    spira::emitter<sf::Event> events;
};

#endif /* Game_hpp */
