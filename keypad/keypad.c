#include <16f877a.h>
#fuses xt,nowdt
#use delay(clock=4000000)
#include <lcd.c>

#define b0 pin_b0
#define b1 pin_b1
#define b2 pin_b2
#define b3 pin_b3

#define a0 pin_a0
#define a1 pin_a1
#define a2 pin_a2
#define a3 pin_a3
//b'ye gonderilecek ; a'dan alýnacak

int i=1;
int yazilan=0;
//14 /; 24 * ; 34 - ; 44 +; 43 =; 41 p; 
void yaz(char k)
{
      yazilan++;
      lcd_gotoxy(yazilan%17,(yazilan/17+1)%2);
      printf(lcd_putc,"%c",k);
      delay_ms(50);
}

void kontrol(int j)
{
   if(j==1)
   {
      if(input(a0))yaz("7");
      if(input(a1))yaz("8");
      if(input(a2))yaz("9");
      if(input(a3))yaz("/");
   }
   if(j==2)
   {
      if(input(a0))yaz("4");
      if(input(a1))yaz("5");
      if(input(a2))yaz("6");
      if(input(a3))yaz("*");
   }
   if(j==4)
   {
      if(input(a0))yaz("1");
      if(input(a1))yaz("2");
      if(input(a2))yaz("3");
      if(input(a3))yaz("-");
   }
   if(j==8)
   {
      if(input(a0))yaz("\f");
      if(input(a1))yaz("0");
      if(input(a2))yaz("=");
      if(input(a3))yaz("+");
   }
   
}

void main()
{
   set_tris_a(0x00);
   output_a(0);
   set_tris_b(0x00);
   output_b(0);
   lcd_init();
   
   for(;;)
   {
      output_b(i);
      kontrol(i);
      i*=2;
      if(i==16)i=1;
   }
}

//#define tus input_c();   //cdeki hangi pinlerde giris var bilgisini tanýmlar!!!!!!!!!!

