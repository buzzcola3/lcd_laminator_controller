#include <EEPROM.h>

int find_EEPROM_endpoint()
{
int i=0;
char e=0;
int sanity=0;
//bool s=false;

do{
 do{
  e=EEPROM.read(i);
  i=i+4;
  
  if(e=='E'){break;};
  if(e=='n'){break;};
  if(e=='d'){break;};
  if(e=='%'){break;};
  
   }
  while(i<1024);
  //Serial.println("GO");

  if(i>1024){return 0;};
  
  do{i=i-1; sanity++; e=EEPROM.read(i);if(sanity>3){break;};}while(e!='E');
}
while(e!='E' && e+1!='n' && e+2!='d' && e+3!='%');

return i;


}

void find_EEPROM_variables()
{
  
}



void save_to_EEPROM(){}