--
-- top level (wrapper)
--
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY chip IS
    PORT (
        clk : IN STD_LOGIC;
        reset_n : IN STD_LOGIC;
        sw : IN STD_LOGIC;
        switches : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
        leds : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
        rled : OUT STD_LOGIC
    );
END ENTITY chip;

ARCHITECTURE rtl_and_struct OF chip IS
    SIGNAL rled_tmp : STD_LOGIC;
    COMPONENT blinky IS
        PORT (
            clk_clk : IN STD_LOGIC := 'X'; -- clk
            reset_reset_n : IN STD_LOGIC := 'X'; -- reset_n
            leds_external_connection_export : OUT STD_LOGIC_VECTOR(1 DOWNTO 0); -- export
            switches_external_connection_export : IN STD_LOGIC_VECTOR(1 DOWNTO 0) := (OTHERS => 'X') -- export
        );
    END COMPONENT blinky;
BEGIN
    u0 : COMPONENT blinky
        PORT MAP(
            clk_clk => clk,
            reset_reset_n => reset_n,
            leds_external_connection_export => leds,
            switches_external_connection_export => switches
        );
    -- begin custom hardware
    -- turning on red LED when the most left switch is up
    PROCESS (reset_n, clk)
    BEGIN
        IF reset_n = '0' THEN
            rled_tmp <= '0';
        ELSIF rising_edge(clk) THEN
            IF (sw = '1') THEN
                rled_tmp <= '1';
            ELSE
                rled_tmp <= '0';
            END IF;
        END IF;
    END PROCESS;
    rled <= rled_tmp;
    -- end custom hardware
END ARCHITECTURE rtl_and_struct;