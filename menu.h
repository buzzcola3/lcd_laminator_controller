void menu()
{

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
  menu_scroll_offset_inv = ((menu_scroll_offset - 1) * (-1)) + 1;

  read_out_menu();
  read_out_cursor();

}
