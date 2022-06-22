#ifndef ControlMatrix.h
#define ControlMatrix.h
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>


class ControlMatrix8x8
{
    public:
        Adafruit_NeoPixel *pixels;
        ControlMatrix8x8(int _pin);
        int Convert(int x,int y);
        void GenerateSquarre(int x, int y, int taille, int color);
        void SetPixelByCood(int x, int y, int color);
        void Clear();
        int pin;

};

#endif