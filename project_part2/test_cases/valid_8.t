def two_funcs(par1 int:x; par2 int:y; par3 int:z; par4 real:f; par5 bool:b):
var  
    type char:d;
    type char*:c:'a'; 
    type bool:b2:TRUE;
    type real:x1, z2:15.2, y2: 4.e-67; 
    type int*: px;
    type int: len;
    type string: message[10];
begin 
    if not b :  
    begin 
        x = x + y; 
    end 
    if x > y and x < z or x == y-z:
    begin 
        px = &x;
    end
    else: 
    begin 
        y = x + y + z; 
        z = y * 2; 
        f = z; 
    end  
    x = y; 
    len = |message|;
end 

def goo(): returns char 
var  
    type char:d;
    type char*:c:'a'; 
    type bool:b:TRUE,b2;
    type real:x, z2:15.2, y2: 4.e-67; 
    type int*: px;
    type int: y;
begin 
    x = 15;
    call two_funcs(*px, 2 - 2 - 2/2,*px + y , 4.5, y != *px);
    return *c;
end 
