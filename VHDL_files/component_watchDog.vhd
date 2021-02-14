--------------------------------------------------------------------
-- Company: TEIS AB
-- Engineer: Saif Saadaldin
--
-- Create Date: 	 2021-02-10
-- Design Name: 	 binary_to_bcd
-- Target Devices: ALTERA MAX 10. DE10-Lite board
-- Tool versions:  Quartus Price Version 18.1.0
-- Testbench file: watchdog_timer.vht
-- Do file: 		 wave.do
--
-- Description: watchdog component that sends out active low reset signal if no kicker_heartbeat signal received with defined
--              amout of time. In this project the kicker_heartbeat must be high at least once a second. The component has a counter
--              for the time counting which will be rested each time kicker_heartbeat is high.
--              
----------------------------------------------------------------------------------------------------------------------


library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity component_watchDog is
			
	port 
	(
    clock_50           : in std_logic;
    reset_n            : in std_logic;
    kicker_heartbeat   : in std_logic; -- if not active "no heartbeat" within a second gives (reset_out <= high)
	
    watchdog_enable    : in std_logic; -- if not enable watchdog has no effect on system
    reset_out_n        : out std_logic -- active two clock cycles when no heartbeat is detected within a second
	);

end entity;

architecture behavioral of component_watchDog is
   
	signal s_reset_n_1      : std_logic;
	--signal s_reset_n_2     : std_logic;
	--signal s_reset_n_3     : std_logic; 
	signal s_count        : unsigned(25 downto 0);-- if s_count passes one second then the system must reset (reset_out_n <= '0')

	constant c_cnt_max : integer := 50000000; 
begin

	process(reset_n, clock_50)
	begin
		if (reset_n = '0') then
		   s_reset_n_1 <= '0';
			s_count <= (others => '0');
			
		elsif (rising_edge(clock_50)) then
			if(watchdog_enable = '1') then
			   if(kicker_heartbeat = '1') then
				   s_count <= (others => '0');-- heartbeat detected, reset s_count
				   s_reset_n_1 <= '1'; 
				else
				   if(s_count >= c_cnt_max+1) then 
				      s_reset_n_1 <= '1';
						s_count <= (others => '0');
					else 
					   s_count <= s_count + 1;
					end if;
				end if;
			else
			   s_reset_n_1 <= '1';
			end if;
     end if;
	  
	end process;
	
	reset_out_n <= s_reset_n_1 when s_count < c_cnt_max else '0';
	
end behavioral;
