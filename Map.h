/*
   Fibonacci Demo Reel: https://github.com/jasoncoon/fibonacci-demoreel
   Copyright (C) 2022 Jason Coon

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

const uint8_t  physicalToFibonacci[NUM_LEDS] { 0, 21, 42, 63, 84, 105, 126, 113, 92, 71, 50, 29, 8, 16, 37, 58, 79, 100, 121, 108, 87, 66, 45, 24, 3, 11, 32, 53, 74, 95, 116, 124, 103, 82, 61, 40, 19, 6, 27, 48, 69, 90, 111, 119, 98, 77, 56, 35, 14, 1, 22, 43, 64, 85, 106, 127, 114, 93, 72, 51, 30, 9, 17, 38, 59, 80, 101, 122, 109, 88, 67, 46, 25, 4, 12, 33, 54, 75, 96, 117, 125, 104, 83, 62, 41, 20, 7, 28, 49, 70, 91, 112, 120, 99, 78, 57, 36, 15, 2, 23, 44, 65, 86, 107, 115, 94, 73, 52, 31, 10, 18, 39, 60, 81, 102, 123, 110, 89, 68, 47, 26, 5, 13, 34, 55, 76, 97, 118 };
const uint8_t  fibonacciToPhysical[NUM_LEDS] { 0, 49, 98, 24, 73, 121, 37, 86, 12, 61, 109, 25, 74, 122, 48, 97, 13, 62, 110, 36, 85, 1, 50, 99, 23, 72, 120, 38, 87, 11, 60, 108, 26, 75, 123, 47, 96, 14, 63, 111, 35, 84, 2, 51, 100, 22, 71, 119, 39, 88, 10, 59, 107, 27, 76, 124, 46, 95, 15, 64, 112, 34, 83, 3, 52, 101, 21, 70, 118, 40, 89, 9, 58, 106, 28, 77, 125, 45, 94, 16, 65, 113, 33, 82, 4, 53, 102, 20, 69, 117, 41, 90, 8, 57, 105, 29, 78, 126, 44, 93, 17, 66, 114, 32, 81, 5, 54, 103, 19, 68, 116, 42, 91, 7, 56, 104, 30, 79, 127, 43, 92, 18, 67, 115, 31, 80, 6, 55 };
const uint8_t coordsX[NUM_LEDS] = { 137, 181, 201, 213, 219, 221, 218, 193, 198, 199, 195, 184, 160, 164, 176, 178, 175, 167, 154, 127, 142, 152, 158, 157, 142, 140, 140, 132, 119, 103, 85, 45, 65, 84, 101, 116, 126, 121, 106, 89, 70, 51, 32, 9, 25, 43, 63, 83, 104, 118, 84, 62, 42, 25, 11, 0, 11, 19, 32, 47, 68, 96, 81, 58, 43, 33, 27, 26, 49, 47, 50, 58, 74, 105, 94, 77, 70, 69, 74, 83, 125, 110, 99, 91, 90, 96, 114, 108, 112, 121, 135, 152, 193, 174, 156, 141, 129, 123, 130, 141, 155, 172, 191, 210, 239, 221, 202, 182, 164, 145, 164, 186, 206, 225, 241, 255, 248, 237, 222, 204, 182, 151, 170, 196, 214, 227, 236, 241 };
const uint8_t coordsY[NUM_LEDS] = { 130, 137, 150, 166, 184, 204, 224, 235, 216, 197, 178, 159, 141, 160, 182, 203, 222, 240, 255, 251, 237, 221, 202, 180, 147, 167, 195, 215, 229, 240, 247, 227, 228, 225, 216, 202, 181, 158, 186, 199, 206, 207, 203, 166, 177, 184, 185, 181, 166, 139, 161, 165, 161, 152, 139, 122, 96, 114, 129, 140, 146, 143, 132, 123, 110, 93, 74, 55, 39, 59, 78, 96, 112, 126, 109, 89, 69, 49, 30, 13, 0, 13, 28, 46, 67, 90, 102, 72, 50, 33, 19, 9, 21, 24, 31, 43, 60, 85, 112, 75, 57, 47, 42, 42, 74, 66, 63, 66, 75, 96, 95, 86, 85, 91, 101, 115, 142, 126, 114, 106, 105, 115, 121, 124, 134, 148, 166, 185 };
const uint8_t angles[NUM_LEDS] = { 156, 145, 146, 149, 152, 156, 160, 167, 163, 159, 155, 153, 152, 158, 161, 165, 169, 173, 178, 184, 179, 175, 170, 166, 162, 169, 175, 180, 185, 190, 196, 208, 202, 197, 191, 185, 179, 177, 189, 196, 203, 209, 215, 230, 223, 216, 208, 200, 189, 174, 202, 213, 222, 231, 238, 246, 2, 248, 239, 229, 216, 195, 213, 234, 248, 4, 13, 22, 35, 26, 16, 3, 237, 184, 215, 17, 31, 41, 49, 56, 74, 68, 63, 57, 50, 45, 134, 75, 73, 76, 80, 85, 99, 95, 92, 89, 89, 104, 143, 106, 101, 102, 105, 108, 120, 117, 114, 112, 113, 124, 125, 121, 122, 125, 128, 132, 139, 135, 132, 130, 130, 140, 139, 138, 139, 142, 146, 150 };

void anglePalette() {
  uint8_t hues = 1;

  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t x = angles[i];

    leds[i] = ColorFromPalette(palettes[currentPaletteIndex], beat8(speed) - (x * hues));
  }
}

void radiusPalette() {
  uint8_t hues = 1;

  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t r = physicalToFibonacci[i];
    
    leds[i] = ColorFromPalette(palettes[currentPaletteIndex], beat8(speed) - (r * hues));
  }
}

void xPalette() {
  uint8_t hues = 1;

  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t x = coordsX[i];

    leds[i] = ColorFromPalette(palettes[currentPaletteIndex], beat8(speed) - (x * hues));
  }
}

void yPalette() {
  uint8_t hues = 1;

  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t y = coordsY[i];

    leds[i] = ColorFromPalette(palettes[currentPaletteIndex], beat8(speed) - (y * hues));
  }
}

void xyPalette() {
  uint8_t hues = 1;

  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t x = coordsX[i];
    uint8_t y = coordsY[i];

    leds[i] = ColorFromPalette(palettes[currentPaletteIndex], beat8(speed) - ((x + y) * hues));
  }
}

void angleGradientPalette() {
  uint8_t hues = 1;

  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t x = angles[i];

    leds[i] = ColorFromPalette(gCurrentPalette, beat8(speed) - (x * hues));
  }
}

void radiusGradientPalette() {
  uint8_t hues = 1;

  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t r = physicalToFibonacci[i];
    
    leds[i] = ColorFromPalette(gCurrentPalette, beat8(speed) - (r * hues));
  }
}

void xGradientPalette() {
  uint8_t hues = 1;
  
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t x = coordsX[i];

    leds[i] = ColorFromPalette(gCurrentPalette, beat8(speed) - (x * hues));
  }
}

void yGradientPalette() {
  uint8_t hues = 1;
  
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t y = coordsY[i];

    leds[i] = ColorFromPalette(gCurrentPalette, beat8(speed) - (y * hues));
  }
}

void xyGradientPalette() {
  uint8_t hues = 1;
  
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t x = coordsX[i];
    uint8_t y = coordsY[i];

    leds[i] = ColorFromPalette(gCurrentPalette, beat8(speed) - ((x + y) * hues));
  }
}
