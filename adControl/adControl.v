/*
名称：adControl.v
描述：
1，AD芯片LTC2150控制逻辑
2，工作在高速时钟区域
3，内部包含DDIO IPcore

*/

module adControl(
//===system====
clk,
rst,
// 7 lvds DATA INPUT 
ADC_D0,
ADC_D1,
ADC_D2,
ADC_D3,
ADC_D4,
ADC_D5,
ADC_D6,

ADC_CLKO,		// lvds clk		

ADC_nCS,
ADC_SCK,
ADC_SDI,
ADC_SDO,
ADC_PnS,

//AVG control
AGV_DATA,
AGV_CLK,
AGV_LTCH,

//data flaw
dout,
doutEn
);

input clk,rst;

input ADC_CLKO;
input ADC_D0;
input ADC_D1;
input ADC_D2;
input ADC_D3;
input ADC_D4;
input ADC_D5;
input ADC_D6;

output ADC_nCS;
output ADC_SCK;
output ADC_SDI;
input ADC_SDO;
output ADC_PnS;

output AGV_DATA;
output AGV_CLK;
output AGV_LTCH;

output[13:0] dout;
output doutEn;

//=================reg & wire================================
wire [6:0]ddio_din;
wire [6:0]ddio_douth;
wire [6:0]ddio_doutl;


//=========================code================================
assign ddio_din = {ADC_D6,ADC_D5,ADC_D4,ADC_D3,ADC_D2,ADC_D1,ADC_D0};
assign dout = {ddio_douth,ddio_doutl};
//1 DDIO
AD_DDIO U0(
	.aclr(rst),
	.datain(ddio_din),
	.inclock(ADC_CLKO),
	.dataout_h(ddio_douth),
	.dataout_l(ddio_doutl));



endmodule