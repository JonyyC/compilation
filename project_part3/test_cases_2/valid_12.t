#-> this is comment, wont interupt the parser <-# 
def comments(par1 int:n): returns int  #-> this is comment, wont interupt the parser <-# 
var  #-> this is comment, wont interupt the parser <-# 
    type int:i; #-> this is comment, wont interupt the parser <-# 
    type int: sum: 0; #-> this is comment, wont interupt the parser <-# 
begin #-> this is comment, wont interupt the parser <-# 
    for ( i = 0 ; i < n ; i = i + 1 ):  #-> this is comment, wont interupt the parser <-# 
        var  #-> this is comment, wont interupt the parser <-# 
            type int: j;   #-> this is comment, wont interupt the parser <-# 
        begin #-> this is comment, wont interupt the parser <-# 
            for ( j = i ; j < n ; j = j + 1 ): sum = sum * j;   #-> this is comment, wont interupt the parser <-# 
            sum = sum + i;   #-> this is comment, wont interupt the parser <-# 
        end #-> this is comment, wont interupt the parser <-# 
    return sum; #-> this is comment, wont interupt the parser <-# 
end#-> this is comment, wont interupt the parser <-# 

def _main_():
begin
end