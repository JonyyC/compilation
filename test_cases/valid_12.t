def if_elif(par1 int:x; par2 int:y; par3 int:z):
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
end