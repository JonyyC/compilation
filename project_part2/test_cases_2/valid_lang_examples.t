def examples():
var 
    type int:i,a,b,j,num,sum,m,n,k,l,x;
begin
    if 3 > 2:    #-> (3>2) also correct <-# 
    var  
        type int:a:7; 
    begin 
        #-> ...statements... <-# 
        i = a+6; 
    end 
    #-> more examples … <-# 
    if a + b > 4 and (num*b <=sum or not m==n): 
    begin j = 3; end 
    else:  
    begin  
        k = 4;  
        while TRUE:  
        begin l = 2; k = l + j; end 
    end 
    if (TRUE): i = 5; 
    if not FALSE:  
    begin  
        j = 3; 
    end 
    else: x = x- 1; 

    while FALSE: x = x + 1; 

    for (i=0; i<10 and a!=sum; i=i+2): 
    begin a = a + i; end 

    do: 
    var 
        type int:a:5; 
    begin 
        a = a + i;  
        i = i + 1; 
    end 
    while : i <= 10; 
end

def _main_():
begin 
    call examples();
end