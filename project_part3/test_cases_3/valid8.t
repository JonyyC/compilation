def foo(par1 int:i): returns bool
var 
    type bool:x;
begin 
    x = TRUE;
    while (i > 0):
    begin
        x = not x;
        i = i - 1;
    end
    i = 10;
    do:
    begin
        if i == 0: x = FALSE;
    end
    while: i > 0;

    return x;
end 
 
 
def _main_():  
var 
begin 

end 