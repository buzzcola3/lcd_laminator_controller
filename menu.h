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



  Serial.println(menu_selection_tracker);
  menu_selection_tracker = selected_menu_option + menu_scroll_offset;
  menu_scroll_offset_inv = ((menu_scroll_offset - 1) * (-1)) + 1;

  read_out_menu();
  write_cursor_to_screen();

}
