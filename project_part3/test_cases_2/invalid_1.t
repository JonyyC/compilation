def nested_funcs(par1 int:x1; par2 int:y; par3 int:z; par4 real:f): returns int
var  
    type char*:x; 
    type int*: sum;
    type string: str[10]; 
    type char:c1; 
begin 
    def Func(par1 int:x2; par2 int:y; par3 int:z; par4 real:f):
    begin
        result = a + b;
    end
    *sum = 0;
    y = "foobar"; 
    y = &x;
    x = &y[5];  
    z = *y;        
    z = *(x - 5);       
    y = "barfoo";  
    
    return null;     
end 

def _main_():
begin
end