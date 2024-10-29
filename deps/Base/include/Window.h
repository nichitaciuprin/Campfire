#pragma once

#include "SysWindow.h"

class BitmapWindow2
{
public:
    BitmapWindow2(int x, int y, int clientWidth, int clientHeight) { instance = BitmapWindow_Create(x, y, clientWidth, clientHeight); }
    ~BitmapWindow2() { BitmapWindow_Destroy(instance); }
    bool Exists() const { return BitmapWindow_Exists(instance); }
    void Update() { BitmapWindow_Update(instance); }
    void SetPixel(int x, int y, uint32_t pixel) { BitmapWindow_SetPixel(instance, x, y, pixel); }
    void SetPixels(uint32_t* pixels, int width, int height) { BitmapWindow_SetPixels(instance, pixels, width, height); }
    void SetPixelsScaled(uint32_t* pixels, int width, int height, int scale) { BitmapWindow_SetPixelsScaled(instance, pixels, width, height, scale); }
    void SetPixelsScaled2(uint8_t* pixels, int width, int height, int scale) { BitmapWindow_SetPixelsScaled2(instance, pixels, width, height, scale); }
    bool KeyDown_W() { return BitmapWindow_KeyDown_W(instance); };
    bool KeyDown_A() { return BitmapWindow_KeyDown_A(instance); };
    bool KeyDown_S() { return BitmapWindow_KeyDown_S(instance); };
    bool KeyDown_D() { return BitmapWindow_KeyDown_D(instance); };
    bool KeyDown_E() { return BitmapWindow_KeyDown_E(instance); };
    bool KeyDown_Q() { return BitmapWindow_KeyDown_Q(instance); };
    bool KeyDown_UP() { return BitmapWindow_KeyDown_UP(instance); };
    bool KeyDown_LEFT() { return BitmapWindow_KeyDown_LEFT(instance); };
    bool KeyDown_DOWN() { return BitmapWindow_KeyDown_DOWN(instance); };
    bool KeyDown_RIGHT() { return BitmapWindow_KeyDown_RIGHT(instance); };

private:
    BitmapWindow* instance;
};
