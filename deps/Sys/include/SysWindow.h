#ifndef SYSWINDOW_H
#define SYSWINDOW_H

#include <stdint.h>
#include <stdbool.h>

typedef struct BitmapWindow BitmapWindow;
BitmapWindow* BitmapWindow_Create(int x, int y, int clientWidth, int clientHeight);
bool BitmapWindow_Exists(BitmapWindow* instance);
void BitmapWindow_Destroy(BitmapWindow* instance);
void BitmapWindow_Update(BitmapWindow* instance);
void BitmapWindow_SetPixel(BitmapWindow* instance, int x, int y, uint32_t pixel);
void BitmapWindow_SetPixels(BitmapWindow* instance, uint32_t* pixels, int width, int height);
void BitmapWindow_SetPixelsScaled(BitmapWindow* instance, uint32_t* pixels, int width, int height, int scale);
void BitmapWindow_SetPixelsScaled2(BitmapWindow* instance, uint8_t* pixels, int width, int height, int scale);
bool BitmapWindow_KeyDown_W(BitmapWindow* instance);
bool BitmapWindow_KeyDown_A(BitmapWindow* instance);
bool BitmapWindow_KeyDown_S(BitmapWindow* instance);
bool BitmapWindow_KeyDown_D(BitmapWindow* instance);
bool BitmapWindow_KeyDown_E(BitmapWindow* instance);
bool BitmapWindow_KeyDown_Q(BitmapWindow* instance);
bool BitmapWindow_KeyDown_UP(BitmapWindow* instance);
bool BitmapWindow_KeyDown_LEFT(BitmapWindow* instance);
bool BitmapWindow_KeyDown_DOWN(BitmapWindow* instance);
bool BitmapWindow_KeyDown_RIGHT(BitmapWindow* instance);

#endif
