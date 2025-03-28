library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity memory is
	port
	(
		clk			: in  std_logic;
		rst			: in  std_logic;
		memread			: in  std_logic;
		memwrite		: in  std_logic;
		address1		: in  std_logic_vector (31 downto 0);
		address2		: in  std_logic_vector (31 downto 0);
		writedata		: in  std_logic_vector (31 downto 0);
		instruction		: out std_logic_vector (31 downto 0);
		readdata		: out std_logic_vector (31 downto 0)
	);
end memory;

architecture behavior of memory is
	type ramcell is array (0 to 255) of std_logic_vector (7 downto 0);
	signal ram			: ramcell;
	signal masked1, masked2		: std_logic_vector (7 downto 0);
	signal selector1, selector2	: natural range 0 to 255;
begin
	masked1 <= address1 (7 downto 2) & "00";
	masked2 <= address2 (7 downto 2) & "00";
	selector1 <= to_integer (unsigned (masked1));
	selector2 <= to_integer (unsigned (masked2));

	process (clk, rst, memread, memwrite, address1, address2, writedata)
	begin
		if (rising_edge (clk)) then
			if (rst = '1') then
				ram (  0) <= "00000000"; -- lui $t0 32768
				ram (  1) <= "10000000";
				ram (  2) <= "00001000";
				ram (  3) <= "00111100";
				ram (  4) <= "00000000"; -- ori $t0 $t0 0
				ram (  5) <= "00000000";
				ram (  6) <= "00001000";
				ram (  7) <= "00110101";
				ram (  8) <= "10000011"; -- sra $t2 $t0 2
				ram (  9) <= "01010000";
				ram ( 10) <= "00001000";
				ram ( 11) <= "00000000";
				ram ( 12) <= "00110100"; -- lui $t3 4660
				ram ( 13) <= "00010010";
				ram ( 14) <= "00001011";
				ram ( 15) <= "00111100";
				ram ( 16) <= "01111000"; -- ori $t3 $t3 22136
				ram ( 17) <= "01010110";
				ram ( 18) <= "01101011";
				ram ( 19) <= "00110101";
				ram ( 20) <= "00000111"; -- jal function
				ram ( 21) <= "00000000";
				ram ( 22) <= "00000000";
				ram ( 23) <= "00001100";
				ram ( 24) <= "00001001"; -- j end
				ram ( 25) <= "00000000";
				ram ( 26) <= "00000000";
				ram ( 27) <= "00001000";
				ram ( 28) <= "00000001"; -- addi $t3 $t3 1
				ram ( 29) <= "00000000";
				ram ( 30) <= "01101011";
				ram ( 31) <= "00100001";
				ram ( 32) <= "00001000"; -- jr $ra
				ram ( 33) <= "00000000";
				ram ( 34) <= "11100000";
				ram ( 35) <= "00000011";
				ram ( 36) <= "00001001"; -- j end
				ram ( 37) <= "00000000";
				ram ( 38) <= "00000000";
				ram ( 39) <= "00001000";
				for i in 40 to 255 loop
					ram (i) <= std_logic_vector (to_unsigned (0, 8));
				end loop;
			else
				if (memwrite = '1') then
					ram (selector2 + 0) <= writedata (7 downto 0);
					ram (selector2 + 1) <= writedata (15 downto 8);
					ram (selector2 + 2) <= writedata (23 downto 16);
					ram (selector2 + 3) <= writedata (31 downto 24);
				end if;
			end if;
		end if;
	end process;
	instruction <= ram (selector1 + 3) & ram (selector1 + 2) & ram (selector1 + 1) & ram (selector1 + 0);
	with memread select
		readdata <=	std_logic_vector (to_unsigned (0, 32)) when '0',
				ram (selector2 + 3) & ram (selector2 + 2) & ram (selector2 + 1) & ram (selector2 + 0) when others;
end behavior;
