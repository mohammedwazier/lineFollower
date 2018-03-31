//main Coding Mikrocontroller
/*
 * Copyright Reserved Muhammad Waziruddin Akbar
 * 6702160088
 * Script Combined in Bojongsoang Telkom University
 * Open Source MIT License
 */
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
Adafruit_SSD1306 display=Adafruit_SSD1306();
int r0=0;
int r1=0;
int r2=0;
//Declare Var for mux
int s0=12;
int s1=8;
int s2=7;
//Dencare Input Var
int out=A0;
//Declare Output Var
int led=13;
//Sensor Output
int valOutSensor=1;
int arraySensor[8]={1,1,1,1,1,1,1};
void setup() {
  //Setup Begin Oled
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);
  display.display();
  display.clearDisplay();
  delay(500);
  //Setup Pin
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  //Setup Other Var
  pinMode(out, INPUT);
  pinMode(led, OUTPUT); 
}
void loop() {
//  readSensorF();
}
void readSensorF(){
  for(int i=0;i<8;i++){
    r0=bitRead(i,0);
    r1=bitRead(i,1);
    r2=bitRead(i,2);

    digitalWrite(s0,r0);
    digitalWrite(s1,r1);
    digitalWrite(s2,r2);
    valOutSensor=digitalRead(out);
    arraySensor[i]=valOutSensor;
  }
}
void buttonPush(){
//  digitalWrite(led, HIGH);
  
}
int readValString(String a){
  return a.length();
}
int row(int a){
  if(a==1){
    return 0;
  }else if(a==2){
    return 8;
  }else if(a==3){
    return 16;
  }else if(a==4){
    return 24;
  }else if(a==5){
    return 32;
  }
}
