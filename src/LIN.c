#include <string.h>
#include "HAL.h"

void LIN_send_frame(char sid, char* data, int size)
{
  char buf[11];

  if( size > (sizeof(buf) - 3) ) size = sizeof(buf) - 3;

  buf[0] = 0x55;
  buf[1] = sid;
  memcpy(buf, data, size);
  UART_send(buf, sizeof(buf));
}