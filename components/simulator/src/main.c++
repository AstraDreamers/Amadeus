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
    sf::SoundBuffer buffer("crush_tekk.mp3");
    sf::Sound       sound(buffer);

    sound.play();

    while (sound.getStatus() == sf::Sound::Status::Playing) {
    }

    return 0;
}