#define beta_co_eff 3950
#define series_resistor_val 10 //Kohms
#define thermistor_nominal_val 10 //Kohms
#define nominal_at_temp 298.15 //Kelvin
#define thermistor_voltage 5 //volts

float read_tempreature(int i)
{
  float Vi = analogRead(i) * (5.0 / 1023.0);
  float R = (Vi * series_resistor_val) / (5 - Vi);
  float T =  1 / ((1 / nominal_at_temp) + ((log(R / thermistor_nominal_val)) / beta_co_eff));
  
  float Tc = T - 273.15; // Converting kelvin to celsius
  
  return Tc;
}
