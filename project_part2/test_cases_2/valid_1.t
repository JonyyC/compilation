def if_elifs_else(par1 int:x; par2 int:y; par3 int:z):
begin
    if x < y:
    var
        type char:c1; 
        type char:c2; 
        type char:c3; 
    begin
        c1 = c2;
        if x < y: c1 = c3;
    end
    elif y == z:
    var
        type char:c1; 
        type char:c2; 
        type char:c3; 
    begin
        c1 = c2;
    end
    else:
    var
        type char:c1; 
        type char:c2; 
        type char:c3;
    begin
        c1 = c2;
    end
end

def _main_():
begin
end