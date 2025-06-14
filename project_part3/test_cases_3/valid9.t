def foo(par1 int:i): returns bool
var 
    type bool:x;
begin 
    x = TRUE;
    for( i = 10; i > 0; i = i + 1):
    begin
        x = not x;    
    end

    return x;
end 
 
 
def _main_():  
var 
begin 

end 