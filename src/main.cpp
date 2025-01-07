#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"
#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <cstdlib>
#include <iostream>


int main() {

  const int wWidth{1280};
  const int wHeight{720};

  sf::RenderWindow window(sf::VideoMode(wWidth, wHeight),
                          "SFML + ImGui works!");
  window.setFramerateLimit(60);
  sf::Font font;
  if (!font.loadFromFile("fonts/quicksand.ttf")) {
    std::cerr << "Could not load font!" << std::endl;
    exit(-1);
  }
  
  // intialize IMGUI and create a clock used for its internal timing
  ImGui::SFML::Init(window);
  sf::Clock deltaClock;

  // scale the ImgGui UI and Font size
  ImGui::GetStyle().ScaleAllSizes(1.0f);
  ImGui::GetIO().FontGlobalScale = 1.0f;

  // variables to feed ImGui UI
  bool drawText{true};
  float sliderValue = 0.0f;
  float textColor[3] = {0.0f, 0.38f, 1.0f};
  char buffer[255] = "i[arr] += j[arr]";
  int fontSize {64};
  sf::Text text("Sample Text", font, fontSize);
  text.setPosition(wWidth * 0.5 - (float)text.getLocalBounds().width * 0.5,
                   wHeight * 0.5 - (float)text.getCharacterSize());

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      // pass event to imgui
      ImGui::SFML::ProcessEvent(window, event);

      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // update imgui for this frame with the time that the last frame took
    ImGui::SFML::Update(window, deltaClock.restart());
    // UI
    ImGui::Begin("ImGui + SFML template");
    ImGui::Checkbox("Draw Text", &drawText);
    ImGui::SameLine();
    ImGui::SliderFloat("Value", &sliderValue, 0.0f, 10.0f);
    ImGui::ColorEdit3("Color", textColor);
	  ImGui::SliderInt("Font Size", &fontSize, 8, 128);
    ImGui::InputText("Text", buffer, 255);
    if (ImGui::Button("Set Text")) {
      text.setString(buffer);
    }
    ImGui::End();

    text.setCharacterSize(fontSize);
    text.setPosition(wWidth * 0.5 - (float)text.getLocalBounds().width * 0.5, 
            wHeight * 0.5 - (float)text.getCharacterSize() * 0.5);
      // The imgui color(r,g,b) wheel requires floats in 0-1 range instead of ints 0-255
    text.setFillColor(sf::Color(
      sf::Uint8(textColor[0]*255),
      sf::Uint8(textColor[1]*255),
      sf::Uint8(textColor[2]*255))
    );

    window.clear();
    if (drawText) {
      window.draw(text);
    }

    // draw the UI as last so it's on the top layer
    ImGui::SFML::Render(window);
    window.display();
  }

  return 0;
}