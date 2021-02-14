

-- Top file

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

entity wathdog_timer is
	port 
	(
	CLOCK_50         : in  std_logic;
	RESET_N          : in  std_logic;
	KEY              : in  std_logic;-- push button "stuck key"
	KEY_enable_dog   : in  std_logic;-- slide switch to enable watchdog
	

	--heartbeat        : in  std_logic;--for testing component_watchDog
	--reset_out        : out std_logic;--for testing component_watchDog

	--i_Binary         : in std_logic_vector(7 downto 0);--for testing binary_to_bcd
	--i_DV_n           : in  std_logic;                  --for testing binary_to_bcd
	
	LEDR             : out std_logic_vector(9 downto 0); -- led diodes are set during cpu stuck
	HEX0             : out std_logic_vector(6 downto 0); -- seven segment diodes
	HEX1             : out std_logic_vector(6 downto 0) -- seven segment diodes
	);

end entity;


architecture behavioral of wathdog_timer is

   component component_watchDog is
	port 
	(
	clock_50		       : in std_logic;
	reset_n		       : in std_logic;
	kicker_heartbeat   : in std_logic; -- if not active "no heartbeat" within a second gives (reset_out <= high)
	
	watchdog_enable    : in std_logic; -- if not enable watchdog has no effect on system
	reset_out_n        : out std_logic -- active two clock cycles when no heartbeat is detected
	);
	end component component_watchDog;

   component binary_to_bcd is
	port 
	(
	--input ports  
		i_Clock		   :  in std_logic;
		i_Reset_n	   :  in std_logic;
		i_Binary	      :  in std_logic_vector (7 downto 0);--timer value from cpu up to 99
		i_DV_n		   :  in std_logic;
		
		--output ports
		o_Sev_seg_1    :  out std_logic_vector(6 downto 0); 	-- 7-segment display
		o_Sev_seg_2    :  out std_logic_vector(6 downto 0) 	-- 7-segment display

   );
	end component binary_to_bcd;
	
	component polling_interrupt_cpu_system is
	port
	(
		clk_clk                  : in  std_logic                    := '0'; --               clk.clk
		i_push_button_export     : in  std_logic                    := '0'; --     i_push_button.export
		o_kicke_heartbeat_export : out std_logic;                           -- o_kicke_heartbeat.export
		o_leds_export            : out std_logic_vector(9 downto 0);        --            o_leds.export
		o_seven_seg_dv_export    : out std_logic;                           --    o_seven_seg_dv.export
		o_seven_segment_export   : out std_logic_vector(7 downto 0);        --   o_seven_segment.export
		reset_reset_n            : in  std_logic                    := '0'  --             reset.reset_n
	);
	end component polling_interrupt_cpu_system;
	
	
	signal s_reset_n       : std_logic;
	signal s_kicker        : std_logic;
	signal s_seven_seg_DV  : std_logic;
	signal s_i_binary      : std_logic_vector (7 downto 0);  
	
	

begin

   component_watchDog_portmap : component component_watchDog
		port map (
		clock_50              => CLOCK_50, 
	   reset_n               => RESET_N,
	   --kicker_heartbeat      => heartbeat, -- change heartbeat to s_kicker after testbench
		
		kicker_heartbeat      => s_kicker,
		
   	watchdog_enable       => KEY_enable_dog,
	   reset_out_n           => s_reset_n
		);
	
	  component_binary_to_bcd_portmap : component binary_to_bcd
		port map (
		i_Clock             => CLOCK_50,
		i_Reset_n           => RESET_N,
		--i_Binary            => i_Binary, -- change i_Binary to s_i_binary after testbench
		--i_DV_n              => i_DV_n,  -- change i_DV_n  to s_seven_seg_DV after testbench
		
		
	   i_Binary            => s_i_binary, -- change i_Binary to s_i_binary
		i_DV_n              => '0', -- s_seven_seg_DV,  -- change i_DV_n  to s_seven_seg_DV
		
		o_Sev_seg_1         => HEX0,
		o_Sev_seg_2         => HEX1
		);
		
	component_polling_interrupt_cpu_system_portmap: component polling_interrupt_cpu_system
	   port map(
		clk_clk                     =>   CLOCK_50,
		o_kicke_heartbeat_export    =>   s_kicker, --  kicker_output_export.export
		o_leds_export               =>   LEDR,     -- output to leds diodes
		i_push_button_export        =>   KEY, --  push_button_input_export.export
		reset_reset_n               =>   s_reset_n,
		o_seven_seg_dv_export       => s_seven_seg_DV,  -- seven_seg_data_validate_output_export.export
		o_seven_segment_export      => s_i_binary       -- value_to_seven_segment_outputl_export.export
		);
		


end behavioral;
