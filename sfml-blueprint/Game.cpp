//
//  Game.cpp
//  sfml-blueprint
//
//  Created by Sean on 12/27/15.
//  Copyright © 2015 Sean. All rights reserved.
//

#include "Game.hpp"

bool isCloseWindow(const sf::Event& evt) {
  return evt.type == sf::Event::Closed;
}

bool pressedEsc(const sf::Event& evt) {
  return evt.type == sf::Event::KeyPressed and evt.key.code == sf::Keyboard::Escape;
}

Game::Game(int w, int h):
  width(w), height(h),
  _window(sf::VideoMode(w, h), "Asteroid")
{
  // Force vsync for better result
  _window.setVerticalSyncEnabled(true);

  // Streams and handlers
  auto whenToCloseWindow$ = events.filter(isCloseWindow);
  auto whenToPressEsp$ = events.filter(pressedEsc);

  auto whenToQuit$ = whenToCloseWindow$.merge(whenToPressEsp$)
    .map<bool>([](const sf::Event&) { return true; });

  whenToQuit$.onValue([this](bool) {
    _window.close();
  });
}

void Game::run(int minFPS) {
  // Initialize
  Data::init();

  _player.setTexture(Data::textures.get(Data::TEXTURES::PLAYER));
  _player.setPosition(width / 2, height / 2);

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
