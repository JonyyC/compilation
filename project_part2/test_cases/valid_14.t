def if_elifs_else(par1 int:x; par2 int:y; par3 int:z; par4 int:t):
begin
    if x < y :x = x - y + x ;
    elif x > y : x = x + y - x;
    else: x = x - y ;

    if y + x == t:
    begin 
        x = x - y + x ;
    end
    elif x < y : x = x + y - x;
    else: x = x - y ;

    if z < x:
    begin 
        x = x - y + x ;
    end
    elif z == x : x = x - y - x;
    else: 
    begin
        x = x*x/y+x-y ;
    end

    if t > z != x > z:
    begin 
        x = x - y + x ;
    end
    elif not t > z != x > z :
    begin
        x = x - y - x;
    end
    else: 
    begin
        x = x*x/y+x-y ;
    end

end