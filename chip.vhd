--
-- top level (wrapper)
--
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity chip is
port (
clk: in std_logic;
reset_n: in std_logic;
sw : in std_logic;
switches: in std_logic_vector(2 downto 0);
leds: out std_logic_vector(2 downto 0);
rled: out std_logic
);
end entity chip;
architecture rtl_and_struct of chip is
signal rled_tmp : std_logic;
component blinky is
port (
	clk_clk : in std_logic := 'X'; -- clk
	reset_reset_n : in std_logic := 'X'; -- reset_n
	leds_external_connection_export : out std_logic_vector(2 downto 0); -- export
	switches_external_connection_export : in std_logic_vector(2 downto 0) := (others => 'X') -- export
	lcd_external_interface_DATA         : inout std_logic_vector(7 downto 0) := (others => 'X'); -- DATA
   lcd_external_interface_ON           : out   std_logic;                                       -- ON
   lcd_external_interface_BLON         : out   std_logic;                                       -- BLON
   lcd_external_interface_EN           : out   std_logic;                                       -- EN
   lcd_external_interface_RS           : out   std_logic;                                       -- RS
   lcd_external_interface_RW           : out   std_logic;
);
end component blinky;
begin
u0 : component blinky
port map (
	clk_clk => clk,
	reset_reset_n => reset_n,
	leds_external_connection_export => leds,
	switches_external_connection_export => switches,
	lcd_external_interface_DATA         => CONNECTED_TO_lcd_external_interface_DATA,         --       lcd_external_interface.DATA
   lcd_external_interface_ON           => CONNECTED_TO_lcd_external_interface_ON,           --                             .ON
   lcd_external_interface_BLON         => CONNECTED_TO_lcd_external_interface_BLON,         --                             .BLON
   lcd_external_interface_EN           => CONNECTED_TO_lcd_external_interface_EN,           --                             .EN
   lcd_external_interface_RS           => CONNECTED_TO_lcd_external_interface_RS,           --                             .RS
   lcd_external_interface_RW           => CONNECTED_TO_lcd_external_interface_RW,           --                             .RW
   leds_external_connection_export     => CONNECTED_TO_leds_external_connection_export,     --     leds_external_connection.export
);
-- begin custom hardware
-- turning on red LED when the most left switch is up
process (reset_n, clk)
begin
if reset_n = '0' then
rled_tmp <= '0';
elsif rising_edge(clk) then
if (sw = '1') then
rled_tmp <= '1';
else
rled_tmp <= '0';
end if;
end if;
end process;
rled <= rled_tmp;
-- end custom hardware
end architecture rtl_and_struct;