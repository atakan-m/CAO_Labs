library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity ALU is
  Port (
    A         : in  std_logic_vector(31 downto 0);
    B         : in  std_logic_vector(31 downto 0);
    shamt     : in  std_logic_vector(4 downto 0);  -- Shift amount extracted from the instruction (bits 10 downto 6)
    alucontrol : in std_logic_vector(3 downto 0);
    ALUResult  : out std_logic_vector(31 downto 0);
    Zero       : out std_logic            -- Optional flag output
  );
end ALU;

architecture Behavioral of ALU is
begin
  process(A, B, shamt, alucontrol)
  begin
    case alucontrol is
      when "0010" =>  -- add
        ALUResult <= std_logic_vector(signed(A) + signed(B));
      when "0110" =>  -- sub
        ALUResult <= std_logic_vector(signed(A) - signed(B));
      when "1001" =>  -- sra: arithmetic shift right
        -- Convert B to signed so that the shift replicates the sign bit.
        ALUResult <= std_logic_vector(shift_right(signed(B), to_integer(unsigned(shamt))));
      -- Add other operations as needed
      when others =>
        ALUResult <= (others => '0');
    end case;
    
    -- Optional: Set Zero flag if the result is zero
    if ALUResult = (others => '0') then
      Zero <= '1';
    else
      Zero <= '0';
    end if;
  end process;
end Behavioral;
