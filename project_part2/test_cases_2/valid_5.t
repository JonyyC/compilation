def ptr_ops(par1 int:x; par2 char:c; par3 real:f):
var
    type int*:x_ptr;
    type real*:f_ptr;
    type char*:c_ptr;
    type bool:b;
    type string:  str[15]:"moshe";
begin 
    x = x + x / x * x - x;
    x_ptr = &x;
    f = (x + f) / x * f - f;
    f_ptr = &f;
    c = *(c_ptr - 5);
    c_ptr = &str[10];
    c_ptr = &str[x + x];
    x = *x_ptr + *x_ptr;
    str = "hello\n";
    c = str[5];
    str[15] = ' ';
    x = |str| + 5 / |str| * |str| + x  / x - *x_ptr;
    x = *x_ptr + 5 / x + *x_ptr / *x_ptr * *x_ptr;
    b = x > f;
    b = x > x and x < x or not b;
  
end 

def _main_():
begin
end