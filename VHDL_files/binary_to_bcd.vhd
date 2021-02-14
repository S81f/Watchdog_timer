--------------------------------------------------------------------
-- Company: TEIS AB
-- Engineer: Saif Saadaldin
--
-- Create Date: 	 2021-02-10
-- Design Name: 	 binary_to_bcd
-- Target Devices: ALTERA MAX 10. DE10-Lite board
-- Tool versions:  Quartus Price Version 18.1.0
-- Testbench file:
-- Do file: 		
--
-- Description7
--					This module will convert the std_logic_vector(7 downto 0) from i_Binary to two variables each of std_logic_vector(6 downto 0).
--             THe output is the values used to set the 7 segments LEDS
--             This module is reused from previous projects adn originaly was capied from 
--             https://en.wikipedia.org/wiki/Double_dabble and modified to suit the project
-------------------------------------------------------------------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;


entity binary_to_bcd is
   Port (
	--input ports  
		i_Clock		   :  in std_logic;
		i_Reset_n	   :  in std_logic;
		i_Binary	      :  in std_logic_vector (7 downto 0);--timer value from cpu up to 99
		i_DV_n		   :  in std_logic; -- data validate
		
		--output ports
      --o_Ones 			:	out std_logic_vector (3 downto 0);
      --o_Tens 			:	out std_logic_vector (3 downto 0);
      --o_Hundreds		:	out std_logic_vector (3 downto 0);
		
		o_Sev_seg_1    :  out std_logic_vector(6 downto 0); 	-- 7-segment display
		o_Sev_seg_2    :  out std_logic_vector(6 downto 0) 	-- 7-segment display
		--o_Sev_seg_3  :  out std_logic_vector(6 downto 0) 	-- 7-segment display
	   --o_DV_n			:	out std_logic
   );
	
end binary_to_bcd;

architecture Behavioral of binary_to_bcd is


	-- Build an enumerated type for the statemachine
	type seven_seg_state_type is (idle, handle_in_data, display_seven_seg);
	-- Register to hold the current state
	signal seven_seg_state: seven_seg_state_type;

	signal 	sev_seg_1 : std_logic_vector(6 downto 0);
	signal 	sev_seg_2 : std_logic_vector(6 downto 0);
	--signal 	sev_seg_3 : std_logic_vector(6 downto 0);

	constant showZero  : std_logic_vector(6 downto 0)   := "1000000"; -- 0x40
	constant showOne   : std_logic_vector(6 downto 0)	 := "1111001";-- 0x79
	constant showTwo   : std_logic_vector(6 downto 0)   := "0100100";-- 0x24
	constant showThree : std_logic_vector(6 downto 0)   := "0110000";-- 0x30
	constant showFour  : std_logic_vector(6 downto 0)   :=	"0011001";-- 0x19
	constant showFive  : std_logic_vector(6 downto 0)   := "0010010";-- 0x12
	constant showSex   : std_logic_vector(6 downto 0)   := "0000010"; -- 0x02
	constant showSeven : std_logic_vector(6 downto 0)   := "1111000"; -- 0x38
	constant showEight : std_logic_vector(6 downto 0)   := "0000000"; -- 0x00
	constant showNine  : std_logic_vector(6 downto 0)   := "0011000"; -- 0x18
	constant reset     : std_logic_vector(6 downto 0)   := "0000000"; -- 0x07	
	
	

	--Build an enumerated type for the statemachines
	type bcd_state_type is (idle, copying_info, counting);
	-- Register to hold the current state

	signal bdc_state: bcd_state_type;
	signal bcd_signal	:	unsigned (7 downto 0);
   signal ones, tens   :   std_logic_vector(3 downto 0);
   signal internal_DV  :   std_logic;-- data validate

begin

	double_dabble: process(i_Clock,i_Reset_n)


	--variables are used in sequential VHDL inside a process.
	--They are local inside the process and uptaded without any delay.
	variable temp	: std_logic_vector (7 downto 0);
	variable bcd	: unsigned (7 downto 0);

	  
	  
	begin
  
		if i_Reset_n = '0' then
			temp 		   :=	(others => '0');
			bcd 	    	:=	(others => '0');
			bcd_signal 	<=	(others => '0');
			bdc_state 	<= idle;
	  
		elsif rising_edge(i_Clock) then
			case bdc_state is
			
				when idle =>
					temp 		:=	(others => '0');
					bcd 		:=	(others => '0');
					bcd_signal 	<=	(others => '0');
			 
			 -- read input into temp variable
					if i_DV_n = '0' then
						bdc_state <= copying_info;
					else
						bdc_state <= idle;
					end if;
				
				when copying_info =>
					temp := i_Binary;
					bdc_state <= counting;
						
				when counting =>
					
					 -- cycle 12 times as we have 12 input bits
					 -- this could be optimized, we do not need to check and add 3 for the 
					 -- first 3 iterations as the number can never be >4
					for i in 0 to 7 loop
					 
						if bcd(3 downto 0) > 4 then 
						  bcd(3 downto 0) := bcd(3 downto 0) + 3;
						end if;
						
						if bcd(7 downto 4) > 4 then 
						  bcd(7 downto 4) := bcd(7 downto 4) + 3;
						end if;
					 
						-- if bcd(11 downto 8) > 4 then
						-- bcd(11 downto 8) := bcd(11 downto 8) + 3;
						-- end if;
					 
						-- shift bcd left by 1 bit, copy MSB of temp into LSB of bcd
						bcd := bcd(6 downto 0) & temp(7); --& = Concatenation Operator and is not "and" operator
					 
						-- shift temp left by 1 bit
						temp := temp(6 downto 0) & '0';
					 
					end loop;
					 
				   bcd_signal <= bcd;
					bdc_state <= idle;
					 
			end case;
				 
				 
		end if;
  
	end process double_dabble;
		

	internal_DV <= '0' when bdc_state = counting else '1';
	
	
	-- set outputs
	ones			<= std_logic_vector(bcd_signal(3 downto 0));
	tens			<= std_logic_vector(bcd_signal(7 downto 4));
	--o_Hundreds		<= std_logic_vector(bcd_signal(11 downto 8));
	
--******************************************************************************************'
	
	
--******************************************************************************************'
	svens_seg: process(i_Clock, i_Reset_n)
	
	begin
		if i_Reset_n = '0' then
			sev_seg_1 <= (others => '0');
			sev_seg_2 <= (others => '0');
			--sev_seg_3 <= (others => '0');
			o_Sev_seg_1 <= (others => '0');
			o_Sev_seg_2 <= (others => '0');
			--o_Sev_seg_3 <= (others => '0');
			seven_seg_state <= idle;
		
		elsif rising_edge(i_Clock) then
		
			case seven_seg_state is
				
				when idle =>
					
					if internal_DV = '0' then	
						seven_seg_state <= handle_in_data;
					else
						seven_seg_state <= idle;
					end if;
				
				
				when handle_in_data =>
		
					case ones is
						when "0000" => sev_seg_1 <= showZero;
						when "0001" => sev_seg_1 <= showOne;
						when "0010" => sev_seg_1 <= showTwo;
						when "0011" => sev_seg_1 <= showThree;
						when "0100" => sev_seg_1 <= showFour;
						when "0101" => sev_seg_1 <= showFive;
						when "0110" => sev_seg_1 <= showSex;
						when "0111" => sev_seg_1 <= showSeven;
						when "1000" => sev_seg_1 <= showEight;
						when "1001" => sev_seg_1 <= showNine;
						when others => sev_seg_1 <= reset;
					end case;	
						

					case tens is
						when "0000" => sev_seg_2 <= showZero;
						when "0001" => sev_seg_2 <= showOne;
						when "0010" => sev_seg_2 <= showTwo;
						when "0011" => sev_seg_2 <= showThree;
						when "0100" => sev_seg_2 <= showFour;
						when "0101" => sev_seg_2 <= showFive;
						when "0110" => sev_seg_2 <= showSex;
						when "0111" => sev_seg_2 <= showSeven;
						when "1000" => sev_seg_2 <= showEight;
						when "1001" => sev_seg_2 <= showNine;
						when others => sev_seg_2 <= reset;
					end case;
										
					-- case i_Sev_seg_3 is
						-- when "0000" => sev_seg_3 <= showZero;
						-- when "0001" => sev_seg_3 <= showOne;
						-- when "0010" => sev_seg_3 <= showTwo;
						-- when "0011" => sev_seg_3 <= showThree;
						-- when "0100" => sev_seg_3 <= showFour;
						-- when "0101" => sev_seg_3 <= showFive;
						-- when "0110" => sev_seg_3 <= showSex;
						-- when "0111" => sev_seg_3 <= showSeven;
						-- when "1000" => sev_seg_3 <= showEight;
						-- when "1001" => sev_seg_3 <= showNine;
						-- when others => sev_seg_3 <= reset;
					-- end case;
					
					if internal_DV = '1' then
						seven_seg_state <= display_seven_seg;
					else
						seven_seg_state<= idle;
					end if;
						
				when display_seven_seg =>
					o_Sev_seg_1 <= sev_seg_1;
					o_Sev_seg_2 <= sev_seg_2;
					--o_Sev_seg_3 <= sev_seg_3;
					if internal_DV = '0' then
						seven_seg_state <= handle_in_data;
					else
						seven_seg_state <= display_seven_seg;
					end if;
			end case;	
		end if;
	end process;
  
end Behavioral;