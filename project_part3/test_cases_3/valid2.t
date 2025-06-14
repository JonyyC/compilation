def foo(par1 int:i):
var
    type string:str[50];
    type char*:c;
begin 
    if i > 10 and i <20: str[i] = *(c + 0);

    if i > 10 and i <20:
    begin
        str[i+ 1] = *(c + 1);
    end

    if i > 10 and i <20:
    var 
        type string:str2[50];
    begin
        str2[i+ 2] = *(c + 2);
    end

    str[i/10 + i*10] = *(c + 5);
end 
 
 
def _main_():  
var 
begin 

end 