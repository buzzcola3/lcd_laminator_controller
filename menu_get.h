



void get_menu_options_endpoint_distance(int menu_options, char menu_option_text[])
{
  int menu_options_lenght[menu_options];
  int i = 0;
  int a = 0;
  int n = 0;

  do
  {
    a = menu_option_text[i] - 47;
    
    main_menu_start_read_positions[n] = i;
    Serial.println(i);
    n = n + 1;
    i = i + a;
  }
  while (n != menu_options + 1);
  i = 0;
  a = 0;

do{


   a = (main_menu_start_read_positions[i + 1] - main_menu_start_read_positions[i]) - 1; //menu_options_lenght[];//0-5 -make
   Serial.println(a);
   menu_options_lenght[i] = a;
   i = i + 1;
  }while(i != main_menu_options);
}


void write_out_menu(char read_menu_options[], int menu_start_read_pos[], int g_menu_scroll_offset) //menu_options, read_menu_options
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

int menu_options=0 ;
do{menu_options++;} while (menu_start_read_pos[menu_options+1] > menu_start_read_pos[menu_options]);
Serial.print(menu_options);
Serial.println(":E");


 int g_menu_scroll_offset_inv = ((g_menu_scroll_offset) * (-1))-(4-menu_options);
  
 int a=1; int b=0; int c=0; int n=0;b=b+g_menu_scroll_offset;
 
  do
  {
     display.setCursor(8, c);
     c = c + 16;
     do{display.print(read_menu_options[menu_start_read_pos[b]+a]);
     a=a+1;
     
     }while(a!=(menu_start_read_pos[(b+1)])-(menu_start_read_pos[(b)]));display.println();a=1;b=b+1;


  }
  while (b-g_menu_scroll_offset < (menu_options-g_menu_scroll_offset)-g_menu_scroll_offset_inv);


}

void write_cursor_to_screen(int i, int menu_options)
{
  int c = 0;
  int e = 0;
  int r = 0;

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