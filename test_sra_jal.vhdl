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
				ram (  0) <= "11110000"; -- ori $t0,$zero,240
				ram (  1) <= "00000000";
				ram (  2) <= "00001000";
				ram (  3) <= "00110100";
				ram (  4) <= "10000011"; -- sra $t1,$t0,2
				ram (  5) <= "01001000";
				ram (  6) <= "00001000";
				ram (  7) <= "00000000";
				ram (  8) <= "00001111"; -- ori $t2,$zero,15
				ram (  9) <= "00000000";
				ram ( 10) <= "00001010";
				ram ( 11) <= "00110100";
				ram ( 12) <= "00000011"; -- sra $t3,$t2,8
				ram ( 13) <= "01011010";
				ram ( 14) <= "00001010";
				ram ( 15) <= "00000000";
				ram ( 16) <= "11111111"; -- lui $t4,65535
				ram ( 17) <= "11111111";
				ram ( 18) <= "00001100";
				ram ( 19) <= "00111100";
				ram ( 20) <= "00000000"; -- ori $t4,$t4,65280
				ram ( 21) <= "11111111";
				ram ( 22) <= "10001100";
				ram ( 23) <= "00110101";
				ram ( 24) <= "11000011"; -- sra $t5,$t4,3
				ram ( 25) <= "01101000";
				ram ( 26) <= "00001100";
				ram ( 27) <= "00000000";
				ram ( 28) <= "00000000"; -- lui $t6,32768
				ram ( 29) <= "10000000";
				ram ( 30) <= "00001110";
				ram ( 31) <= "00111100";
				ram ( 32) <= "00000011"; -- sra $t7,$t6,16
				ram ( 33) <= "01111100";
				ram ( 34) <= "00001110";
				ram ( 35) <= "00000000";
				ram ( 36) <= "00000000"; -- ori $t8,$zero,0
				ram ( 37) <= "00000000";
				ram ( 38) <= "00011000";
				ram ( 39) <= "00110100";
				ram ( 40) <= "01000011"; -- sra $t9,$t8,5
				ram ( 41) <= "11001001";
				ram ( 42) <= "00011000";
				ram ( 43) <= "00000000";
				ram ( 44) <= "00010010"; -- jal test_function1
				ram ( 45) <= "00000000";
				ram ( 46) <= "00000000";
				ram ( 47) <= "00001100";
				ram ( 48) <= "00010011"; -- jal test_function2
				ram ( 49) <= "00000000";
				ram ( 50) <= "00000000";
				ram ( 51) <= "00001100";
				ram ( 52) <= "00000001"; -- ori $a0,$zero,1
				ram ( 53) <= "00000000";
				ram ( 54) <= "00000100";
				ram ( 55) <= "00110100";
				ram ( 56) <= "00010110"; -- jal conditional_jump
				ram ( 57) <= "00000000";
				ram ( 58) <= "00000000";
				ram ( 59) <= "00001100";
				ram ( 60) <= "00000010"; -- ori $a0,$zero,2
				ram ( 61) <= "00000000";
				ram ( 62) <= "00000100";
				ram ( 63) <= "00110100";
				ram ( 64) <= "00010110"; -- jal conditional_jump
				ram ( 65) <= "00000000";
				ram ( 66) <= "00000000";
				ram ( 67) <= "00001100";
				ram ( 68) <= "00011101"; -- j end
				ram ( 69) <= "00000000";
				ram ( 70) <= "00000000";
				ram ( 71) <= "00001000";
				ram ( 72) <= "00001000"; -- jr $ra
				ram ( 73) <= "00000000";
				ram ( 74) <= "11100000";
				ram ( 75) <= "00000011";
				ram ( 76) <= "00010101"; -- jal nested_function
				ram ( 77) <= "00000000";
				ram ( 78) <= "00000000";
				ram ( 79) <= "00001100";
				ram ( 80) <= "00001000"; -- jr $ra
				ram ( 81) <= "00000000";
				ram ( 82) <= "11100000";
				ram ( 83) <= "00000011";
				ram ( 84) <= "00001000"; -- jr $ra
				ram ( 85) <= "00000000";
				ram ( 86) <= "11100000";
				ram ( 87) <= "00000011";
				ram ( 88) <= "00000001"; -- ori $t0,$zero,1
				ram ( 89) <= "00000000";
				ram ( 90) <= "00001000";
				ram ( 91) <= "00110100";
				ram ( 92) <= "00000011"; -- beq $a0,$t0,jump_target1
				ram ( 93) <= "00000000";
				ram ( 94) <= "10001000";
				ram ( 95) <= "00010000";
				ram ( 96) <= "00000010"; -- ori $t0,$zero,2
				ram ( 97) <= "00000000";
				ram ( 98) <= "00001000";
				ram ( 99) <= "00110100";
				ram (100) <= "00000010"; -- beq $a0,$t0,jump_target2
				ram (101) <= "00000000";
				ram (102) <= "10001000";
				ram (103) <= "00010000";
				ram (104) <= "00001000"; -- jr $ra
				ram (105) <= "00000000";
				ram (106) <= "11100000";
				ram (107) <= "00000011";
				ram (108) <= "00001000"; -- jr $ra
				ram (109) <= "00000000";
				ram (110) <= "11100000";
				ram (111) <= "00000011";
				ram (112) <= "00001000"; -- jr $ra
				ram (113) <= "00000000";
				ram (114) <= "11100000";
				ram (115) <= "00000011";
				ram (116) <= "00011101"; -- j end
				ram (117) <= "00000000";
				ram (118) <= "00000000";
				ram (119) <= "00001000";
				for i in 120 to 255 loop
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
