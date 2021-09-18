
void menu()
{

  if (cursor_position_on_display < 1) {
    cursor_position_on_display = 1;
    menu_scroll_offset = menu_scroll_offset - 1;
  }
  if (cursor_position_on_display > 4) {
    cursor_position_on_display = 4;
    menu_scroll_offset = menu_scroll_offset + 1;
  }



  //Serial.println(menu_selection_tracker);
  //Serial.println(find_EEPROM_endpoint());
  menu_selection_tracker = cursor_position_on_display + menu_scroll_offset;
  

  write_out_menu(main_menu_option_text, main_menu_start_read_positions, main_menu_options, menu_scroll_offset);
  write_cursor_to_screen(cursor_position_on_display, main_menu_options);

}