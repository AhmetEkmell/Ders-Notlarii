#include <adc_modul.h>
#include <lcd.c>
void main()
{
   int16 x_data, y_data, xxData, yyData;
   lcd_init();
   setup_adc(ADC_CLOCK_DIV_2); // Focs/2 ayarland�.
   //setup_adc_ports(AN0_AN1_AN2_AN4_AN5_VSS_VREF);
   setup_adc_ports(ALL_ANALOG); // T�m 8 kanal analog input durmunda
   set_adc_channel(5); // AN5 - RE0 - JOYSTICK Y EKSEN� AKT�F
   
   
   while(TRUE)
   {
      setup_adc_ports(ALL_ANALOG);
      set_adc_channel(5);  // AN5 - RE0 - joystick y ekseni aktif
      y_data = read_adc();
      delay_ms(1);
      set_adc_channel(6);  // AN6 - RE1 - joystick x ekseni aktif
      x_data = read_adc();
      delay_ms(1);
      
      // sol �st ve sa� �st �apraz da 1023 de�erini g�rmek i�in a�a��daki kodlama yap�ld�.
      if(x_data == 512 ) xxData = 0;
      if(y_data == 512 ) yyData = 0;
      if(x_data >  512 ) xxData = (x_data-512)*2+1;
      if(y_data >  512 ) yyData = (y_data-512)*2+1;
      if(x_data <  512 ) xxData = (511-x_data)*2+1;
      if(y_data <  512 ) xxData = (511-y_data)*2+1;
      
      setup_adc_ports(NO_ANALOGS);
      printf(lcd_putc,"\f  ( x  ,  y )  \n  %04Lu , %04Lu",x_data,y_data);
      delay_ms(30);
   }

}
