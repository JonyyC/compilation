def dereference(): returns int
var  
    type char*:x; 
    type string: y[10]; 
    type char:z; 
begin 
    y = "foobar"; 
    x = &y[5];          
    z = *(x - 5);       
    y = "barfoo";    
    
    return 0;   
end 