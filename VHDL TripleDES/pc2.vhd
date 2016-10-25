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

entity pc2 is

port(a :in  std_logic_vector(55 downto 0);
     b :out std_logic_vector(47 downto 0));
	  
end pc2;

architecture Behavioral of pc2 is

begin

b  <= a(13)&a(16)&a(10)&a(23)&a(0) &a(4) &a(2) &a(27)&a(14)&a(5) &a(20)&a(9) &
		a(22)&a(18)&a(11)&a(3) &a(25)&a(7) &a(15)&a(6) &a(26)&a(19)&a(12)&a(1) &
		a(40)&a(51)&a(30)&a(36)&a(46)&a(54)&a(29)&a(39)&a(50)&a(44)&a(32)&a(47)&
		a(43)&a(48)&a(38)&a(55)&a(33)&a(52)&a(45)&a(41)&a(49)&a(35)&a(28)&a(31);


end Behavioral;

