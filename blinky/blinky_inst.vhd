	component blinky is
		port (
			buttons_external_connection_export  : in  std_logic_vector(2 downto 0)  := (others => 'X'); -- export
			clk_clk                             : in  std_logic                     := 'X';             -- clk
			leds_external_connection_export     : out std_logic_vector(1 downto 0);                     -- export
			reset_reset_n                       : in  std_logic                     := 'X';             -- reset_n
			switches_external_connection_export : in  std_logic_vector(17 downto 0) := (others => 'X')  -- export
		);
	end component blinky;

	u0 : component blinky
		port map (
			buttons_external_connection_export  => CONNECTED_TO_buttons_external_connection_export,  --  buttons_external_connection.export
			clk_clk                             => CONNECTED_TO_clk_clk,                             --                          clk.clk
			leds_external_connection_export     => CONNECTED_TO_leds_external_connection_export,     --     leds_external_connection.export
			reset_reset_n                       => CONNECTED_TO_reset_reset_n,                       --                        reset.reset_n
			switches_external_connection_export => CONNECTED_TO_switches_external_connection_export  -- switches_external_connection.export
		);

