def foo(par1 real:x; par2 int:y): returns int 
var 
    type int:a,b; 
    type real: r:3.14;
    type string:str[50]:"hello", str2[10]:"hey";
begin 
    r = 15.6 * 15.8 - 10.6 / 16.5;
    return b + a; 
end 

def empty(): returns real
begin
    return 10;
end
 
def _main_():  
var 
    type int:a,b; 
    type real:a2;
begin 
    a = 0; 
    a2 = call empty();
    call foo(3.14, a);
    call empty();
end 
