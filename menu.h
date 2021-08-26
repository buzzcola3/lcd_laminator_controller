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



  Serial.println(menu_selection_tracker);
  menu_selection_tracker = cursor_position_on_display + menu_scroll_offset;
  menu_scroll_offset_inv = ((menu_scroll_offset - 1) * (-1)) + 1;

  read_out_menu();
  write_cursor_to_screen();

}
