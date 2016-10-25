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

entity TripleDES is
   port (data_in : in std_logic_vector (63 downto 0);
         key1_in : in std_logic_vector (63 downto 0);
			key2_in : in std_logic_vector (63 downto 0);
			key3_in : in std_logic_vector (63 downto 0);
			fn_sel  : in std_logic;
			data_out: out std_logic_vector (63 downto 0)
         );
end TripleDES;

architecture Behavioral of TripleDES is

component des_top is

port ( data_in     : in  std_logic_vector (63 downto 0);
		 key_in      : in  std_logic_vector (63 downto 0);
		 function_in : in  std_logic;
		 data_out    : out std_logic_vector (63 downto 0));
		 
end component; 

signal dataout_des1,dataout_des2 : std_logic_vector (63 downto 0);
signal invfunc : std_logic;
signal k1,k3: std_logic_vector (63 downto 0);

begin

invfunc <= not(fn_sel);

process (fn_sel,k1,k3)

begin

if(fn_sel='1') then

k1<=key1_in;
k3<=key3_in;

else

k1<=key3_in;
k3<=key1_in;

end if;
end process;


DES1: des_top 
port map (data_in => data_in ,
			 key_in=>k1,
			 function_in=>fn_sel,
			 data_out=>dataout_des1);
			 
DES2: des_top 
port map (data_in =>dataout_des1  ,
			 key_in=>key2_in,
			 function_in=>invfunc,
			 data_out=>dataout_des2);

DES3: des_top 
port map (data_in =>dataout_des2 ,
			 key_in=>k3,
			 function_in=>fn_sel,
			 data_out=>data_out);
			 			 
end Behavioral;

