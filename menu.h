void  menu_button()
{
  if (open_menu == true && button_hold == true && button_hold_multiplier == 0 && button_action == '+' && menu_selection_tracker < menu_options) {
    selected_menu_option = selected_menu_option + 1;
    previous_button_action = button_action;
    button_action = '0';
  };
  if (open_menu == true && button_hold == true && button_hold_multiplier == 0 && button_action == '-' && menu_selection_tracker > 1 ) {
    selected_menu_option = selected_menu_option - 1;
    previous_button_action = button_action;
    button_action = '0';
  };

  if (open_menu == true && button_hold == true && button_hold_multiplier == 0 && button_action == 'K' && menu_selection_tracker == 6 ) {
    open_menu = false;
    testdrawstyles();
    previous_button_action = button_action;
    button_action = '0';
  };
}


void menu(int i)
{
  int a = 0;
  int b=0;
  int d = 0;
  int c = 0;
  int e = 0;
  int r = 0;
  int n = 0;

  if (selected_menu_option < 1) {
    selected_menu_option = 1;
    menu_scroll_offset = menu_scroll_offset - 1;
  }
  if (selected_menu_option > 4) {
    selected_menu_option = 4;
    menu_scroll_offset = menu_scroll_offset + 1;
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  // Serial.println(menu_start_read_pos[0]);
  // Serial.println(menu_start_read_pos[1]);
  // Serial.println(menu_start_read_pos[2]);
  // Serial.println(menu_start_read_pos[3]);
  // Serial.println(menu_start_read_pos[4]);
  //Serial.println(menu_start_read_pos[5]);
  //Serial.println(menu_start_read_pos[6]);

  Serial.println(menu_selection_tracker);
  menu_selection_tracker = selected_menu_option + menu_scroll_offset;
  menu_scroll_offset_inv = ((menu_scroll_offset-1)*(-1))+1;

n=0;
b=0;
b=b+menu_scroll_offset;
a=1;
  do //6x
  {
     display.setCursor(8, c);
     c = c + 16;
     do{display.print(read_menu_options[menu_start_read_pos[b]+a]); Serial.print(read_menu_options[menu_start_read_pos[b]+a]); a=a+1;//}
     }while(a!=menu_options_lenght[b]+1);display.println();a=1;b=b+1; Serial.println();
  }
  while (b-menu_scroll_offset < (menu_options-menu_scroll_offset)-menu_scroll_offset_inv);


Serial.println(b);
Serial.println(menu_scroll_offset);


   
//    Serial.print(read_menu_options[menu_start_read_pos[4]+a]); a=a+1;//}
 //   Serial.print(read_menu_options[menu_start_read_pos[4]+a]); a=a+1;//}
  //  Serial.print(read_menu_options[menu_start_read_pos[4]+a]); a=a+1;//}
   // Serial.print(read_menu_options[menu_start_read_pos[4]+a]); a=a+1;//}

  
  n = 0;
  c = 0;
  e = 0;
  r = 0;

  do {
    r = r + 1;
    display.setCursor(-6, c);
    if (i == r) {
      display.println('>');
    } else(display.println(' '));
    c = c + 16;
    e = e + 1;
  }
  while (e < menu_options);
  r = 0;
  display.display();
}
