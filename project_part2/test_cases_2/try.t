def try1():
var  
    type int:x; 
    type int*:y; 
begin 
    x = 5; 
    y = &x; 
    x = 6; 
end 

def try2():
var  
    type char*:x; 
    type string: y[10]; 
    type char:z; 
    
begin 
    var  
        type int:x; 
        type int*:y; 
    begin 
        x = 5; 
        y = &x; 
        x = 6; 

    end 
    
    y = "foobar"; 
    x = &y[5];          
    z = *(x - 5);       
    y = "barfoo";  
end 


def _main_():
begin
end