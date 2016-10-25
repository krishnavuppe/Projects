--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   21:08:22 03/31/2013
-- Design Name:   
-- Module Name:   I:/vhdl/chaitu/tb_proj.vhd
-- Project Name:  chaitu
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: TripleDES
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY tb_proj IS
END tb_proj;
 
ARCHITECTURE behavior OF tb_proj IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT TripleDES
    PORT(
         data_in : IN  std_logic_vector(63 downto 0);
         key1_in : IN  std_logic_vector(63 downto 0);
         key2_in : IN  std_logic_vector(63 downto 0);
         key3_in : IN  std_logic_vector(63 downto 0);
         fn_sel : IN  std_logic;
         data_out : OUT  std_logic_vector(63 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal data_in : std_logic_vector(63 downto 0) := (others => '0');
   signal key1_in : std_logic_vector(63 downto 0) := (others => '0');
   signal key2_in : std_logic_vector(63 downto 0) := (others => '0');
   signal key3_in : std_logic_vector(63 downto 0) := (others => '0');
   signal fn_sel : std_logic := '0';

 	--Outputs
   signal data_out : std_logic_vector(63 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
--   constant <clock>_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: TripleDES PORT MAP (
          data_in => data_in,
          key1_in => key1_in,
          key2_in => key2_in,
          key3_in => key3_in,
          fn_sel => fn_sel,
          data_out => data_out
        );

   -- Clock process definitions
 
 
   -- Stimulus process
   stim_proc: process
   begin		
	
           data_in<= x"bbbbbbbbbbbbbbbb";
		key1_in<= x"abababababababab";
		key2_in<= x"abcabcabcabcabca";
		key3_in<= x"abcdabcdabcdabcd";
		fn_sel <= '0';
		
		wait for 100 ns;
		data_in<= x"446cec5ac0943b43";
		key1_in<= x"abababababababab";
		key2_in<= x"abcabcabcabcabca";
		key3_in<= x"abcdabcdabcdabcd";
		fn_sel <= '1';
		

      wait;
   end process;

END;
