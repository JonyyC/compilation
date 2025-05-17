def do_whileExample(par1 int: x): returns int
begin
    do :
        begin
            x = x - 1;
        end
    while : x > 0;
    return x;
end