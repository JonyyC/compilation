def foo(): returns int 
var 
    type int:x; 
begin 
    var  
        type int:y; 
    begin  
        x = 1; 
        y = 2; 
        begin 
            x = 2; 
        end 
        y = 3; 
    end 
    return 0; 
end 

def goo(): returns int 
begin 
    begin 
        begin end   
    end 
    return 0; 
end 

def _main_():
begin
end