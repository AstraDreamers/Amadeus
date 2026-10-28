#include <algorithm>

/*
Amadeus - Binary Neural Network (BNN) AI that detects BPM in music at real time.
    Copyright (C) 2026  AstraDreamers

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

auto main() -> int32_t {
    sf::RenderWindow window(sf::VideoMode({1920, 1080}, 32), "simulator", sf::Style::Close, sf::State::Fullscreen);
    window.setFramerateLimit(144U);

    sf::SoundBuffer buffer("crush_tekk.mp3");
    sf::Sound       sound(buffer);

    sound.play();

    sf::VertexArray array;
    array.setPrimitiveType(sf::PrimitiveType::Lines);
    array.resize(1920U);

    std::span<const int16_t> sound_buffer(buffer.getSamples(), buffer.getSampleCount());

    while (window.isOpen()) {
        while (const std::optional event{window.pollEvent()}) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        int64_t position =
            static_cast<int64_t>(static_cast<float>(sound_buffer.size()) *
                                 (sound.getPlayingOffset().asSeconds() / buffer.getDuration().asSeconds()));

        position = std::min<int64_t>(position, sound_buffer.size() - 1920U);

        for (int32_t i{0}; i < 1920; i++) {
            array[i].position = {
                static_cast<float>(i),
                (1080.F / 2.F) * (static_cast<float>(sound_buffer[i + position]) / static_cast<float>(INT16_MAX)) +
                    (1080.F / 2.F)};
        }

        window.clear();
        window.draw(array);
        window.display();
    }

    return 0;
}