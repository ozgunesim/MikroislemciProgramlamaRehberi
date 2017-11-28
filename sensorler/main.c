#include <16f877a.h>
#fuses xt,nowdt
#use delay(clock=4000000)

#include <lcd.c>
#include <kurulum.c>

long sicaklik;

void main()
{
   kurulum();
   
   for(;;)
   {
   
      set_adc_channel(0);//hangi a portundan okuma yapýlacak ?
      delay_ms(10);
      sicaklik = read_adc();
      sicaklik *= 2;
      delay_ms(50);
      if(sicaklik>25 || input(pin_c0))output_b(1);
      else if(sicaklik<20 || input(pin_c1))output_b(2);
      else output_b(0);
      printf(lcd_putc,"\f Sicaklik = %ld C",sicaklik);   //%02.2f float icin virgulden once ve sonraki basamak sayýlarý girilir
      delay_ms(250);
   }
   
}
