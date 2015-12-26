#include <SFML/Graphics.hpp>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

int main(int argc, char const* argv[]) {
  // Create the main window
  sf::RenderWindow window(sf::VideoMode(400, 400), "SFML blueprint");

  // Create a circle
  sf::CircleShape circle(150);
  circle.setFillColor(sf::Color::Cyan);
  circle.setPosition(10, 20);

  // Start the game loop
  while (window.isOpen()) {
    // Process events
    sf::Event event;
    while (window.pollEvent(event)) {
      // Close window: exit
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // Escape pressed: exit
      if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        window.close();
      }
    }

    // Clear screen
    window.clear();

    // Draw something
    window.draw(circle);

    // Update the window
    window.display();
  }

  return 0;
}
