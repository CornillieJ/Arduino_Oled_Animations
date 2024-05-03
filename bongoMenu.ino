#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <string.h>
#include "bongoCat.h"
#include "kirby.h"
#include "navi.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define OPTIONSIZE 4
String options[OPTIONSIZE] = { "BongoCat", "Kirby", "Navi","Turn Off"};
byte kirbyState = 0;
byte naviState = 0;



byte input_left = 9;
byte input_right = 2;
byte input_select = 3;
void setup() {
  pinMode ( input_left, INPUT );
  digitalWrite ( input_left, HIGH ); // enables internal pullup
  pinMode ( input_right, INPUT );
  digitalWrite ( input_right, HIGH ); // enables internal pullup
  pinMode ( input_select, INPUT );
  digitalWrite ( input_select, HIGH ); // enables internal pullup

  Serial.begin(9600);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
}

void loop() {
  byte selection = mainMenu();
  while(digitalRead(input_select) != LOW){
    display.clearDisplay();
    display.setRotation(2);
    switch(selection){
    case 0:
      showBongoCat();
      break;
    case 1:
      showKirby();
      break;
    case 2:
      showNavi();
      break;
    case 3:
      turnOff();
      break;
    }
  }
  debounceInput(input_select);
}
void debounceInput(int pin){
  byte debounce = 0;
  while(debounce<150){
    if(digitalRead(pin) != LOW)  debounce++;
    else debounce = 0;
    delay(1);
  }
}
byte mainMenu(){
  kirbyState = 0;
  naviState = 0;
  byte selection = 0;
  byte selected = 0;
  while(selected == 0){
    display.clearDisplay();
    display.setTextSize(2);
    display.setRotation(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println(options[selection]);
    display.display();
    delay(10);
    if(digitalRead(input_right) == LOW){
      if(selection < OPTIONSIZE - 1) selection = selection + 1;
      else selection = 0;
      debounceInput(input_right);
    }
    else if(digitalRead(input_left) == LOW){
      if(selection > 0) selection = selection - 1;
      else selection = (OPTIONSIZE -1);
      debounceInput(input_left);
    }
    if(digitalRead(input_select) == LOW){
      selected = 1;
      byte turnOff = 0;
    }
  }
  debounceInput(input_select);
  return selection;  
}
void turnOff(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setRotation(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println(F("GoodBye"));
  display.display();
  delay(500);
  display.clearDisplay();
  display.setTextSize(2);
  display.setRotation(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println(F("GoodBye."));
  display.display();
  delay(500);
  display.clearDisplay();
  display.setTextSize(2);
  display.setRotation(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println(F("GoodBye.."));
  display.display();
  delay(500);
  display.clearDisplay();
  display.setTextSize(2);
  display.setRotation(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println(F("GoodBye..."));
  display.display();
  delay(500);
  display.clearDisplay();
  display.display();
  exit(0);
}
void showBongoCat(){
  display.drawBitmap(0, 0, bongocat, 128, 32, WHITE);
  display.display();
  delay(10);
  if(digitalRead(input_left) == LOW){
    display.clearDisplay();
    display.setRotation(2);
    display.drawBitmap(0, 0, taps[0], 128, 32, WHITE);
    display.display();
    delay(300);
  }
  if(digitalRead(input_right) == LOW){
    display.clearDisplay();
    display.setRotation(2);
    display.drawBitmap(0, 0, taps[1], 128, 32, WHITE);
    display.display();
    delay(300);
  }
}
void showKirby(){
  if(kirbyState == 0){
    display.clearDisplay();
    display.drawBitmap(0, 0,kirbyArray[0], 128, 32, WHITE);
    display.display();
    delay(10);
    if(digitalRead(input_right) == LOW){  
      for(byte i = 0; i < 7; i++){
        kirbyState = 1;
        display.clearDisplay();
        display.drawBitmap(0, 0,kirbyArray[i], 128, 32, WHITE);
        display.display();
        delay(200);
      }
      debounceInput(input_right);
    }
  }
  else{
    display.clearDisplay();
    display.drawBitmap(0, 0,kirbyArray[7], 128, 32, WHITE);
    display.display();
    delay(10);
    if(digitalRead(input_left) == LOW){  
      for(byte i = 7; i < kirbyArray_LEN; i++){
        kirbyState = 0;
        display.clearDisplay();
        display.drawBitmap(0, 0,kirbyArray[i], 128, 32, WHITE);
        display.display();
        delay(200);
      }
      debounceInput(input_left);
    }
  }
}
void showNavi(){
  display.clearDisplay();
  display.drawBitmap(0, 0,naviArray[naviState], 128, 32, WHITE);
  display.display();
  delay(100);
  naviState++;
  if(naviState == naviArray_LEN) naviState = 0;
}