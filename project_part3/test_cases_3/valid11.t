def foo(par1 real:x): returns int 
var 
    type int:a,b; 
begin 
    return b + a; 
end 

def empty(): returns int
begin
    return 10;
end
 
def _main_():  
var 
    type int:a,b; 
begin 
    a = 0; 
    a = call empty();
    call foo(3.14);
    call empty();
end 