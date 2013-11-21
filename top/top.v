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
DRAM_ADDR,
DRAM_BA,
DRAM_CK,
DRAM_CK_n,
DRAM_CKE,
DRAM_nCS,
DRAM_DQM,
DRAM_nRAS,
DRAM_nCAS,
DRAM_nWE,
DRAM_nRST,
DRAM_DATA,
DRAM_DQS,
DRAM_DQS_n,
DRAM_ODT,

RZQ_IN,

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

//SD鍗
SD_SCK,
SD_MOSI,
SD_CS,
SD_DETECT,
SD_MISO,
SD_WP,

//MCU_PIO
MCU_PIO,		// 0-6 

//===测试用======
//uart
TEST_TX,
TEST_RX,
//led
LED

);

//=============PORT============================
input CLK_IN;
input RST_IN;
input ADC_CLKO;
input ADC_D0;
input ADC_D1;
input ADC_D2;
input ADC_D3;
input ADC_D4;
input ADC_D5;
input ADC_D6;

		
	

output ADC_ENC;		
output ADC_nCS;
output ADC_SCK;
output ADC_SDI;
input ADC_SDO;
output ADC_PnS;

output AGV_DATA;
output AGV_CLK;
output AGV_LTCH;


output [13:0]DRAM_ADDR;
output [2:0]DRAM_BA;
output DRAM_CK;
output DRAM_CK_n;
output DRAM_CKE;
output DRAM_nCS;
output [1:0]DRAM_DQM;
output DRAM_nRAS;
output DRAM_nCAS;
output DRAM_nRST;
output DRAM_nWE;
output DRAM_ODT;
inout [15:0]DRAM_DATA;
inout [1:0]DRAM_DQS;
inout [1:0]DRAM_DQS_n;

input RZQ_IN;

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

input TEST_RX;
output TEST_TX;	
//led
output [3:0]LED;


//=============wire & reg===========================
// CLK
wire clk;			//GCLK
wire clk_200m;		//GCLK
wire pll4_outclk;
//RST
wire rst = 1'b0;
wire rst_n = !rst;


//DMAWRITE TO DDR3
wire        dma_in_sop;                //             dma.startofpacket
wire        dma_in_eop;                   //                .endofpacket
wire [1:0]  dma_in_empty;                         //                .empty
wire [31:0] dma_in_data;                          //                .data
wire        dma_in_valid;                         //                .valid
wire        dma_in_ready;                         //                .ready

//DMAREAD FROM DDR3
wire        dma_out_sop;                //             dma.startofpacket
wire        dma_out_eop;                   //                .endofpacket
wire [1:0]  dma_out_empty;                         //                .empty
wire [31:0] dma_out_data;                          //                .data
wire        dma_out_valid;                         //                .valid
wire        dma_out_ready;                         //                .ready

wire [7:0]ad_ctrl;
wire [15:0]ad_cnt;
wire [3:0]ad_status;

//ddr3
wire loc_cal_fail;
wire loc_init_done;
wire loc_cal_success;
//===============code============================
/*
1,CLK 时钟域设置
（1）输入CLK_IN,50MHZ，直接输入到GCLK网络上
（2）输入CLK_IN,进入PLL，输出AD高频时钟CLK_ENC,进入RCLK网络
（3）使用DDIO IP CORE，作为AD数据接收端
*/
//1 GCLK
GCLK_CTRL U0(
	.inclk(CLK_IN),
	.outclk(clk));
//2 RCLK
PLL4 U1(
		.refclk(clk),   //  refclk.clk
		.rst(rst),      //   reset.reset
		.outclk_0(pll4_outclk), // outclk0.clk
		.locked()    //  locked.export
	);
GCLK_CTRL U2(
	.inclk(pll4_outclk),
	.outclk(clk_200m));
/*
2,RST 复位信号设置
使用全局时钟网络
*/
//GCLK_CTRL U2(
//	.inclk(RST_IN),
//	.outclk(rst));
	
/*
3,adControl  
*/
assign ADC_ENC = clk_200m;
adControl U3(
//===system====
.clk(clk_200m),
.rst(rst),
// 7 lvds DATA INPUT 
.ADC_D0(ADC_D0),
.ADC_D1(ADC_D1),
.ADC_D2(ADC_D2),
.ADC_D3(ADC_D3),
.ADC_D4(ADC_D4),
.ADC_D5(ADC_D5),
.ADC_D6(ADC_D6),

.ADC_CLKO(ADC_CLKO),		// lvds clk		

.ADC_nCS(ADC_nCS),
.ADC_SCK(ADC_SCK),
.ADC_SDI(ADC_SDI),
.ADC_SDO(ADC_SDO),
.ADC_PnS(ADC_PnS),

//AVG control
.AGV_DATA(AGV_DATA),
.AGV_CLK(AGV_CLK),
.AGV_LTCH(AGV_LTCH),

//data flaw
.dout(),
.doutEn()
);

/*
4,kernel

*/
kernel MCU(
		//======system==============
		.clk_clk(clk),                           //             clk.clk
		.c200_clk(clk_200m),
		.reset_reset_n(rst_n),                     //           reset.reset_n
		.r200_reset_n(rst_n),
		
		.mcu_pio_export(MCU_PIO),
		.led_ctrl_export(LED),                   //        led_ctrl.export
		
		//====UART&SPI===========
		.test_uart_rxd(SD_MISO),                     //       uart_port.rxd
		.test_uart_txd(SD_MOSI),                     //                .txd
		.usart1_rxd(UART_RX),
		.usart1_txd(UART_TX),
		.spi1_MISO(SPI1_MISO),
		.spi1_MOSI(SPI1_MOSI),
		.spi1_SCLK(SPI1_SCK),
		.spi1_SS_n(SPI1_NSS),
		.spi2_MISO(SPI2_MISO),
		.spi2_MOSI(SPI2_MOSI),
		.spi2_SCLK(SPI2_SCK),
		.spi2_SS_n(SPI2_NSS),
		
		//==PIO:AD PROCESS====
		.ad_ctrl_export(ad_ctrl),
		.ad_cnt_export(ad_cnt),
		.ad_status_export(ad_status),
		
		
		//====DMAWRITE avalon-st SINK=====
		.dma_in_startofpacket(dma_in_sop),
		.dma_in_endofpacket(dma_in_eop),
		.dma_in_empty(dma_in_empty),
		.dma_in_data(dma_in_data),
		.dma_in_valid(dma_in_valid),
		.dma_in_ready(dma_in_ready),
		//=====DMAWRITE avalon-st SOURCE======
		.dma_out_startofpacket(dma_out_sop),
		.dma_out_endofpacket(dma_out_eop),
		.dma_out_empty(dma_out_empty),
		.dma_out_data(dma_out_data),
		.dma_out_valid(dma_out_valid),
		.dma_out_ready(dma_out_ready),
		
		//===DDR3==============
		.oct_rzqin(RZQ_IN),                         //             oct.rzqin
		.ddr3_mem_status_local_init_done(loc_init_done),   // ddr3_mem_status.local_init_done
		.ddr3_mem_status_local_cal_success(loc_cal_success), //                .local_cal_success
		.ddr3_mem_status_local_cal_fail(loc_cal_fail),    //                .local_cal_fail
		//======DDR3 MEM interface==========
		.memory_mem_a(DRAM_ADDR),                      //          memory.mem_a
		.memory_mem_ba(DRAM_BA),                     //                .mem_ba
		.memory_mem_ck(DRAM_CK),                     //                .mem_ck
		.memory_mem_ck_n(DRAM_CK_n),                   //                .mem_ck_n
		.memory_mem_cke(DRAM_CKE),                    //                .mem_cke
		.memory_mem_cs_n(DRAM_nCS),                   //                .mem_cs_n
		.memory_mem_dm(DRAM_DQM),                     //                .mem_dm
		.memory_mem_ras_n(DRAM_nRAS),                  //                .mem_ras_n
		.memory_mem_cas_n(DRAM_nCAS),                  //                .mem_cas_n
		.memory_mem_we_n(DRAM_nWE),                   //                .mem_we_n
		.memory_mem_reset_n(DRAM_nRST),                //                .mem_reset_n
		.memory_mem_dq(DRAM_DATA),                     //                .mem_dq
		.memory_mem_dqs(DRAM_DQS),                    //                .mem_dqs
		.memory_mem_dqs_n(DRAM_DQS_n),                  //                .mem_dqs_n
		.memory_mem_odt(DRAM_ODT)                     //                .mem_odt
	);

//===========for test===================
adVirtualTest U4(
//===system============
.clk(clk),
.clk_200m(clk_200m),
.rst_n(rst_n),
//=====control===========
.control(ad_ctrl),
.length(ad_cnt),
.status(ad_status),

//===data flow====
.dma_sop(dma_in_sop),
.dma_eop(dma_in_eop),
.dma_empty(dma_in_empty),
.dma_ready(dma_in_ready),
.dma_valid(dma_in_valid),
.dma_data(dma_in_data)

);

endmodule