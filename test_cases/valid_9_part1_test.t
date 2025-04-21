def foo(par1 int:x; par2 int:y; par3 int:z; par4 real:f):  
begin 
    if x > y:  x = x +y;
    else: 
    begin 
        y = x + y + z; 
        z = y * 2; 
        f = z; 
    end 

    x = |str|;
    * y = x;
    z = y;
end 
 
def goo(): returns char 
begin 
    return 'a'; 
end 