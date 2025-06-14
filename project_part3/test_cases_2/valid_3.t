def addTwo(par1 int:x; par2 int:y): returns int
var
    type int:res;
begin
    res = x + y;
    return res;
end

def _main_():
var 
    type int:x:0;
    type int:y:15;
begin
    x = y + x / 10 * 15 - x;
    y = y/y;
    call addTwo(x, y);
end