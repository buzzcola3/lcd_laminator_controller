void get_menu_options_endpoints()
{

  int c = 0;
  int e = 0;
  int n = 0;

  menu_start_read_pos[n] = e;
  n = n + 1;
  Serial.println(e);

  c = read_menu_options[0] - 47;
  e = e + c; //5
  menu_start_read_pos[n] = e;
  n = n + 1;
  Serial.println(e);

  do
  {
    c = read_menu_options[e] - 47;
    e = e + c;
    menu_start_read_pos[n] = e;
    n = n + 1;
    Serial.println(e);
  }
  while (n != menu_options + 1);
}

void get_menu_options_endpoint_distance()
{
  int i = 0;
  int a = 0;

do{
   a = (menu_start_read_pos[i + 1] - menu_start_read_pos[i]) - 1; //menu_options_lenght[];//0-5 -make
   Serial.println(a);
   menu_options_lenght[i] = a;
   i = i + 1;
  }while(i != menu_options);
}


void read_out_menu()
{
 int a=1; int b=0; int c=0; int n=0;b=b+menu_scroll_offset;
  do
  {
     display.setCursor(8, c);
     c = c + 16;
     do{display.print(read_menu_options[menu_start_read_pos[b]+a]); a=a+1;//}
     }while(a!=menu_options_lenght[b]+1);display.println();a=1;b=b+1;
  }
  while (b-menu_scroll_offset < (menu_options-menu_scroll_offset)-menu_scroll_offset_inv);
}

void write_cursor_to_screen()
{
  int c = 0;
  int e = 0;
  int r = 0;
  int i = selected_menu_option;

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
