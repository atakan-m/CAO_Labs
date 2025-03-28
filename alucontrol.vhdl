library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity ALUControl is
  Port (
    ALUOp    : in  std_logic_vector(1 downto 0);
    funct    : in  std_logic_vector(5 downto 0);
    alucontrol : out std_logic_vector(3 downto 0)
  );
end ALUControl;

architecture Behavioral of ALUControl is
begin
  process(ALUOp, funct)
  begin
    -- For R-type instructions, ALUOp is typically "10"
    if ALUOp = "10" then
      case funct is
        when "100000" =>   -- add
          alucontrol <= "0010";
        when "100010" =>   -- sub
          alucontrol <= "0110";
        when "000011" =>   -- sra: arithmetic shift right
          alucontrol <= "1001";  -- choose an unused control code, here "1001"
        when others  =>
          alucontrol <= "XXXX";  -- undefined: you might want to add a default safe value here
      end case;
    else
      -- For non R-type instructions, you may decode based on ALUOp directly:
      -- (For example, LW/SW might have ALUOp = "00" meaning add)
      case ALUOp is
        when "00" => alucontrol <= "0010";  -- add for lw/sw
        when "01" => alucontrol <= "0110";  -- sub for branch
        when others => alucontrol <= "0000"; -- default
      end case;
    end if;
  end process;
end Behavioral;
