
#include <Arduino.h>

void uartinit();
void datasending(char data);
void setup()
{
uartinit();
}
void loop()
{
datasending('H');
}
void uartinit()
{

UCSR0B = 1 << 6 | 1 << 3 | 0 << 2; 
UCSR0C = 0 << UMSEL00 | 1 << UCSZ01 | 1 << UCSZ00 ;
UBRR0 = 103;
}

void datasending(char data)
{
UDR0 = data;
while (!( UCSR0A & 1 << 6));
}

ISR(USART_TX_vect)
{
}
