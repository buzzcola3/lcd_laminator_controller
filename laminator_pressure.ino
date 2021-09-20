#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//#include <string.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define rps 30 //display and pressure refreshes per second


#define menu_exit 7
char main_menu_option_text[] =
{
  '2', 'o', 'n',
  '4', 'd', 'e', 'e', 'z',
  '2', 'o', 'n',
  '4', 'n', 'u', 't', 'z',
  '2', 'o', 'n',
  '1', 'u',
  '4', 'e', 'x', 'i', 't',
};

#define tempreature_submenu_exit 4
char read_tempreature_submenu_options[] =
{
  '3', 'b', 'e', 't','a',
  '2', 'e', 'n',
  '4', 'd', 'e', 'e', 'n',
  '4', 'p', 'u', 'e', 'r',
};

unsigned long pr_timer;
int pr_count;
int pr_value;
long int pr_avg;
int pr_final;
int pr_smooth;

bool press_detected;
char button_action;
char previous_button_action;
unsigned long button_timer;
bool button_hold;
int button_hold_multiplier;
unsigned long button_hold_multiplier_timer = 0;

int temp;
int cur_temp;
unsigned long value_add_timer;

bool open_menu;
int cursor_position_on_display;
int menu_scroll_offset;
int menu_selection_tracker;
int display_update_tracker;

int main_menu_start_read_positions[main_menu_options+1];


#include "EEPROM_managment.h"
#include "get_pressure.h"
#include "get_tempreature.h"
//#include "input.h"
#include "homescreen.h"
#include "PID.h"
#include "menu_get.h"
#include "menu.h"
#include "input_simulator.h"

void setup() {
simulator();

  Serial.begin(9600);
  pinMode(A3, INPUT);

  pinMode(A7, INPUT);
  pinMode(7, OUTPUT);
  pinMode(2, INPUT);
  attachInterrupt(INT0, press_detect, RISING);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.invertDisplay(false);
  delay(100);
  pr_value = analogRead(A3);
  pr_count = 0;
  pr_avg = 0;
  pr_smooth = 10;

  press_detected = false;
  button_hold = false;
  button_hold_multiplier = 0;
  button_hold_multiplier_timer = 0;

  temp = 0; //read from eeprom
  cur_temp = 0; //read

  open_menu = false;
  cursor_position_on_display = 1;
  menu_scroll_offset = 0;
  menu_selection_tracker = 0;
  display_update_tracker = 0;




  get_menu_options_endpoint_distance(main_menu_options, main_menu_option_text);

  Serial.println(find_EEPROM_endpoint());
}

void loop() {
  if (millis() - pr_timer >= (1000 / (rps * 1000)))
  {
    if (open_menu == false) {
      display_homescreen();
    } else(menu());
    input_check_handler();
    //Serial.println(menu_selection_tracker);
    //Serial.print("open_menu:");
    //Serial.println(open_menu);
  }



  if (press_detected == true) {
    button_input_leadin();
  }
  if (button_hold == true) {
    hold_count();
  }

  input_check_handler();

  PID();
}