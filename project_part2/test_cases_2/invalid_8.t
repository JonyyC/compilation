def FuncArgs(par1 int:x; par2 char:c1): returns int
var
    type string: str[100];
    type char*: c2;
begin
    str[x] = c1;
    c2 = null;
    return "string";
end

def _main_():
begin
end