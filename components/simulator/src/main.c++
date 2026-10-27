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

struct av_format_context_deleter {
    auto operator()(AVFormatContext *context) const -> void {
        if (context != nullptr) {
            avformat_close_input(&context);
        }
    }
};

auto print_error(int32_t error_code) {
    std::array<char, AV_ERROR_MAX_STRING_SIZE> buffer{};
    av_strerror(error_code, buffer.data(), buffer.size());
    std::println(stderr, "{}", buffer.data());
}

auto main() -> int32_t {
    const std::string filename{"crush_tekk.mp3"};

    std::unique_ptr<AVFormatContext, av_format_context_deleter> format_context{};

    {
        AVFormatContext *format_context_raw{nullptr};

        if (int32_t return_value{avformat_open_input(&format_context_raw, filename.c_str(), nullptr, nullptr)};
            return_value < 0) {
            print_error(return_value);
            return -1;
        }

        format_context.reset(format_context_raw);
    }

    return 0;
}