	component blinky is
		port (
			audio_0_external_interface_BCLK     : in  std_logic                    := 'X';             -- BCLK
			audio_0_external_interface_DACDAT   : out std_logic;                                       -- DACDAT
			audio_0_external_interface_DACLRCK  : in  std_logic                    := 'X';             -- DACLRCK
			clk_clk                             : in  std_logic                    := 'X';             -- clk
			leds_external_connection_export     : out std_logic_vector(1 downto 0);                    -- export
			reset_reset_n                       : in  std_logic                    := 'X';             -- reset_n
			switches_external_connection_export : in  std_logic_vector(1 downto 0) := (others => 'X')  -- export
		);
	end component blinky;

	u0 : component blinky
		port map (
			audio_0_external_interface_BCLK     => CONNECTED_TO_audio_0_external_interface_BCLK,     --   audio_0_external_interface.BCLK
			audio_0_external_interface_DACDAT   => CONNECTED_TO_audio_0_external_interface_DACDAT,   --                             .DACDAT
			audio_0_external_interface_DACLRCK  => CONNECTED_TO_audio_0_external_interface_DACLRCK,  --                             .DACLRCK
			clk_clk                             => CONNECTED_TO_clk_clk,                             --                          clk.clk
			leds_external_connection_export     => CONNECTED_TO_leds_external_connection_export,     --     leds_external_connection.export
			reset_reset_n                       => CONNECTED_TO_reset_reset_n,                       --                        reset.reset_n
			switches_external_connection_export => CONNECTED_TO_switches_external_connection_export  -- switches_external_connection.export
		);

