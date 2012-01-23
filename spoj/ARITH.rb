T = gets.to_i
(1..T).each do |t|
  line = gets
  n1, n2 = line.split(/[+*-]/).map{|x| x.to_i}
  op = line[/[+*-]/]
  n1_s = n1.to_s
  n2_s = op + n2.to_s
  if op =~ /[+-]/ or (op == '*' and n2 < 10)
    result = case op
             when "+" then n1 + n2
             when "-" then n1 - n2
             when "*" then n1 * n2
             end
    cols = [n1_s.size, n2_s.size, result.to_s.size].max
    line_size = [n2_s.size, result.to_s.size].max
    puts "%*s" % [cols, n1_s]
    puts "%*s" % [cols, n2_s]
    puts "%*s" % [cols, "-" * line_size]
    puts "%*s" % [cols, result]
  else
    result_s = (n1 * n2).to_s
    n2_digits = n2.to_s
    first_product_s = (n1 * n2_digits[-1..-1].to_i).to_s
    last_product_s = (n1 * n2_digits[0..0].to_i).to_s
    first_line_size = [n2_s.size, first_product_s.size].max
    second_line_size = [result_s.size, last_product_s.size+n2_digits.size-1].max
    cols = [result_s.size, n1_s.size, n2_s.size].max
    puts "%*s" % [cols, n1_s]
    puts "%*s" % [cols, n2_s]
    puts "%*s" % [cols, "-" * first_line_size]
    for i in -1.downto(-n2_digits.size)
      puts "%*s" % [cols + i + 1, n1 * n2_digits[i..i].to_i]
    end
    puts "%*s" % [cols, "-" * second_line_size]
    puts "%*s" % [cols, result_s]
  end
  puts
end
exit 0
