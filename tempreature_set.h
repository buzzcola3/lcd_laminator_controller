void temp_set()
  {
    if (button_hold == true && button_hold_multiplier == 0 && button_action == '+'){temp = temp+1; previous_button_action=button_action; button_action='0';}
    if (button_hold == true && button_hold_multiplier == 0 && button_action == '-'){temp = temp-1; previous_button_action=button_action; button_action='0';}

    if (millis()-value_add_timer>=(200-button_hold_multiplier*40))
    {
      if (button_hold == true && button_hold_multiplier != 0 && previous_button_action == '+'){temp = temp+1;} 
      if (button_hold == true && button_hold_multiplier != 0 && previous_button_action == '-'){temp = temp-1;}
      value_add_timer = millis();
    };
  }
