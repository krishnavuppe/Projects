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

entity inv_ip is

port(a:in  std_logic_vector(63 downto 0);
     b:out std_logic_vector(63 downto 0));
end inv_ip;

architecture Behavioral of inv_ip is

begin

b	 <=a(39)&a(7) &a(47)&a(15)&a(55)&a(23)&a(63)&a(31)&
		a(38)&a(6) &a(46)&a(14)&a(54)&a(22)&a(62)&a(30)&
		a(37)&a(5) &a(45)&a(13)&a(53)&a(21)&a(61)&a(29)&
		a(36)&a(4) &a(44)&a(12)&a(52)&a(20)&a(60)&a(28)&
		a(35)&a(3) &a(43)&a(11)&a(51)&a(19)&a(59)&a(27)&
		a(34)&a(2) &a(42)&a(10)&a(50)&a(18)&a(58)&a(26)&
		a(33)&a(1) &a(41)&a(9) &a(49)&a(17)&a(57)&a(25)&
		a(32)&a(0) &a(40)&a(8) &a(48)&a(16)&a(56)&a(24);


end Behavioral;

