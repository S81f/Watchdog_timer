library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity timer_top is

	port
	(
		-- Input ports
		clk             : in std_logic;
		reset_n         : in std_logic;
		control_timer   : in std_logic_vector(1 downto 0);
		
		-- output ports
		timer_data      : inout std_logic_vector(31 downto 0)
		
	);

end timer_top;

architecture behavioral of timer_top is
begin
	
	hw_function_process : 
	process(clk,reset_n)
	begin
		if(reset_n = '0') then
			timer_data <= (others => '0');
		elsif (rising_edge(clk)) then
			case control_timer is
				-- Start timer
				when "10" =>
					timer_data <= timer_data + 1;
					
				-- Stop timer
				when "00" =>
					timer_data <= timer_data;
					
				-- Reset timer
				when "01" =>
					timer_data <= (others => '0');
					
				when others => null;
			end case;
		end if;
	end process;
	
end behavioral;