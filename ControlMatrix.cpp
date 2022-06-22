#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "ControlMatrix.h"
#define NUMPIXELS 64

ControlMatrix8x8::ControlMatrix8x8(int _pin){
    pin = _pin;
    pixels = new Adafruit_NeoPixel(NUMPIXELS, pin, NEO_GRB + NEO_KHZ800);
    pixels->begin();
    pixels->setBrightness(2);
}

int ControlMatrix8x8::Convert(int x, int y){
  if(x>7||x<0||y>7||y<0) return -1;
  return 7+8*x - y;
}

void ControlMatrix8x8::GenerateSquarre(int x, int y, int taille, int color){
    for(int i = 0; i < taille; i++ ){
      pixels->setPixelColor(ControlMatrix8x8::Convert(x+i,y), color);
      pixels->setPixelColor(ControlMatrix8x8::Convert(x+taille-1,y+i), color);
      pixels->setPixelColor(ControlMatrix8x8::Convert(x+taille-1-i,y+taille-1), color);
      pixels->setPixelColor(ControlMatrix8x8::Convert(x,y+taille-1-i), color);
    }
    pixels->show();
}

void ControlMatrix8x8::SetPixelByCoord(int x, int y, int color){
    pixels->setPixelColor(ControlMatrix8x8::Convert(x,y), color);
    pixels->show();
}

void ControlMatrix8x8::Clear(){
    pixels->clear();
    pixels->show();
}
