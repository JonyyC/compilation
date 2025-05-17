def dereference(): returns int
var  
    type char*:c; 
    type int:x,z; 
    type int*:y; 
begin 
    x = 5; 
    y = &x;     
    x = 6;      
    z = *y;     
    y = null;   
    z = **y;    
    &x = y;       
end