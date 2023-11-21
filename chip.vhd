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
		switches: in std_logic_vector(1 downto 0);
		leds: out std_logic_vector(1 downto 0);
		rled: out std_logic; 
		audio: out std_logic_vector(1 downto 0)
	);
end entity chip;

architecture rtl_and_struct of chip is

signal rled_tmp : std_logic;

component blinky is
	port (
	clk_clk : in std_logic := 'X'; -- clk
	reset_reset_n : in std_logic := 'X'; -- reset_n
	leds_external_connection_export : out std_logic_vector(1 downto 0); -- export
	switches_external_connection_export : in std_logic_vector(1 downto 0) := (others => 'X'); -- export
	audio_0_external_interface_export : out std_logic_vector(1 downto 0) -- export
	);
end component blinky;

begin

u0 : component blinky
	port map (
		clk_clk => clk,
		reset_reset_n => reset_n,
		leds_external_connection_export => leds,
		switches_external_connection_export => switches,
		audio_0_external_interface_export => audio
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