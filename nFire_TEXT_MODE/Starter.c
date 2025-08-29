#include "image_data.h"

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define VIDEO_MEMORY ((volatile uint16_t*)0xB8000)

void k_main() {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        uint8_t c = image_chars[i];
        uint8_t color = image_colors[i];
        uint16_t v = (color << 8) | c;
        VIDEO_MEMORY[i] = v;
    }

    while (1);
}
