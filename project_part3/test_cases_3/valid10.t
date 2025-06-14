def foo(par1 real:x): returns int 
var 
    type int:a,b; 
    type int*:b_ptr;
    type string:str[50];
    type char:c;
    type char*:c_ptr;
begin 
    a = 23; 
    a = -a;
    if a == 23: 
    begin 
        b = 10; 
    end 
    else: b = 19; 
    b_ptr = &b;

    c = str[-a * -b];

    c_ptr  = &str[a + b];
    str[a * b] = c;

    c = *(c_ptr + b);

    *c_ptr = c;
    return b + a; 
end 
 
 
def _main_():  
var 
    type int:a,b; 
begin 
    a = 0; 
    while a < 10: 
    begin 
        b = call foo(3.14); 
        a = a + b; 
    end  
end 