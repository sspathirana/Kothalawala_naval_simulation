#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

#define TCAADDR 0x70

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


// Helper function for changing TCA output channel
void tcaselect(uint8_t channel) {
  if (channel > 7) return;
  
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << channel);
  Wire.endTransmission();
  // Serial.print(TCAADDR);  
}

void setupOled() {
  
  // Serial.begin(9600);
 
  // Start I2C communication with the Multiplexer
  Wire.begin();

  // Init OLED display on bus number 0
  tcaselect(0);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 

   // Clear the buffer
  display.clearDisplay();
  
  // Init OLED display on bus number 1
   tcaselect(1);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 
  
  // Clear the buffer
  display.clearDisplay();

  tcaselect(2);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 

   // Clear the buffer
  display.clearDisplay();
  
  // Init OLED display on bus number 1
   tcaselect(3);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 
  
  // Clear the buffer
  display.clearDisplay();

  tcaselect(4);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 

   // Clear the buffer
  display.clearDisplay();
  
  // Init OLED display on bus number 1
   tcaselect(5);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 
  
 display.clearDisplay();
  
  // Init OLED display on bus number 1
   tcaselect(6);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 
display.clearDisplay();
  
  // Init OLED display on bus number 1
   tcaselect(7);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 

 // Clear the buffer
  display.clearDisplay();

  // Write to OLED on bus number 0
  tcaselect(0);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  //display.setCursor(50, 5);
  int cool_sys_temp_1=25;
  // Display static text
  display.println(cool_sys_temp_1);
  display.display(); 

  
  // Write to OLED on bus number 1
  tcaselect(1);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(10, 5);
  // display.setCursor(50, 5);
  // Display static text
  float cool_sys_pr=0.0;
  display.println(cool_sys_pr, 1);
  display.display(); 

  tcaselect(2);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(10, 5);
  // Display static text
  float steam_system_pr=0;
  display.println(steam_system_pr, 1);
  display.display(); 

  
  // Write to OLED on bus number 1
  tcaselect(3);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  // Display static text
  int steam_system_water_temp_1=25;
  display.println(steam_system_water_temp_1);
  display.display(); 

  tcaselect(4);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  // Display static text
  int steam_system_water_temp_2=25;
  display.println(steam_system_water_temp_2);
  display.display(); 

  
  // Write to OLED on bus number 1
  tcaselect(5);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  // Display static text
  int cool_sytem_temp_2=25;
  display.println(cool_sytem_temp_2);
  display.display(); 

  // Write to OLED on bus number 1
  tcaselect(6);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  // Display static text
  int cool_sytem_temp_2A=25;
  display.println(cool_sytem_temp_2);
  display.display(); 

  // Write to OLED on bus number 1
  tcaselect(7);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  // Display static text
  int cool_sytem_temp_2B=25;
  display.println(cool_sytem_temp_2);
  display.display(); 

}
int display_UP[8], DG1 = 0, DG2 = 0;
int AL_en[8];


void displayDG1_on(){
  tcaselect(0);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  if(DG1>99) display.setCursor(10, 5); else display.setCursor(30, 5);
  if(DG1<860 && display_[0]==4) DG1=DG1+50;
  else if(DG1>0 && display_[0]==8){DG1=DG1-50; if(DG1<200)Serial.println("STOP");} 
  display.println(DG1);
  display.display(); 

}

void displayDG2_on(){
  tcaselect(1);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  if(DG2>99) display.setCursor(10, 5); else display.setCursor(30, 5);
  if(DG2<860 && display_[1]==4) DG2=DG2+50;
  else if(DG2>0 && display_[1]==8){DG2=DG2-50; if(DG2<200)Serial.println("STOP");} 
  display.println(DG2);
  display.display(); 

}