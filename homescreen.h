void display_homescreen(void)
{
  display.clearDisplay();

  display.setTextSize(4);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0, 0);            // Start at top-left corner
  display.print(pr_avg_calc(1));
  display.setTextSize(2);
  display.print("kPa");
  display.setTextSize(4);
  display.println("");

  display.setTextSize(1);
  //display.println(pr_smooth);
  display.print(temp); display.println("C");
  display.println(previous_button_action);
  if (button_hold == true) {
    display.println(millis() - button_timer);
  } else (display.println("0"));
  display.display();
  pr_timer = millis();
}
