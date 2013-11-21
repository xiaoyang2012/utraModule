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

//====SG DMA======
#include "altera_avalon_sgdma_regs.h"
#include "altera_avalon_sgdma.h"
#include "altera_avalon_sgdma_descriptor.h"
//====FIFO=====
#include "altera_avalon_fifo_regs.h"
#include "altera_avalon_fifo_util.h"
//====pio include===========
#include "altera_avalon_pio_regs.h"
//====uart include=============
#include "altera_avalon_uart_regs.h"
#include "altera_avalon_uart.h"

//====user interface============
#include "slave_template_macros.h"

static void initial(void);
static void usartInit(void);
static void dmaInit(void);
static void delayMs(alt_u32 msec);

//=======parameter=============
alt_sgdma_dev   *sgdma_rx_dev; //sgdma_rx设备文件
alt_sgdma_descriptor   *desc;       //descriptor memory指针

#define DISCRIPTOR_MEMORY_BASE 0x10033000
#define DMA_DESTINATION		0x00020000			//DDR3

#define AD_SEND_COUNT 200
//(1)先配置好sgdma_rx的基本配置，然后设置好sgdma_rx的回调函数。
//(2)配置ST_FIFO。
//（3）启动ST_FIFO完成dma发送。在这个过程中涵盖了sgdma_rx的基本使用


int main()
{
  alt_u8 ad_status = 0;
  initial();
  // LED
  IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE,0x01);
  // AD参数：发送次数
  IOWR_ALTERA_AVALON_PIO_DATA(AD_CNT_BASE,(alt_u16)AD_SEND_COUNT);

  while(1)
  {
	  IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE,0x02);
	  //start send data
	  IOWR_ALTERA_AVALON_PIO_DATA(AD_CTRL_BASE,0x01);
	  while(ad_status == 0x00)
	  {
		  delayMs(100);
		  ad_status = IORD_ALTERA_AVALON_PIO_DATA(AD_STATUS_BASE);
	  }
	  IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE,0x03);
	  //stop send data
	  IOWR_ALTERA_AVALON_PIO_DATA(AD_CTRL_BASE,0x00);
  }


  return 0;
}

static void initial(void)
{
	//===initial=======
	usartInit();
	dmaInit();
}

static void usartInit(void)
{

}

static void dmaInit(void)
{
	int dma_code=0;
	//重定义desc DISCRIPTOR_MEMORY_BASE定义在system.h中，即descriptor_memory的基地址
	desc= (alt_sgdma_descriptor*)DISCRIPTOR_MEMORY_BASE;

	//打开sgdma_rx
	sgdma_rx_dev= alt_avalon_sgdma_open(DMA_WRITE_NAME);
	if(!sgdma_rx_dev)
	     {
	        printf("[triple_speed_ethernet_init] Error opening SGDMA\n");
	        return;
	    }
	//==建立链表============
	//填充发送decriptor memory 并不需要自己填充，调用函数就好了。
	alt_avalon_sgdma_construct_stream_to_mem_desc(
		                       &desc[0],            //主描述字
		                       &desc[1],            //次描述字
		                       DMA_DESTINATION,
		                       0,				// 直到EOP
		                       0);

	   //启动sgdma_rx和sgdma_tx
	dma_code = alt_avalon_sgdma_do_async_transfer(sgdma_rx_dev,&desc[0]);

}


static void delayMs(alt_u32 msec)
{
	alt_32 i,t;
	for(i=0;i<msec;i++)
		for(t=0;t<0xffff;t++);
}

