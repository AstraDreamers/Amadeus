#pragma once
#include <stdint.h>

#define INPUT_SIZE  64
#define OUTPUT_SIZE 2

const uint32_t bnn_weights[OUTPUT_SIZE][INPUT_SIZE // 32] = {
    {0x70C98F3DU, 0x77EC6D6AU},
    {0xC9E3F017U, 0x3B685B95U},
};

const float bnn_biases[OUTPUT_SIZE] = {
    0.0f, 0.0f
};
