/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include <alt_types.h>
#include <io.h>
#include <system.h>
#include <string.h>

#include "sys/alt_dma.h"
#include "system.h"
#include "sys/alt_flash.h"
#include "sys/alt_flash_dev.h"
#include <altera_avalon_pio_regs.h>

#include <altera_avalon_uart_regs.h>

#define TEST_MEMORY_BASE  0x00001000
#define TEST_MEMORY_END   0x01010101
#define TEST_MEMORY_LEN   1024

/******************************************************************
*  Function: MemTest8bit
*
*  Á¬ÐøµØÖ·£¬8bit¶ÁÐ´¼ì²â
*
*
******************************************************************/
static int MemTest8bit(unsigned long memory_base,unsigned long nBytes)
{
	unsigned long byte_cnt = 0;
	unsigned int pattern     = 0xAA;
	unsigned int antipattern  = 0x55;
	unsigned int rd_data;
	unsigned long ret_code = 0x0;


	for(byte_cnt = 0;byte_cnt<nBytes;byte_cnt++)
	{
		IOWR_8DIRECT(memory_base, byte_cnt, pattern);
		rd_data = IORD_8DIRECT(memory_base, byte_cnt);
		if(rd_data != pattern)
		{
			ret_code = memory_base + byte_cnt;
			break;
		}
		IOWR_8DIRECT(memory_base, byte_cnt, antipattern);
		rd_data = IORD_8DIRECT(memory_base, byte_cnt);
		if(rd_data != antipattern)
		{
			ret_code = memory_base + byte_cnt;
			break;
		}

	}

	return ret_code;


}


/******************************************************************
*  Function: MemTestAddressBus
*
*  Purpose: Tests that the address bus is connected with no
*           stuck-at's, shorts, or open circuits.
*
******************************************************************/
static int MemTestAddressBus(unsigned int memory_base, unsigned int nBytes)
{
  unsigned int address_mask = (nBytes - 1);
  unsigned int offset;
  unsigned int test_offset;

  unsigned int pattern     = 0xAAAAAAAA;
  unsigned int antipattern  = 0x55555555;

  unsigned int ret_code = 0x0;

  /* Write the default pattern at each of the power-of-two offsets. */
  for (offset = sizeof(unsigned int); (offset & address_mask) != 0; offset <<= 1)
  {
    IOWR_32DIRECT(memory_base, offset, pattern);
  }

  /* Check for address bits stuck high. */
  test_offset = 0;
  IOWR_32DIRECT(memory_base, test_offset, antipattern);
  for (offset = sizeof(unsigned int); (offset & address_mask) != 0; offset <<= 1)
  {
     if (IORD_32DIRECT(memory_base, offset) != pattern)
     {
        ret_code = (memory_base+offset);
        break;
     }
  }

  /* Check for address bits stuck low or shorted. */
  IOWR_32DIRECT(memory_base, test_offset, pattern);
  for (test_offset = sizeof(unsigned int); (test_offset & address_mask) != 0; test_offset <<= 1)
  {
    if (!ret_code)
    {
      IOWR_32DIRECT(memory_base, test_offset, antipattern);
      for (offset = sizeof(unsigned int); (offset & address_mask) != 0; offset <<= 1)
      {
        if ((IORD_32DIRECT(memory_base, offset) != pattern) && (offset != test_offset))
        {
          ret_code = (memory_base + test_offset);
          break;
        }
      }
      IOWR_32DIRECT(memory_base, test_offset, pattern);
    }
  }

  return ret_code;
}


void delayMs(alt_u16 count)
{
	alt_u16 i,k;
	for(k=0;k<count;k++)
		for(i=0;i<0xffff;i++);
}

void uart_send_byte(alt_u8 data)
{
	alt_u16 status;

	do{
	status = IORD_ALTERA_AVALON_UART_STATUS(UART_0_BASE);
	}while(!(status&0x0040));

	IOWR_ALTERA_AVALON_UART_TXDATA(UART_0_BASE,data);
}

int main()
{
/*
  unsigned long ret_code = 0;
  unsigned long test_len;
  printf("Hello from Nios II!\n");
  test_len = TEST_MEMORY_END - TEST_MEMORY_BASE - 1;
  //MEMORY TEST
  ret_code = MemTest8bit(TEST_MEMORY_BASE, test_len);
  //MemTestAddressBus(TEST_MEMORY_BASE, TEST_MEMORY_LEN);

  if(ret_code == 0)
	  IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE,0x01);
  else
	  IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE,0x02);
*/
	//´®¿Ú²âÊÔ
	alt_u8 i;
	for(i=0;i<255;i++)
		uart_send_byte(i);



  return 0;
}
