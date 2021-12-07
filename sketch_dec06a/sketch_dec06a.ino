/* Basic example code for MAX7219 LED dot matrix display with Arduino. More info: https://www.makerguides.com */
// Include the required Arduino libraries:
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
// Define hardware type, size, and output pins:
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 1
#define CS_PIN 10
// Create a new instance of the MD_Parola class with hardware SPI connection:
//MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// Setup for software SPI:
 #define DATA_PIN 11
 #define CLK_PIN 13
 MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
const int boton = 14; 



void setup() {
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
pinMode(4,OUTPUT);
pinMode(3,OUTPUT);
pinMode(2,OUTPUT);
pinMode(1,OUTPUT);
pinMode(0,OUTPUT);
  pinMode(boton, INPUT);
  // Intialize the object:
  myDisplay.begin();
  // Set the intensity (brightness) of the display (0-15):
  myDisplay.setIntensity(5);
  // Clear the display:
  myDisplay.displayClear();
  myDisplay.displayText("201213010", PA_RIGHT,600, 0, PA_SCROLL_RIGHT, PA_SCROLL_RIGHT);
  
}

void loop() {

  if (digitalRead(boton) == HIGH) {
    izquierdam();
    izquierda();
    
  }else{
    
    derecham();
    derecha();
    
  }

  if (myDisplay.displayAnimate()) {
    myDisplay.displayReset();
  }
}

void derecha(){
  
  digitalWrite(7,HIGH);
  delay(70);
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  delay(70);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  delay(70);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  delay(70);
  digitalWrite(4,LOW);
  digitalWrite(3,HIGH);
  delay(70);
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
  delay(70);
  digitalWrite(2,LOW);
  digitalWrite(1,HIGH);
  delay(70);
  digitalWrite(1,LOW);
  digitalWrite(0,HIGH);
  delay(70);
  digitalWrite(0,LOW);
  }
  void izquierda(){
    
  digitalWrite(0,HIGH);
  delay(70);
  digitalWrite(0,LOW);
  digitalWrite(1,HIGH);
  delay(70);
  digitalWrite(1,LOW);
  digitalWrite(2,HIGH);
  delay(70);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  delay(70);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(70);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  delay(70);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  delay(70);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  delay(70);
  digitalWrite(7,LOW);
  }

  void derecham(){
    myDisplay.setTextEffect(PA_SCROLL_RIGHT, PA_SCROLL_RIGHT);
    int velocidad = 600;
    int slide_scroll_speed = map(velocidad, 1023, 0, 400, 15);
    myDisplay.setSpeed(slide_scroll_speed);
    }
  void izquierdam(){
    myDisplay.setTextEffect(PA_SCROLL_LEFT, PA_SCROLL_LEFT);
    int velocidad = 600;
    int slide_scroll_speed = map(velocidad, 1023, 0, 400, 15);
    myDisplay.setSpeed(slide_scroll_speed);
    }
