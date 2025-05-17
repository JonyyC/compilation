def nested_funcs(par1 int:x1; par2 int:y; par3 int:z; par4 real:f): returns int
var  
    type char*:x; 
    type int*: sum;
    type string: str[10]; 
    type char:c1; 
    type int:result;
begin 
    def Func(par1 int:x2; par2 int:y2; par3 int:z2; par4 real:f2):
    begin
        result = x1 + y;
        call nested_funcs(1, 2, 3 , 4);
    end

    *sum = 0;
    str = "foobar"; 
    y = &result;
    x = &str[5];       
    c1 = *(x - 2);       
    
    return result;     
end 