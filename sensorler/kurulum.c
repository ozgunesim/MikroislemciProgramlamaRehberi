void kurulum()
{
   set_tris_a(0x01); //denetleyici ucunda "AN" yazan kanallar analog okuyabilir.
                     //A portu giriþ portu olarak ayarlandý
   output_a(0);
   set_tris_b(0x00);
   output_b(0);
   set_tris_c(0x01);
   output_c(0);
   set_tris_d(0x00);
   output_d(0);
   lcd_init();
   setup_adc(adc_clock_div_2);   //analog okuma hýzý(onemli degil)
   setup_adc_ports(all_analog);  //tüm analoglarý oku
   
}
