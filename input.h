void press_detect() //D2-interrupt D7-transistor A7-analog value
{
  detachInterrupt(INT0);
  press_detected = true;
};

void button_input_leadout()
{
  Serial.println("leadout");
  attachInterrupt(INT0, press_detect, RISING);
  button_hold = false;
  button_hold_multiplier = 0;
  previous_button_action = '0';
};

void button_input_leadin()
{
  detachInterrupt(INT0);
  button_timer = millis();
  Serial.println("leadin");
  digitalWrite(7, HIGH);
  //Serial.println(analogRead(A7));
  if (analogRead(A7) > 1000) {
    button_action = '-';
  };
  if (analogRead(A7) < 850 && analogRead(A7) > 750) {
    button_action = 'K';
  };
  if (analogRead(A7) < 550 && analogRead(A7) > 450) {
    button_action = '+';
  };

  Serial.println(button_action);
  digitalWrite(7, LOW);
  // Serial.println(button_action);
  press_detected = false;
  button_hold = true;
  attachInterrupt(INT0, button_input_leadout, FALLING);
};

recheck_hold()
{
  //char ch='0';
  digitalWrite(7, HIGH);
  if (analogRead(A7) > 1000) {
    button_action = '-';
  };
  if (analogRead(A7) < 850 && analogRead(A7) > 750) {
    button_action = 'K';
  };
  if (analogRead(A7) < 550 && analogRead(A7) > 450) {
    button_action = '+';
  };
  digitalWrite(7, LOW);
  //Serial.print("ch:");

  if (previous_button_action != button_action) {
    previous_button_action = button_action;
    button_hold_multiplier = 0; ;
  };

};

hold_count()//if(button_hold == true) button_hold_multiplier_timer
{
  //Serial.println(millis()-button_timer);
  //<1000 +1
  if (millis() - button_timer >= 350)
  {
    //Serial.println("AYAYA");
    if (millis() - button_hold_multiplier_timer >= 450)
    {
      //Serial.println("WTF");
      button_hold_multiplier_timer = millis();
      if (button_hold_multiplier < 4) {
        button_hold_multiplier = button_hold_multiplier + 1;
      }
      recheck_hold();
    }
  };
};

void input_check_handler()
{
  if (button_hold == true && button_hold_multiplier == 0 && button_action == '+')
  { if (open_menu == false) {
      temp = temp + 1;
      previous_button_action = button_action;
      button_action = '0';
    }
    if (open_menu == true && menu_selection_tracker < main_menu_options) {
      cursor_position_on_display = cursor_position_on_display + 1;
      previous_button_action = button_action;
      button_action = '0';
    };
  }

  if (button_hold == true && button_hold_multiplier == 0 && button_action == '-')
  { if (open_menu == false) {
      temp = temp - 1;
      previous_button_action = button_action;
      button_action = '0';
    }
    if (open_menu == true && menu_selection_tracker > 1) {
      cursor_position_on_display = cursor_position_on_display - 1;
      previous_button_action = button_action;
      button_action = '0';
    };
  }

  if (button_hold == true && button_hold_multiplier == 0 && button_action == 'K')
  { if (open_menu == false && millis() - button_timer >= 600) {
      cursor_position_on_display = 1;
      menu_selection_tracker = 1;
      menu_scroll_offset = 0;
      button_action = '0';
      open_menu = true;
      button_timer = millis();
      
     
    }
    if (open_menu == true && button_action == 'K' && menu_selection_tracker == menu_exit) {
      open_menu = false;
      previous_button_action = button_action;
      button_action = '0';
    };
  }

  if (millis() - value_add_timer >= (200 - button_hold_multiplier * 40))
  {
    if (button_hold == true && button_hold_multiplier != 0 && previous_button_action == '+') {
      temp = temp + 1;
    }
    if (button_hold == true && button_hold_multiplier != 0 && previous_button_action == '-') {
      temp = temp - 1;
    }
    value_add_timer = millis();

  };
}