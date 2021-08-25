char read_menu_options[] =
{
  '1', 'a',
  '4', 'm', 'e', 'n', 'u',
  '1', 'c',
  '1', 'd',
  '4', 'e', 'x', 'i', 't',
  '3', 'f', 'e', 'd',
};

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
