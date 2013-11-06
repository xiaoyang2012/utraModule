// megafunction wizard: %ALTDDIO_IN%VBB%
// GENERATION: STANDARD
// VERSION: WM1.0
// MODULE: ALTDDIO_IN 

// ============================================================
// File Name: AD_DDIO.v
// Megafunction Name(s):
// 			ALTDDIO_IN
//
// Simulation Library Files(s):
// 			altera_mf
// ============================================================
// ************************************************************
// THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
//
// 12.1 Build 177 11/07/2012 SJ Full Version
// ************************************************************

//Copyright (C) 1991-2012 Altera Corporation
//Your use of Altera Corporation's design tools, logic functions 
//and other software and tools, and its AMPP partner logic 
//functions, and any output files from any of the foregoing 
//(including device programming or simulation files), and any 
//associated documentation or information are expressly subject 
//to the terms and conditions of the Altera Program License 
//Subscription Agreement, Altera MegaCore Function License 
//Agreement, or other applicable license agreement, including, 
//without limitation, that your use is for the sole purpose of 
//programming logic devices manufactured by Altera and sold by 
//Altera or its authorized distributors.  Please refer to the 
//applicable agreement for further details.

module AD_DDIO (
	aclr,
	datain,
	inclock,
	dataout_h,
	dataout_l);

	input	  aclr;
	input	[6:0]  datain;
	input	  inclock;
	output	[6:0]  dataout_h;
	output	[6:0]  dataout_l;

endmodule

// ============================================================
// CNX file retrieval info
// ============================================================
// Retrieval info: LIBRARY: altera_mf altera_mf.altera_mf_components.all
// Retrieval info: PRIVATE: INTENDED_DEVICE_FAMILY STRING "Cyclone V"
// Retrieval info: CONSTANT: INTENDED_DEVICE_FAMILY STRING "Cyclone V"
// Retrieval info: CONSTANT: INVERT_INPUT_CLOCKS STRING "OFF"
// Retrieval info: CONSTANT: LPM_HINT STRING "UNUSED"
// Retrieval info: CONSTANT: LPM_TYPE STRING "altddio_in"
// Retrieval info: CONSTANT: POWER_UP_HIGH STRING "OFF"
// Retrieval info: CONSTANT: WIDTH NUMERIC "7"
// Retrieval info: USED_PORT: aclr 0 0 0 0 INPUT NODEFVAL "aclr"
// Retrieval info: CONNECT: @aclr 0 0 0 0 aclr 0 0 0 0
// Retrieval info: USED_PORT: datain 0 0 7 0 INPUT NODEFVAL "datain[6..0]"
// Retrieval info: CONNECT: @datain 0 0 7 0 datain 0 0 7 0
// Retrieval info: USED_PORT: dataout_h 0 0 7 0 OUTPUT NODEFVAL "dataout_h[6..0]"
// Retrieval info: CONNECT: dataout_h 0 0 7 0 @dataout_h 0 0 7 0
// Retrieval info: USED_PORT: dataout_l 0 0 7 0 OUTPUT NODEFVAL "dataout_l[6..0]"
// Retrieval info: CONNECT: dataout_l 0 0 7 0 @dataout_l 0 0 7 0
// Retrieval info: USED_PORT: inclock 0 0 0 0 INPUT_CLK_EXT NODEFVAL "inclock"
// Retrieval info: CONNECT: @inclock 0 0 0 0 inclock 0 0 0 0
// Retrieval info: GEN_FILE: TYPE_NORMAL AD_DDIO.v TRUE FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL AD_DDIO.qip TRUE FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL AD_DDIO.bsf TRUE TRUE
// Retrieval info: GEN_FILE: TYPE_NORMAL AD_DDIO_inst.v TRUE TRUE
// Retrieval info: GEN_FILE: TYPE_NORMAL AD_DDIO_bb.v TRUE TRUE
// Retrieval info: GEN_FILE: TYPE_NORMAL AD_DDIO.inc TRUE TRUE
// Retrieval info: GEN_FILE: TYPE_NORMAL AD_DDIO.cmp TRUE TRUE
// Retrieval info: GEN_FILE: TYPE_NORMAL AD_DDIO.ppf TRUE FALSE
// Retrieval info: LIB_FILE: altera_mf
