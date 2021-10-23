# ESP32-TFT-Library-ST7735
A library for 1.77'' tft displays with controller ST3357

![Display](https://github.com/schreibfaul1/ESP32-TFT-Library-ST7735/blob/main/images/Display%20ST7735-160x128.jpg)

![Schematic](https://github.com/schreibfaul1/ESP32-TFT-Library-ST7735/blob/main/images/ST7735.jpg)

````c++
#include "Arduino.h"
#include "tft.h"

TFT tft;

const uint8_t SPI_MOSI  = 23;
const uint8_t SPI_MISO  = 19;
const uint8_t SPI_SCK   = 18;

const uint8_t TFT_DC = 21;
const uint8_t TFT_CS = 22;

void setup() {

    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);
    tft.setFrequency(20000000); // 4MHz max
    tft.begin(TFT_CS, TFT_DC);
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);
    tft.setTextColor(TFT_WHITE);  tft.setTextSize(1);
    tft.println("Hello World!");
    tft.setTextColor(TFT_YELLOW); tft.setTextSize(2);
    tft.println(1234.56);
    tft.setTextColor(TFT_RED);    tft.setTextSize(3);
    tft.println(0xDEADBEEF, HEX);
    tft.setTextColor(TFT_GREEN);  tft.setTextSize(5);
    tft.print("Display");
}

//-------------------------------------------------------------------------------------
void loop(void) {

}
````
