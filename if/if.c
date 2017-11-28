#include <16f877a.h>
#fuses xt,nowdt
#use delay(clock=4000000)
int i = 1;


void main()
{
set_tris_b(0x00);
output_b(0);

for(;;)
{
   if(input(pin_a0)==1)
      {
      for(i=0;i<10;i++)
         {
         if(input(pin_a1)==1)
            {break;}
         output_b(i);
         delay_ms(300);
         }
      }
}
   
}


