def if_elifs_else(par1 int:x; par2 int:y; par3 int:z):
begin
    if x < y:
    var
        type char:c1;
        type char:c2;
    begin
        c1 = c2;
    end
    elif y == z:
    var
        type int:a;
        type int:b;
    begin
        if a > b:
        begin
            a = b;
        end
        elif a == b:
        begin
            b = a;
        end
        else:
        begin
            a = a;
        end
    end
    elif z != 0:
    var
        type char:c3;
        type char:c4;
    begin
        c3 = c4;
    end
    else:
    var
        type int:i;
    begin
        i = 0;
        while i < 10:
        begin
            i = i + 1;
        end
        do:
        begin
            while i < 10:
            begin
                i = i + 1;
            end
        end
        while: i > 0;
    end
end

def _main_():
begin
end
