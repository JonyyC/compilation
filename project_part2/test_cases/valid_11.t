def if_else(par1 int:x; par2 int:y; par3 int:z):
begin
    if x > y and x / 2 > z / 3 and not x != 0:
    var
        type int: t;
    begin 
        x = x + y / z ;
    end
    else:
    var 
        type int: t;
    begin
        x = y ;
        y = y * z;
        x = y - z;
    end

    if x > y: x = x + y ;
    else: y = y - x;
end