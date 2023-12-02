--
-- top level (wrapper)
--
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity chip is
    port (
        clk           : in std_logic;
        reset_n       : in std_logic;
        switches      : in std_logic_vector(17 downto 0);
		  KEYS			 : in std_logic_vector(2 downto 0); 
		  LEDG          : out std_logic_vector(7 downto 0);
		  LEDR          : out std_logic_vector(16 downto 0);
        sev_seg_0     : out std_logic_vector(6 downto 0);
		  sev_seg_1     : out std_logic_vector(6 downto 0);
		  sev_seg_2     : out std_logic_vector(6 downto 0);
		  sev_seg_3     : out std_logic_vector(6 downto 0);
		  sev_seg_4     : out std_logic_vector(6 downto 0);
		  sev_seg_5  	 : out std_logic_vector(6 downto 0);
		  sev_seg_6   	 : out std_logic_vector(6 downto 0);
		  sev_seg_7     : out std_logic_vector(6 downto 0);
		  lcd_data : out std_logic_vector(7 downto 0);
		  lcd_en, lcd_rw, lcd_rs, lcd_on, lcd_blon : out std_logic
    );
end entity chip;

architecture rtl_and_struct of chip is
    signal rled_tmp : std_logic;
	 --signal count_i : std_logic_vector (31 downto 0);
	 --signal feedback : std_logic;
	 signal randoms : std_logic_vector(31 downto 0);
	 
	 --signal count_i : STD_LOGIC_VECTOR(31 downto 0);
    --signal feedback : STD_LOGIC;
    
    -- LFSR taps for a 32-bit LFSR
    --constant lfsr_taps : STD_LOGIC_VECTOR(31 downto 0) := "10000000000000000000000001100011";
	 signal lfsr_reg : STD_LOGIC_VECTOR(31 downto 0) := (others => '0');
	 

    component blinky is
        port (
            clk_clk                             : in std_logic := 'X'; -- clk
            reset_reset_n                       : in std_logic := 'X'; -- reset_n
            switches_external_connection_export : in std_logic_vector(17 downto 0) := (others => 'X'); -- export
				keys_external_connection_export: in std_logic_vector(2 downto 0);
				grn_leds_external_connection_export: out std_logic_vector(7 downto 0);
				red_leds_external_connection_export: out std_logic_vector(16 downto 0);
            sev_seg_0_external_connection_export: out std_logic_vector(6 downto 0);
				sev_seg_1_external_connection_export: out std_logic_vector(6 downto 0);
				sev_seg_2_external_connection_export: out std_logic_vector(6 downto 0);
				sev_seg_3_external_connection_export: out std_logic_vector(6 downto 0);
				sev_seg_4_external_connection_export: out std_logic_vector(6 downto 0);
				sev_seg_5_external_connection_export: out std_logic_vector(6 downto 0);
				sev_seg_6_external_connection_export: out std_logic_vector(6 downto 0);
				sev_seg_7_external_connection_export: out std_logic_vector(6 downto 0);
				randoms_external_connection_export : in std_logic_vector(31 downto 0);
				lcd_external_connection_export : out std_logic_vector(12 downto 0)
        );
    end component blinky;

begin
    u0 : component blinky
        port map (
            clk_clk                             => clk,
            reset_reset_n                       => reset_n,
            switches_external_connection_export => switches,
				keys_external_connection_export => KEYS,
				grn_leds_external_connection_export => LEDG,
				red_leds_external_connection_export => LEDR,
            sev_seg_0_external_connection_export=> sev_seg_0,
				sev_seg_1_external_connection_export=> sev_seg_1,
				sev_seg_2_external_connection_export=> sev_seg_2,
				sev_seg_3_external_connection_export=> sev_seg_3,
				sev_seg_4_external_connection_export=> sev_seg_4,
				sev_seg_5_external_connection_export=> sev_seg_5,
				sev_seg_6_external_connection_export=> sev_seg_6,
				sev_seg_7_external_connection_export=> sev_seg_7,
				randoms_external_connection_export => randoms, 
				lcd_external_connection_export(7 downto 0) => lcd_data(7 downto 0),
				lcd_external_connection_export(8) => lcd_en,
				lcd_external_connection_export(9) => lcd_rw,
				lcd_external_connection_export(10) => lcd_rs,
				lcd_external_connection_export(11) => lcd_on,
				lcd_external_connection_export(12) => lcd_blon
        );

--    -- begin custom hardware
--    -- turning on red LED when the most left switch is up
--    process (reset_n, clk)
--    begin
--        if reset_n = '0' then
--            rled_tmp <= '0';
--        elsif rising_edge(clk) then
--            if sw = '1' then
--                rled_tmp <= '1';
--            else
--                rled_tmp <= '0';
--            end if;
--        end if;
--    end process;
--    rled <= rled_tmp;
--	 
	 --random number generation
	 process (reset_n, clk)
	 begin
    if reset_n = '0' then
      lfsr_reg <= "01010111010101010101010101111001";
		--lfsr_reg <= "00000000000000000000000000000000";
    elsif rising_edge(clk) then
      -- LFSR feedback polynomial: x^32 + x^22 + x^2 + x^1 + 1
      lfsr_reg(31 downto 1) <= lfsr_reg(30 downto 0);
      lfsr_reg(0) <= lfsr_reg(31) xor lfsr_reg(22) xor lfsr_reg(2) xor lfsr_reg(1);
    end if;
  end process;
    

    randoms <= lfsr_reg;
--
--	 
--	
--    -- end custom hardware
	 
	 

end architecture rtl_and_struct;
