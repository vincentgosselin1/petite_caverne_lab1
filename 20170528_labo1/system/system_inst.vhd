	component system is
		port (
			buttons_i_export  : in  std_logic_vector(3 downto 0)  := (others => 'X'); -- export
			clk_clk           : in  std_logic                     := 'X';             -- clk
			leds_o_export     : out std_logic_vector(1 downto 0);                     -- export
			reset_reset_n     : in  std_logic                     := 'X';             -- reset_n
			sseg_i_iv_export  : out std_logic_vector(31 downto 0);                    -- export
			sseg_v_vi_export  : out std_logic_vector(31 downto 0);                    -- export
			switches_i_export : in  std_logic_vector(9 downto 0)  := (others => 'X')  -- export
		);
	end component system;

	u0 : component system
		port map (
			buttons_i_export  => CONNECTED_TO_buttons_i_export,  --  buttons_i.export
			clk_clk           => CONNECTED_TO_clk_clk,           --        clk.clk
			leds_o_export     => CONNECTED_TO_leds_o_export,     --     leds_o.export
			reset_reset_n     => CONNECTED_TO_reset_reset_n,     --      reset.reset_n
			sseg_i_iv_export  => CONNECTED_TO_sseg_i_iv_export,  --  sseg_i_iv.export
			sseg_v_vi_export  => CONNECTED_TO_sseg_v_vi_export,  --  sseg_v_vi.export
			switches_i_export => CONNECTED_TO_switches_i_export  -- switches_i.export
		);

