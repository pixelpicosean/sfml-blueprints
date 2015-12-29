//
//  Game.cpp
//  sfml-blueprint
//
//  Created by Sean on 12/27/15.
//  Copyright © 2015 Sean. All rights reserved.
//

#include "Game.hpp"

Game::Game():
  _window(sf::VideoMode(800, 600), "02 Game Archi"),
  _player(200, 300)
{
  // Force vsync for better result
  _window.setVerticalSyncEnabled(true);

  // Streams and handlers
  auto whenToCloseWindow$ = events.filter([this] (const sf::Event& evt) {
    return evt.type == sf::Event::Closed;
  });
  auto whenToPressEsp$ = events.filter([this](const sf::Event& evt) {
    return evt.type == sf::Event::KeyPressed and evt.key.code == sf::Keyboard::Escape;
  });

  auto whenToQuit$ = whenToCloseWindow$.merge(whenToPressEsp$)
    .map<bool>([](const sf::Event&) { return true; });

  whenToQuit$.onValue([this](bool) {
    _window.close();
  });
}

void Game::run(int minFPS) {
  // Setup timer
  const sf::Time TIME_PER_FRAME = sf::seconds(1.0f / minFPS);

  sf::Clock clock;
  sf::Time timeSinceLastTick;

  // Start game loop
  while (_window.isOpen()) {
    processEvents();

    timeSinceLastTick = clock.restart();

    while (timeSinceLastTick > TIME_PER_FRAME) {
      timeSinceLastTick -= TIME_PER_FRAME;
      update(TIME_PER_FRAME);
    }

    update(timeSinceLastTick);
    render();
  }
}

void Game::processEvents() {
  sf::Event event;
  while (_window.pollEvent(event)) {
    events.emit(event);

    if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Up) {
        _player.isMoving = true;
      }
      else if (event.key.code == sf::Keyboard::Left) {
        _player.rotation = -1;
      }
      else if (event.key.code == sf::Keyboard::Right) {
        _player.rotation = 1;
      }
    }
    else if (event.type == sf::Event::KeyReleased) {
      if (event.key.code == sf::Keyboard::Up) {
        _player.isMoving = false;
      }
      else if (event.key.code == sf::Keyboard::Left) {
        _player.rotation = 0;
      }
      else if (event.key.code == sf::Keyboard::Right) {
        _player.rotation = 0;
      }
    }
  }
}

void Game::update(sf::Time delta) {
  _player.update(delta);
}

void Game::render() {
  _window.clear();

  _window.draw(_player);

  _window.display();
}
