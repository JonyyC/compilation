def addTwo(par1 int:x; par2 int:y; par3 real:f): returns int
var
    type int:res;
begin
    res = x + y;
    f = call addTwo(35, 34, 34.8);
    return res;
end

def _main_():
begin
    call addTwo(35, 34, 34.8);
end
