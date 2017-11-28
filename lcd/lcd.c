#include <16f877a.h>
#fuses xt,nowdt
#use delay(clock=4000000)
#include <lcd.c>

long i;
int x;

#define button pin_b0

void main()
{
set_tris_a(0x00);
   output_a(0);
   set_tris_b(0x00);
   output_b(0);
   set_tris_c(0x00);
   output_c(0);
   set_tris_d(0x00);
   output_d(0);
   
   lcd_init(); 
   
   for(;;)
   {  
      i++;
      if(input(button)){x++; delay_ms(100);}
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Butona %d kez b...",x); 
   }
}

// aciklamalar

   //lcd_init();  lcd kuruldu
   // printf(lcd_putc,"\f"); lcd temizle (yazýlar ve imlecin yeri)
   //lcd_gotoxy(i%23-6,(i/23+1)%2);  //imlecin gidecegi adres: arka arkaya yazmasýn diye..
   //printf(lcd_putc,"deneme %ld",i  ); //lcd'ye veri gonderildi (lcd_putc kullanýlmazsa direkt seri porta veri gider)
   // degiskenden sonra yazý yazdýrmak icin printf(lcd_putc," deneme %ld asdf",i)
   // %ld long turunde oldugunu belirtir, %d int oldugunu belirtir. char > %c
   // delay_ms(20);
   //#define button pin_a0 pin button olarak tanýmlandý
   // #define use_portb_lcd TRUE: LCD' B portunu kullanýr
