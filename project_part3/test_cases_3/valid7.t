def foo():
var 
    type bool:x,y;
    type int:i;
begin 
    if x or y : 
    begin
        if x and y: x = x and not y;
        elif x:
        begin
            i = 1;
        end
        else:
        begin
            i = 2;
        end
        i = i * i;
    end
    else:
    var 
        type int:j;
    begin
        j = 1;
        j = j * i;
        if j > 0 or j == 10 and i <= 5:
        begin
            i = i + j;
        end
    end
end 
 
 
def _main_():  
var 
begin 

end 