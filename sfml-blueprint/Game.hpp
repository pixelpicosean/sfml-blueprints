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

class Game {
  public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    Game();

    void run(int fps);

  private:
    void processEvents();
    void update(sf::Time delta);
    void render();

    sf::RenderWindow _window;
    sf::CircleShape _player;
};

#endif /* Game_hpp */
