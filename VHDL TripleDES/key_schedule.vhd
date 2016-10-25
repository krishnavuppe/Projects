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

entity key_schedule is

port(a:in std_logic_vector(63 downto 0);
     e_d:in std_logic;
	  key1,key2,key3,key4,key5,key6,key7,key8,
	  key9,key10,key11,key12,key13,key14,key15,key16:out std_logic_vector(47 downto 0));
	  
end key_schedule;

architecture Behavioral of key_schedule is

signal pc1_out:std_logic_vector(55 downto 0);
signal k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11,k12,k13,k14,k15,k16:std_logic_vector(47 downto 0);
signal r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16:std_logic_vector(55 downto 0);
signal c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15,c16,c17,
		 d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13,d14,d15,d16,d17 :std_logic_vector (27 downto 0);

component pc1 is
port  ( 	key_in  : in  std_logic_vector(0 to 63);
			pc1_out     : out std_logic_vector(0 to 55)
 	    ); 
end component;

component shifting is
port (c:in std_logic_vector(27 downto 0);
		d:in std_logic_vector(27 downto 0);
      cout:out std_logic_vector(27 downto 0);
		dout:out std_logic_vector(27 downto 0);
	   round:in std_logic_vector(3 downto 0));
end component;

component pc2 is

port(a :in  std_logic_vector(55 downto 0);
     b :out std_logic_vector(47 downto 0));
	  
end component;

begin

permuted_choice1 : pc1 port map (key_in => a, pc1_out=> pc1_out ) ;
			  
c1 <= pc1_out(55 downto 28);
d1 <= pc1_out(27 downto 0);

s1 : shifting port map (c=>c1  ,d=>d1 ,cout=>c2, dout=>d2 ,round=>"0000" );
s2 : shifting port map (c=>c2  ,d=>d2 ,cout=>c3, dout=>d3 ,round=>"0001" );
s3 : shifting port map (c=>c3  ,d=>d3 ,cout=>c4, dout=>d4 ,round=>"0010" );
s4 : shifting port map (c=>c4  ,d=>d4 ,cout=>c5, dout=>d5 ,round=>"0011" );
s5 : shifting port map (c=>c5  ,d=>d5 ,cout=>c6, dout=>d6 ,round=>"0100" );
s6 : shifting port map (c=>c6  ,d=>d6 ,cout=>c7, dout=>d7 ,round=>"0101" );
s7 : shifting port map (c=>c7  ,d=>d7 ,cout=>c8, dout=>d8 ,round=>"0110" );
s8 : shifting port map (c=>c8  ,d=>d8 ,cout=>c9, dout=>d9 ,round=>"0111" );
s9 : shifting port map (c=>c9  ,d=>d9 ,cout=>c10,dout=>d10,round=>"1000" );
s10: shifting port map (c=>c10 ,d=>d10,cout=>c11,dout=>d11,round=>"1001" );
s11: shifting port map (c=>c11 ,d=>d11,cout=>c12,dout=>d12,round=>"1010" );
s12: shifting port map (c=>c12 ,d=>d12,cout=>c13,dout=>d13,round=>"1011" );
s13: shifting port map (c=>c13 ,d=>d13,cout=>c14,dout=>d14,round=>"1100" );
s14: shifting port map (c=>c14 ,d=>d14,cout=>c15,dout=>d15,round=>"1101" );
s15: shifting port map (c=>c15 ,d=>d15,cout=>c16,dout=>d16,round=>"1110" );
s16: shifting port map (c=>c16 ,d=>d16,cout=>c17,dout=>d17,round=>"1111" );

r1  <= c2&d2;
r2  <= c3&d3;
r3  <= c4&d4;
r4  <= c5&d5;
r5  <= c6&d6;
r6  <= c7&d7;
r7  <= c8&d8;
r8  <= c9&d9;
r9  <= c10&d10;
r10 <= c11&d11;
r11 <= c12&d12;
r12 <= c13&d13;
r13 <= c14&d14;
r14 <= c15&d15;
r15 <= c16&d16;
r16 <= c17&d17;

KR1 : pc2 port map (a=>r1, b=>k1);
KR2 : pc2 port map (a=>r2, b=>k2);
KR3 : pc2 port map (a=>r3, b=>k3);
KR4 : pc2 port map (a=>r4, b=>k4);
KR5 : pc2 port map (a=>r5, b=>k5);
KR6 : pc2 port map (a=>r6, b=>k6);
KR7 : pc2 port map (a=>r7, b=>k7);
KR8 : pc2 port map (a=>r8, b=>k8);
KR9 : pc2 port map (a=>r9, b=>k9);
KR10: pc2 port map (a=>r10,b=>k10);
KR11: pc2 port map (a=>r11,b=>k11);
KR12: pc2 port map (a=>r12,b=>k12);
KR13: pc2 port map (a=>r13,b=>k13);
KR14: pc2 port map (a=>r14,b=>k14);
KR15: pc2 port map (a=>r15,b=>k15);
KR16: pc2 port map (a=>r16,b=>k16);

process(e_d,k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11,k12,k13,k14,k15,k16)
begin
if(e_d='1')then
key1  <=k1;
key2  <=k2;
key3  <=k3;
key4  <=k4;
key5  <=k5;
key6  <=k6;
key7  <=k7;
key8  <=k8;
key9  <=k9;
key10<=k10;
key11<=k11;
key12<=k12;
key13<=k13;
key14<=k14;
key15<=k15;
key16<=k16;
elsif(e_d='0')then
key1<=k16;
key2<=k15;
key3<=k14;
key4<=k13;
key5<=k12;
key6<=k11;
key7<=k10;
key8 <=k9;
key9 <=k8;
key10<=k7;
key11<=k6;
key12<=k5;
key13<=k4;
key14<=k3;
key15<=k2;
key16<=k1;
end if;
end process;


			  



end Behavioral;

