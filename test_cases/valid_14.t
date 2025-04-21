def if_elifs_else(par1 int:x; par2 int:y; par3 int:z):
begin
    if y:
    begin 
        x = x - y + x ;
    end
    elif x : x = x + y - x;
    else: x = x - y ;

    if y:
    begin 
        x = x - y + x ;
    end
    elif x : x = x - y - x;
    else: 
    begin
        x = x*x/y+x-y ;
    end

    
    
end