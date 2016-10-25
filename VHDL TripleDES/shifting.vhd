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

entity shifting is

port (c:in std_logic_vector(27 downto 0);
		d:in std_logic_vector(27 downto 0);
      cout:out std_logic_vector(27 downto 0);
		dout:out std_logic_vector(27 downto 0);
	   round:in std_logic_vector(3 downto 0));
end shifting;

architecture Behavioral of shifting is

begin

process(round,c,d)
begin

if(round ="0000" or round="0001" or round="1000" or round="1111") then
cout <=c(26 downto 0)&c(27);
dout <=d(26 downto 0)&d(27);
else
cout <=c(25 downto 0)&c(27)&c(26);
dout <=d(25 downto 0)&d(27)&d(26);
end if;
end process;


end Behavioral;

