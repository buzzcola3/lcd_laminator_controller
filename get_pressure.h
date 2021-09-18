
pr_avg_calc(int o) {

  pr_count = pr_count + 1;
  pr_avg = pr_avg + analogRead(A3);

  if (pr_count >= pr_smooth) {
    (pr_avg = pr_avg / pr_count);
    pr_count = 0;
    pr_final = (((pr_avg * 10) - 1030) / 8.41) ;
    pr_avg = 0;
  };

  pr_smooth = pr_smooth + 1;

  if (pr_smooth > 20) {
    pr_smooth = 20;
  };
  if ((pr_final - ((analogRead(A3) * 10) - 1030) / 8.41) >  5) {
    pr_smooth = pr_smooth - 4;
  };
  if ((pr_final - ((analogRead(A3) * 10) - 1030) / 8.41) < -5) {
    pr_smooth = pr_smooth - 4;
  };
  if (pr_smooth <= 0) {
    pr_smooth = 1 ;
  };

  return  pr_final / 10;
}