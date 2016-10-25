library IEEE; 
use IEEE.STD_LOGIC_1164.ALL; 
use IEEE.STD_LOGIC_ARITH.ALL; 
use IEEE.STD_LOGIC_UNSIGNED.ALL; 

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity swaping is

port(a:in  std_logic_vector(63 downto 0);
     b:out std_logic_vector(63 downto 0));
	  
end swaping;

architecture Behavioral of swaping is

begin

b  <=a(31 downto 0)& a(63 downto 32);

end Behavioral;

