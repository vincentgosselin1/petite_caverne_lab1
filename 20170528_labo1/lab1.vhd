library ieee;
use ieee.std_logic_1164.all;

entity lab1 is 
	port(clock_50 : in std_logic;
		  sw    : in std_logic_vector(9 downto 0);  -- tel qu'indiqué sur le board.
		  ledr  : out std_logic_vector(1 downto 0);
		  hex0  : out std_logic_vector(6 downto 0);
		  hex1  : out std_logic_vector(6 downto 0);
		  hex2  : out std_logic_vector(6 downto 0);
		  hex3  : out std_logic_vector(6 downto 0); 
		  hex4  : out std_logic_vector(6 downto 0); 
		  hex5  : out std_logic_vector(6 downto 0);  
		  key : in std_logic_vector(3 downto 0)
		 );
	end lab1; 
	
architecture structural of lab1 is 
	
		component system is
		port (
			buttons_i_export  : in  std_logic_vector(3 downto 0)  := (others => '0'); -- export
			clk_clk           : in  std_logic                     := '0';             -- clk
			leds_o_export     : out std_logic_vector(1 downto 0);                     -- export
			reset_reset_n     : in  std_logic                     := '1';             -- reset_n
			sseg_i_iv_export  : out std_logic_vector(31 downto 0);                    -- export
			sseg_v_vi_export  : out std_logic_vector(31 downto 0);                    -- export
			switches_i_export : in  std_logic_vector(9 downto 0)  := (others => '0')  -- export
		);
	end component system;

begin 
	nios_system : system
	port map ( clk_clk => clock_50,
				  leds_o_export => ledr,
				  sseg_i_iv_export(6 downto 0) =>  hex0,
				  sseg_i_iv_export(14 downto 8) => hex1,
				  sseg_i_iv_export(22 downto 16) => hex2,
				  sseg_i_iv_export(30 downto 24) => hex3,
				  sseg_v_vi_export(6 downto 0) =>  hex4,
				  sseg_v_vi_export(14 downto 8) => hex5,
				  switches_i_export => sw,
				  buttons_i_export => key
				);
				
end structural;