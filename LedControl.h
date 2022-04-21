/*
   SERIAL DATA FORMAT
   
   DATA: 15-14-13-12-11-10-09-08-07-06-05-04-03-02-01-00
   
   D15 - D12: XX
   D11 - D08: ADDRESS
   D07 - D00: DATA
*/

/*
   INIT
   
   1) SHUTDOWN 
   2) DECODE
   3) INTENSITY
   4) SCAN LIMIT
   
   Solo hace falta el shutdown mode = 1 (prendido)
*/

///////////////////////////////////////////////////////////////////////////////REGISTER MAP
#define MAX7219_REG_NOOP         0x00
#define MAX7219_REG_DIGIT_0      0x01
#define MAX7219_REG_DIGIT_1      0x02
#define MAX7219_REG_DIGIT_2      0x03
#define MAX7219_REG_DIGIT_3      0x04
#define MAX7219_REG_DIGIT_4      0x05
#define MAX7219_REG_DIGIT_5      0x06
#define MAX7219_REG_DIGIT_6      0x07
#define MAX7219_REG_DIGIT_7      0x08
#define MAX7219_REG_DECODE       0x09
#define MAX7219_REG_INTENSITY    0x0A
#define MAX7219_REG_SCAN_LIMIT   0x0B
#define MAX7219_REG_SHUTDOWN     0x0C
#define MAX7219_REG_DISPLAY_TEST 0x0F

///////////////////////////////////////////////////////////////////////////////SHUTDOWN MODE
#define MAX7219_OFF              0x00
#define MAX7219_ON               0x01

///////////////////////////////////////////////////////////////////////////////DECODE MODE
#define MAX7219_DECODE_MODE_1    0x00
#define MAX7219_DECODE_MODE_2    0x01
#define MAX7219_DECODE_MODE_3    0x0F
#define MAX7219_DECODE_MODE_4    0xFF

///////////////////////////////////////////////////////////////////////////////INTENSITY MODE
#define MAX7219_INTENSITY_1      0x00
#define MAX7219_INTENSITY_2      0x01
#define MAX7219_INTENSITY_3      0x02
#define MAX7219_INTENSITY_4      0x03
#define MAX7219_INTENSITY_5      0x04
#define MAX7219_INTENSITY_6      0x05
#define MAX7219_INTENSITY_7      0x06
#define MAX7219_INTENSITY_8      0x07
#define MAX7219_INTENSITY_9      0x08
#define MAX7219_INTENSITY_10     0x09
#define MAX7219_INTENSITY_11     0x0A
#define MAX7219_INTENSITY_12     0x0B
#define MAX7219_INTENSITY_13     0x0C
#define MAX7219_INTENSITY_14     0x0D
#define MAX7219_INTENSITY_15     0x0E
#define MAX7219_INTENSITY_16     0x0F

///////////////////////////////////////////////////////////////////////////////LIMIT MODE
#define MAX7219_MAX_DIGITS_1     0x00
#define MAX7219_MAX_DIGITS_2     0x01
#define MAX7219_MAX_DIGITS_3     0x02
#define MAX7219_MAX_DIGITS_4     0x03
#define MAX7219_MAX_DIGITS_5     0x04
#define MAX7219_MAX_DIGITS_6     0x05
#define MAX7219_MAX_DIGITS_7     0x06
#define MAX7219_MAX_DIGITS_8     0x07

void send7219( unsigned int16 data = 0 )
{
   unsigned int i = 0;
   unsigned int MSB = 0;
   unsigned int LSB = 0;
   
   MSB = data >> 8;
   LSB = data & 0xFF;
   
   output_low( o_DATA );
   output_low( o_LOAD );
   output_low( o_CLK );
   
   for( i=0; i<8; i++ ){
      output_bit( o_DATA, ( MSB >> ( 7 - i ) ) & 0x01 );
      output_high( o_CLK );
      delay_us( 1 );
      output_low( o_CLK );
   }
   
   for( i=0; i<8; i++ ){
      output_bit( o_DATA, ( LSB >> ( 7 - i ) ) & 0x01 );
      output_high( o_CLK );
      delay_us( 1 );
      output_low( o_CLK );
   }
   
   output_high( o_DATA );
   output_high( o_LOAD );
   output_high( o_CLK );
}
