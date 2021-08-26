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


void menu()
{
  int a = 0;
  int b=0;
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

  Serial.println(menu_selection_tracker);
  menu_selection_tracker = selected_menu_option + menu_scroll_offset;
  menu_scroll_offset_inv = ((menu_scroll_offset-1)*(-1))+1;




  
  n = 0;

read_out_menu();
read_out_cursor();

}
