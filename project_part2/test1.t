def foo(par1 int:x; par2 int:y; par3 char:z; par4 real:f): 
var 
    type char*: x2;
    type int: y2;
    type char*: x_ptr;
begin 
    if x > y: 
    begin
        x = x + y;
    end 
    else: 
    begin 
        f = x + y; 
        x = y * 2; 
        f = f/2; 
        z = *(x_ptr + 5);       
    end 
end 
 
def _main_():
begin 
    call foo(1,2,'a',3.14);
end 