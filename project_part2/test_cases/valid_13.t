def if_elifs(par1 int:x; par2 int:y; par3 int:z):
begin
    if x > y and x / 2 > z / 3 and not x != 0:
    begin 
        x = x + y / z ;
    end
    elif x < y or x * 2 < z * 3 or not not x == 0:
    begin
        x = y ;
        y = y * z;
        x = y - z;
    end
    elif x == y: x = x + y ;
    elif x/x+y*20 - 5 != 0: y = y + y + y + x;
    elif x < 0:
    begin
        x = y;
    end
    elif y < 0:
    begin
        y = x ;
    end
end