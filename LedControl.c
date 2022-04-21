void displayOFF( void )
{
   send7219( ( MAX7219_REG_SHUTDOWN << 8 ) | MAX7219_OFF );
}

void displayBCD( unsigned int16 digit = 0, unsigned int number = 0 )
{
   send7219( ( MAX7219_REG_SHUTDOWN << 8 ) | MAX7219_ON );
   
   send7219( ( MAX7219_REG_DECODE << 8 ) | MAX7219_DECODE_MODE_4 );
   
   send7219( ( MAX7219_REG_INTENSITY << 8 ) | MAX7219_INTENSITY_16 );
   
   send7219( ( MAX7219_REG_SCAN_LIMIT << 8 ) | MAX7219_MAX_DIGITS_8 );
   
   send7219( ( digit << 8 ) | number );
}

void display( unsigned int16 digit = 0, unsigned int number = 0 )
{   
   send7219( ( MAX7219_REG_SHUTDOWN << 8 ) | MAX7219_ON );
   
   send7219( ( MAX7219_REG_DECODE << 8 ) | MAX7219_DECODE_MODE_1 );
   
   send7219( ( MAX7219_REG_INTENSITY << 8 ) | MAX7219_INTENSITY_16 );
   
   send7219( ( MAX7219_REG_SCAN_LIMIT << 8 ) | MAX7219_MAX_DIGITS_8 );
   
   send7219( ( digit << 8 ) | number );
}
