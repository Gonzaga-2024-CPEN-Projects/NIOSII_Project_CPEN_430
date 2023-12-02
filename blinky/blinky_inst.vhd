	component blinky is
		port (
			clk_clk                              : in  std_logic                     := 'X';             -- clk
			grn_leds_external_connection_export  : out std_logic_vector(7 downto 0);                     -- export
			keys_external_connection_export      : in  std_logic_vector(2 downto 0)  := (others => 'X'); -- export
			lcd_external_connection_export       : out std_logic_vector(12 downto 0);                    -- export
			randoms_external_connection_export   : in  std_logic_vector(31 downto 0) := (others => 'X'); -- export
			red_leds_external_connection_export  : out std_logic_vector(16 downto 0);                    -- export
			reset_reset_n                        : in  std_logic                     := 'X';             -- reset_n
			sev_seg_0_external_connection_export : out std_logic_vector(6 downto 0);                     -- export
			sev_seg_1_external_connection_export : out std_logic_vector(6 downto 0);                     -- export
			sev_seg_2_external_connection_export : out std_logic_vector(6 downto 0);                     -- export
			sev_seg_3_external_connection_export : out std_logic_vector(6 downto 0);                     -- export
			sev_seg_4_external_connection_export : out std_logic_vector(6 downto 0);                     -- export
			sev_seg_5_external_connection_export : out std_logic_vector(6 downto 0);                     -- export
			sev_seg_6_external_connection_export : out std_logic_vector(6 downto 0);                     -- export
			sev_seg_7_external_connection_export : out std_logic_vector(6 downto 0);                     -- export
			switches_external_connection_export  : in  std_logic_vector(17 downto 0) := (others => 'X')  -- export
		);
	end component blinky;

	u0 : component blinky
		port map (
			clk_clk                              => CONNECTED_TO_clk_clk,                              --                           clk.clk
			grn_leds_external_connection_export  => CONNECTED_TO_grn_leds_external_connection_export,  --  grn_leds_external_connection.export
			keys_external_connection_export      => CONNECTED_TO_keys_external_connection_export,      --      keys_external_connection.export
			lcd_external_connection_export       => CONNECTED_TO_lcd_external_connection_export,       --       lcd_external_connection.export
			randoms_external_connection_export   => CONNECTED_TO_randoms_external_connection_export,   --   randoms_external_connection.export
			red_leds_external_connection_export  => CONNECTED_TO_red_leds_external_connection_export,  --  red_leds_external_connection.export
			reset_reset_n                        => CONNECTED_TO_reset_reset_n,                        --                         reset.reset_n
			sev_seg_0_external_connection_export => CONNECTED_TO_sev_seg_0_external_connection_export, -- sev_seg_0_external_connection.export
			sev_seg_1_external_connection_export => CONNECTED_TO_sev_seg_1_external_connection_export, -- sev_seg_1_external_connection.export
			sev_seg_2_external_connection_export => CONNECTED_TO_sev_seg_2_external_connection_export, -- sev_seg_2_external_connection.export
			sev_seg_3_external_connection_export => CONNECTED_TO_sev_seg_3_external_connection_export, -- sev_seg_3_external_connection.export
			sev_seg_4_external_connection_export => CONNECTED_TO_sev_seg_4_external_connection_export, -- sev_seg_4_external_connection.export
			sev_seg_5_external_connection_export => CONNECTED_TO_sev_seg_5_external_connection_export, -- sev_seg_5_external_connection.export
			sev_seg_6_external_connection_export => CONNECTED_TO_sev_seg_6_external_connection_export, -- sev_seg_6_external_connection.export
			sev_seg_7_external_connection_export => CONNECTED_TO_sev_seg_7_external_connection_export, -- sev_seg_7_external_connection.export
			switches_external_connection_export  => CONNECTED_TO_switches_external_connection_export   --  switches_external_connection.export
		);

