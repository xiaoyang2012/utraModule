/*
模拟AD输出模块，
输出数据，进入FIFO，通过AVALON-DMA写入DDR3

*/

module adVirtualTest(
//===system============
clk,
clk_200m,
rst_n,
//=====control===========
control,
length,
status,

//===data flow====
dma_sop,
dma_eop,
dma_empty,
dma_ready,
dma_valid,
dma_data

);

input clk,clk_200m,rst_n;

input [7:0]control;
input [15:0]length;
output [3:0]status;

output        dma_sop;               
output        dma_eop;                 
output [1:0]  dma_empty;                       
output [31:0] dma_data;                          
output        dma_valid;                       
input        dma_ready;


//==========reg&wire===================
reg [3:0]start_buf;
reg [15:0]send_cnt_buf[2:0];

reg [1:0]ad_status;
parameter sIDLE = 2'd0;
parameter sPROCESS = 2'd1;
parameter sWAIT = 2'd2;

reg [1:0]status_buf[2:0];

reg [29:0]ad_cnt;

//================code=================================
//====start_buf======
always@(posedge clk_200m or negedge rst_n)
if(!rst_n)
start_buf <= 4'd0;
else
start_buf <= {start_buf[2:0],control[0]};

always@(posedge clk_200m or negedge rst_n)
if(!rst_n)
begin
	send_cnt_buf[0]<= 16'd0;
	send_cnt_buf[0]<= 16'd0;
	send_cnt_buf[0]<= 16'd0;
end
else
begin
	send_cnt_buf[2]<= send_cnt_buf[1];
	send_cnt_buf[1]<= send_cnt_buf[0];
	send_cnt_buf[0]<= length;
end


//======status_buf==============
always@(posedge clk or negedge rst_n)
if(!rst_n)
begin
	status_buf[0] <= 2'd0;
	status_buf[1] <= 2'd0;
	status_buf[2] <= 2'd0;
end
else
begin
	status_buf[2] <= status_buf[1];
	status_buf[1] <= status_buf[0];
	status_buf[0] <= ad_status;
end


//ad_status
always@(posedge clk_200m or negedge rst_n)
if(!rst_n)
ad_status <= sIDLE;
else
begin
	case(ad_status)
	sIDLE:
	begin
		if(start_buf[3])
		ad_status <= sPROCESS;
	end
	sPROCESS:
	begin
		if(ad_cnt == send_cnt_buf[2])
		ad_status <= sWAIT;
	end
	sWAIT:
	begin
		if(start_buf[3] == 1'b0)
		ad_status <= sIDLE;
	end
	endcase
end

//===ad_cnt====
always@(posedge clk_200m or negedge rst_n)
if(!rst_n)
ad_cnt <= 30'd0;
else
begin
	if(ad_status == sPROCESS)
	begin
		if(dma_ready)
		ad_cnt <= ad_cnt + 1'b1;
		else
		ad_cnt <= ad_cnt;
	end
	else
	ad_cnt <= 30'd0;
end

assign dma_valid = (ad_status == sPROCESS)?1'b1:1'b0;
assign dma_data = {{ad_cnt[14:0],2'd0},{ad_cnt[14:0],2'd1}};

assign dma_empty = 2'd0;
assign dma_sop = (dma_valid&&(ad_cnt == 30'd0))?1'b1:1'b0;
assign dma_eop = (ad_cnt >= send_cnt_buf[2])?1'b1:1'b0;
assign status = status_buf[2];
endmodule