/*
module name:top.v

*/

module top(
//system
CLK_IN,
RST_IN,

//LTC2151
// 7 lvds DATA INPUT 
ADC_D0,
ADC_D1,
ADC_D2,
ADC_D3,
ADC_D4,
ADC_D5,
ADC_D6,

ADC_CLKO,		// lvds clk
ADC_OF,			

ADC_ENC,		
ADC_nCS,
ADC_SCK,
ADC_SDI,
ADC_SDO,
ADC_PnS,

//AVG control
AGV_DATA,
AGV_CLK,
AGV_LTCH,

//DDR3 control
DRAM_DATA,
DRAM_ADDR,
DRAM_BA,
DRAM_CLK,
DRAM_DQS0,
DRAM_DQS1,
DRAM_DQM,

DRAM_nCS0,
DRAM_nRST,
DRAM_CKE,
DRAM_nRAS,
DRAM_nCAS,
DRAM_nWE,
DRAM_ODT,

FECH,		// 0-8 
ARxSEL_nEN2,
ARxSEL_EN1,
ARXSEL_EN0,
ARxSEL,		//SEL0-2 
SYNC_DIN,
SYNC_DOUT,

//SPI & UART
SPI1_SCK,
SPI1_MOSI,
SPI1_MISO,
SPI1_NSS,

SPI2_SCK,
SPI2_MOSI,
SPI2_MISO,
SPI2_NSS,

UART_TX,
UART_RX,
UART_CK,

//SD卡
SD_SCK,
SD_MOSI,
SD_CS,
SD_DETECT,
SD_MISO,
SD_WP,

//MCU_PIO
MCU_PIO,		// 0-6 
//led
LED

);

//=============PORT============================
input CLK_IN;
input RST_IN;

input ADC_D0;
input ADC_D1;
input ADC_D2;
input ADC_D3;
input ADC_D4;
input ADC_D5;
input ADC_D6;

input ADC_CLKO;		
input ADC_OF;			

output ADC_ENC;		
output ADC_nCS;
output ADC_SCK;
output ADC_SDI;
input ADC_SDO;
output ADC_PnS;

output AGV_DATA;
output AGV_CLK;
output AGV_LTCH;

inout [15:0]DRAM_DATA;
output [15:0]DRAM_ADDR;
output [2:0]DRAM_BA;
output DRAM_CLK;
input DRAM_DQS0;
input DRAM_DQS1;
output [1:0]DRAM_DQM;

output DRAM_nCS0;
output DRAM_nRST;
output DRAM_CKE;
output DRAM_nRAS;
output DRAM_nCAS;
output DRAM_nWE;
output DRAM_ODT;

output [8:0]FECH;		
output ARxSEL_nEN2;
output ARxSEL_EN1;
output ARXSEL_EN0;
output [2:0]ARxSEL;		
input SYNC_DIN;
output SYNC_DOUT;

//SPI & UART
input SPI1_SCK;
input SPI1_MOSI;
output SPI1_MISO;
input SPI1_NSS;

input SPI2_SCK;
input SPI2_MOSI;
output SPI2_MISO;
input SPI2_NSS;

output UART_TX;
input UART_RX;
input UART_CK;

output SD_SCK;
output SD_MOSI;
output SD_CS;
input SD_DETECT;
input SD_MISO;
output SD_WP;

//MCU_PIO
input [6:0]MCU_PIO;		
//led
output [3:0]LED;




endmodule