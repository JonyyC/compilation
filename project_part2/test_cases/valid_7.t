
def forCheck(par1 int:n): returns int 
var 
    type int:i;  
    type int: sum: 0;
begin
    for ( i = 0 ; i < n ; i = i + 1 ):  
        var
            type int: j;
        begin
            for ( j = i ; j < n ; j = j + 1 ): sum = sum * j;
            sum = sum + i;
        end
    return sum;
end