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
        sw            : in std_logic;
        switches      : in std_logic_vector(1 downto 0);
        leds          : out std_logic_vector(1 downto 0);
        rled          : out std_logic;
        sev_seg_0     : out std_logic_vector(6 downto 0)
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
            leds_external_connection_export     : out std_logic_vector(1 downto 0); -- export
            switches_external_connection_export : in std_logic_vector(1 downto 0) := (others => 'X'); -- export
            sev_seg_0_external_connection_export: out std_logic_vector(6 downto 0);
				randoms_external_connection_export : in std_logic_vector(31 downto 0)
        );
    end component blinky;

begin
    u0 : component blinky
        port map (
            clk_clk                             => clk,
            reset_reset_n                       => reset_n,
            leds_external_connection_export     => leds,
            switches_external_connection_export => switches,
            sev_seg_0_external_connection_export=> sev_seg_0,
				randoms_external_connection_export => randoms
        );

    -- begin custom hardware
    -- turning on red LED when the most left switch is up
    process (reset_n, clk)
    begin
        if reset_n = '0' then
            rled_tmp <= '0';
        elsif rising_edge(clk) then
            if sw = '1' then
                rled_tmp <= '1';
            else
                rled_tmp <= '0';
            end if;
        end if;
    end process;
    rled <= rled_tmp;
	 
	 --random number generation
	 process (reset_n, clk)
	 begin
    if reset_n = '0' then
      lfsr_reg <= "01010111010101010101010101111001";
    elsif rising_edge(clk) then
      -- LFSR feedback polynomial: x^32 + x^22 + x^2 + x^1 + 1
      lfsr_reg(31 downto 1) <= lfsr_reg(30 downto 0);
      lfsr_reg(0) <= lfsr_reg(31) xor lfsr_reg(22) xor lfsr_reg(2) xor lfsr_reg(1);
    end if;
  end process;
    

    randoms <= lfsr_reg;

	 
	
    -- end custom hardware
	 
	 

end architecture rtl_and_struct;
