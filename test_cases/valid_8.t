def two_funcs(par1 int:x; par2 int:y; par3 int:z; par4 real:f):
var  
    type char:d;
    type char*:c:'a'; 
    type bool:b:TRUE,b2;
    type int:x,z:15.2,y: 4.e-67; 
    type int*:y;
begin 
    if not x :  
    begin 
        x = x + y; 
    end 
    if x > y and x < z or x == y-z:
    begin 
        meow = x;
    end
    else: 
    begin 
        y = x + y + z; 
        z = y * 2; 
        f = z; 
    end  
    x = y; 
    len = |c|;
end 

def goo(): returns char 
begin 
    x = 15;
    call foo(x, 2 - 2 - 2/2, 3, 4.5);
    return c;
end 
