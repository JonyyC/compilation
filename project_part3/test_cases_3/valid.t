def foo(par1 real:x): returns int
var 
    type int:a,b; 
    type int*:a_ptr;
    type real:r;
    type char:c;
    type char*:c_ptr;
    type string:str[50];
    type bool:b1;
begin 
    #-> b1 = not |str| > b or |str| <= b; <-# 
    #-> a = 23; <-#
    a = 23 + b / 8 + 50 * *a_ptr;
    c = str[23 + b / 8 + 50 * *a_ptr];
    c_ptr = &str[23 + b / 8 + 50 * *a_ptr];
    c = *(c_ptr - 23 - b / 8 + 50 * *a_ptr);

    b = call foo(5 + 5/5 * r / r - 3.14);
    return a + b;
end 
 
 
def _main_():  
var 
begin 

end 