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
  _player(150)
{
  _player.setFillColor(sf::Color::Blue);
  _player.setPosition(10, 20);
}

void Game::run(int fps) {
  const sf::Time TIME_PER_FRAME = sf::seconds(1.0f / fps);

  sf::Clock clock;
  sf::Time timeSinceLastTick = sf::Time::Zero;

  while (_window.isOpen()) {
    processEvents();

    bool repaint = false;

    timeSinceLastTick += clock.restart();
    while (timeSinceLastTick > TIME_PER_FRAME) {
      timeSinceLastTick -= TIME_PER_FRAME;
      repaint = true;

      update(TIME_PER_FRAME);
    }

    if (repaint) render();
  }
}

void Game::processEvents() {
  sf::Event event;
  while (_window.pollEvent(event)) {
    if ((event.type == sf::Event::Closed) or (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)) {
      _window.close();
    }
  }
}

void Game::update(sf::Time delta) {}

void Game::render() {
  _window.clear();

  _window.draw(_player);

  _window.display();
}
