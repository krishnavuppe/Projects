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

entity des_top is

port ( data_in     : in  std_logic_vector (63 downto 0);
		 key_in      : in  std_logic_vector (63 downto 0);
		 function_in : in  std_logic;
		 data_out    : out std_logic_vector (63 downto 0));
		 
end des_top; 

architecture Behavioral of des_top is

component ip is

port(a:in std_logic_vector(63 downto 0);
     b:out std_logic_vector(63 downto 0));
	  
end component ;

component key_schedule is

port(a:in std_logic_vector(63 downto 0);
     e_d:in std_logic;
	  key1,key2,key3,key4,key5,key6,key7,key8,
	  key9,key10,key11,key12,key13,key14,key15,key16:out std_logic_vector(47 downto 0));
	  
end component;



component block_top is
port(
		
		L_in: in std_logic_vector(0 to 31);
		R_in: in std_logic_vector(0 to 31);
	
		
		L_out: out std_logic_vector(0 to 31);
		R_out: out std_logic_vector(0 to 31);

     	
		round_key_des: in std_logic_vector(0 to 47)	

	);
end component;

component swaping is

port(a:in  std_logic_vector(63 downto 0);
     b:out std_logic_vector(63 downto 0));
	  
end component;

component inv_ip is

port(a:in  std_logic_vector(63 downto 0);
     b:out std_logic_vector(63 downto 0));
end component;


signal s1,s2,s3,s4 : std_logic_vector (63 downto 0);
signal l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,l13,l14,l15,l16,l17: std_logic_vector (31 downto 0);
signal r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16,r17: std_logic_vector (31 downto 0);
signal k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11,k12,k13,k14,k15,k16 : std_logic_vector (47 downto 0);

begin

Initial_permutation : ip port map ( a => data_in , b => s1 );

l1 <= s1(63 downto 32);
r1 <= s1(31 downto 0 );

key_gen : key_schedule 
port map ( a=>key_in,e_d=>function_in,
           key1=>k1,key2=>k2,key3=>k3,key4=>k4,key5=>k5,key6=>k6,
			  key7=>k7,key8=>k8,key9=>k9,key10=>k10,key11=>k11,key12=>k12,
			  key13=>k13,key14=>k14,key15=>k15,key16=>k16);

round1 : block_top port map (l_in=>l1 ,r_in=>r1, l_out=>l2 ,r_out=>r2 ,round_key_des=>k1) ;
round2 : block_top port map (l_in=>l2 ,r_in=>r2, l_out=>l3 ,r_out=>r3 ,round_key_des=>k2) ;
round3 : block_top port map (l_in=>l3 ,r_in=>r3, l_out=>l4 ,r_out=>r4 ,round_key_des=>k3) ;
round4 : block_top port map (l_in=>l4 ,r_in=>r4, l_out=>l5 ,r_out=>r5 ,round_key_des=>k4) ;
round5 : block_top port map (l_in=>l5 ,r_in=>r5, l_out=>l6 ,r_out=>r6 ,round_key_des=>k5) ;
round6 : block_top port map (l_in=>l6 ,r_in=>r6, l_out=>l7 ,r_out=>r7 ,round_key_des=>k6) ;
round7 : block_top port map (l_in=>l7 ,r_in=>r7, l_out=>l8 ,r_out=>r8 ,round_key_des=>k7) ;
round8 : block_top port map (l_in=>l8 ,r_in=>r8, l_out=>l9 ,r_out=>r9 ,round_key_des=>k8) ;
round9 : block_top port map (l_in=>l9 ,r_in=>r9, l_out=>l10,r_out=>r10,round_key_des=>k9) ;
round10: block_top port map (l_in=>l10,r_in=>r10,l_out=>l11,r_out=>r11,round_key_des=>k10);
round11: block_top port map (l_in=>l11,r_in=>r11,l_out=>l12,r_out=>r12,round_key_des=>k11);
round12: block_top port map (l_in=>l12,r_in=>r12,l_out=>l13,r_out=>r13,round_key_des=>k12);
round13: block_top port map (l_in=>l13,r_in=>r13,l_out=>l14,r_out=>r14,round_key_des=>k13);
round14: block_top port map (l_in=>l14,r_in=>r14,l_out=>l15,r_out=>r15,round_key_des=>k14);
round15: block_top port map (l_in=>l15,r_in=>r15,l_out=>l16,r_out=>r16,round_key_des=>k15);
round16: block_top port map (l_in=>l16,r_in=>r16,l_out=>l17,r_out=>r17,round_key_des=>k16);



s2<= l17&r17;

swap: swaping port map (a=>s2,b=>s3);

inv_iniperm : inv_ip port map (a=>s3,b=>s4 );



data_out <= s4;
			 



end Behavioral;

