def foo(par1 int:i; par2 int:j):
begin 
#->
    if i > 10: i = j + 5;
    else : j = i + 10;

    if i <20: i = j + 5;
    else : 
    begin
        j = i + 10;
    end
<-#
    if i > 10 and i <20:
    begin
        i = j + 5;
    end
    else : j = i + 10;

    if i > 10 or i <20:
    begin
        i = 5;
    end
    else :
    begin
        j = i + 10;
    end

    
    if i > 10 and i <20:
    var 
        type int:c;
    begin
        i = j + 5 / c;
    end
    else :
    var 
        type int:c;
    begin
        j = i + 10 / c;
    end


end 
 
 
def _main_():  
var 
begin 

end 