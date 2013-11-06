set_global_assignment -entity "pll_lvds" -library "lib_pll_lvds" -name IP_TOOL_NAME "altera_pll"
set_global_assignment -entity "pll_lvds" -library "lib_pll_lvds" -name IP_TOOL_VERSION "12.1"
set_global_assignment -entity "pll_lvds" -library "lib_pll_lvds" -name IP_TOOL_ENV "mwpim"
set_global_assignment -library "lib_pll_lvds" -name SPD_FILE [file join $::quartus(sip_path) "pll_lvds.spd"]

set_global_assignment -library "lib_pll_lvds" -name MISC_FILE [file join $::quartus(sip_path) "pll_lvds_sim/pll_lvds.vo"]
