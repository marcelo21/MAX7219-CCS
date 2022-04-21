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

void displayCharacters( unsigned int16 digit = 0, char data = 0, int1 dt = 0 )
{
   unsigned int char7seg;
   
   char7seg = 0;
   switch( data ){
      case '0':
         char7seg = 0x7E;
         break;
         
      case '1':
         char7seg = 0x30;
         break;
         
      case '2':
         char7seg = 0x6D;
         break;
         
      case '3':
         char7seg = 0x79;
         break;
         
      case '4':
         char7seg = 0x33;
         break;
         
      case '5':
         char7seg = 0x5B;
         break;
         
      case '6':
         char7seg = 0x5F;
         break;
         
      case '7':
         char7seg = 0x70;
         break;
         
      case '8':
         char7seg = 0x7F;
         break;
         
      case '9':
         char7seg = 0x7B;
         break;
         
      case 'A':
         char7seg = 0x77;
         break;
         
      case 'B':
         char7seg = 0x1F;
         break;
         
      case 'C':
         char7seg = 0x4E;
         break;
         
      case 'D':
         char7seg = 0x3D;
         break;
         
      case 'E':
         char7seg = 0x4F;
         break;
         
      case 'F':
         char7seg = 0x47;
         break;
         
      case 'G':
         char7seg = 0x5E;
         break;
         
      case 'H':
         char7seg = 0x37;
         break;
         
      case 'J':
         char7seg = 0x3C;
         break;
         
      case 'L':
         char7seg = 0x0E;
         break;
         
      case 'N':
         char7seg = 0x76;
         break;
         
      case 'O':
         char7seg = 0x1D;
         break;
         
      case 'P':
         char7seg = 0x67;
         break;
         
      case 'R':
         char7seg = 0x05;
         break;
         
      case 'S':
         char7seg = 0x5B;
         break;
         
      case 'T':
         char7seg = 0x0F;
         break;
         
      case '-':
         char7seg = 0x01;
         break;
         
      default:
         char7seg = 0x00;
         break;
   }
   
   send7219( ( MAX7219_REG_SHUTDOWN << 8 )   | MAX7219_ON );   
   send7219( ( MAX7219_REG_DECODE << 8 )     | MAX7219_DECODE_MODE_1 );   
   send7219( ( MAX7219_REG_INTENSITY << 8 )  | MAX7219_INTENSITY_1 );   
   send7219( ( MAX7219_REG_SCAN_LIMIT << 8 ) | MAX7219_MAX_DIGITS_8 );
   
   if( dt == true ){ send7219( ( digit << 8 ) | char7seg | ( 1 << 7 ) ); }
   else{ send7219( ( digit << 8 ) | char7seg ); }
}

void display( unsigned int16 digit = 0, unsigned int number = 0 )
{   
   send7219( ( MAX7219_REG_SHUTDOWN << 8 ) | MAX7219_ON );
   
   send7219( ( MAX7219_REG_DECODE << 8 ) | MAX7219_DECODE_MODE_1 );
   
   send7219( ( MAX7219_REG_INTENSITY << 8 ) | MAX7219_INTENSITY_16 );
   
   send7219( ( MAX7219_REG_SCAN_LIMIT << 8 ) | MAX7219_MAX_DIGITS_8 );
   
   send7219( ( digit << 8 ) | number );
}
