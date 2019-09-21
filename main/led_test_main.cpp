#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

#include "Arduino.h"

#define ESP32
#include "FastLED.h"

#define NUM_LEDS 50
#define DATA_PIN 15

CRGB leds[NUM_LEDS];

void setup()
{
//    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop()
{
    leds[0] = CRGB::White; FastLED.show(); delay(30);
    leds[0] = CRGB::Black; FastLED.show(); delay(30);
}

extern "C" void app_main(void)
{
    setup();

    while (1) {
        loop();
    }
}

#include "FastLED.cpp"
