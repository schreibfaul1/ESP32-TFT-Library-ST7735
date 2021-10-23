#include "Arduino.h"
#include "SPI.h"
#include "SD.h"
#include "tft.h"

TFT tft[3];

const uint8_t SPI_MOSI  = 23;
const uint8_t SPI_MISO  = 19;
const uint8_t SPI_SCK   = 18;
const uint8_t SD_CS     =  5;
const uint8_t TFT_DC    = 21;
const uint8_t TFT_CS[3] = {22, 32, 33};

void testText(uint8_t nr); // function prototyp

void setup() {
    Serial.begin(115200);

    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);
    SPI.setFrequency(20000000);
    SD.begin(5);
    tft[0].setFrequency(20000000);
    tft[0].begin(TFT_CS[0], TFT_DC);
    tft[0].fillScreen(TFT_GREEN);

    tft[1].setFrequency(20000000);
    tft[1].begin(TFT_CS[1], TFT_DC);
    tft[1].fillScreen(TFT_BLUE);

    tft[2].setFrequency(20000000);
    tft[2].begin(TFT_CS[2], TFT_DC);
    tft[2].fillScreen(TFT_ORANGE);

    tft[0].setRotation(0);
    tft[0].drawJpgFile(SD, "/nixie/1.jpg", 0, 0);

    tft[1].setRotation(0);
    tft[1].drawJpgFile(SD, "/nixie/2.jpg", 0, 0);

    tft[2].setRotation(0);
    tft[2].drawJpgFile(SD, "/nixie/3.jpg", 0, 0);

    delay(15000);

}

//-------------------------------------------------------------------------------------
void loop(void) {
    for(uint8_t rotation=0; rotation<4; rotation++) {
        tft[0].setRotation(rotation);
        testText(0);
        tft[1].setRotation(rotation);
        testText(1);
        tft[2].setRotation(rotation);
        testText(2);
        delay(3000);
    }
}
//-------------------------------------------------------------------------------------

void testText(uint8_t nr) {
    tft[nr].fillScreen(TFT_BLACK);
    tft[nr].setCursor(0, 0);
    tft[nr].setTextColor(TFT_WHITE);  tft[nr].setTextSize(1);
    tft[nr].println("Hello World!");
    tft[nr].setTextColor(TFT_YELLOW); tft[nr].setTextSize(2);
    tft[nr].println(1234.56);
    tft[nr].setTextColor(TFT_RED);    tft[nr].setTextSize(3);
    tft[nr].println(0xDEADBEEF, HEX);
    tft[nr].setTextColor(TFT_GREEN);
    tft[nr].setTextSize(6);
    tft[nr].print("Disp"); tft[nr].println(nr);
}




