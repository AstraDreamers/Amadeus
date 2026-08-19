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

#include <array>

namespace bnn {
    template <typename main_data_type, typename threshold_data_type, std::size_t neuron_count_word>
    struct neuron_layer {
        static constexpr std::size_t neuron_count{neuron_count_word * std::numeric_limits<main_data_type>::digits};

        std::array<threshold_data_type, neuron_count> thresholds{};
        std::array<main_data_type, neuron_count_word> outputs{};
    };

    template <std::size_t neuron_count_word>
    using neuron_layer_u8u8 = neuron_layer<uint8_t, uint8_t, neuron_count_word>;

    template <std::size_t neuron_count_word>
    using neuron_layer_u16u8 = neuron_layer<uint16_t, uint8_t, neuron_count_word>;

    template <std::size_t neuron_count_word>
    using neuron_layer_u16u16 = neuron_layer<uint16_t, uint16_t, neuron_count_word>;

    template <std::size_t neuron_count_word>
    using neuron_layer_u32u8 = neuron_layer<uint32_t, uint8_t, neuron_count_word>;

    template <std::size_t neuron_count_word>
    using neuron_layer_u32u16 = neuron_layer<uint32_t, uint16_t, neuron_count_word>;

    template <std::size_t neuron_count_word>
    using neuron_layer_u32u32 = neuron_layer<uint32_t, uint32_t, neuron_count_word>;
} // namespace bnn

auto main() -> int {
    std::cout << "Hello World!\n";
    return 0;
}