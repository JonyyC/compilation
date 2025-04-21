def dereference(): returns int
var  
    type char*:x; 
    type int*: sum;
    type string: y[10]; 
    type char:z; 
begin 
    *sum = 0;
    y = "foobar"; 
    y = &x;
    x = &y[5];  
    z = *y;        
    z = *(x - 5);       
    y = "barfoo";  
    
    return null;     
end 