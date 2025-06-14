def bool_check(): returns bool
var 
    type bool:b1,b2:TRUE,b3:FALSE,b4;
    type char:c;
    type char*:c_ptr;
    type int:i;
    type int*:i_ptr;
    type real:r;
    type real*:r_ptr;
begin
    b1 = call bool_check();
    r = *i_ptr;
    r = *r_ptr;
    
    i = *i_ptr;

    i_ptr = &i;
    b1 = &i == &i;
    b2 = &i != &i;

    c_ptr = &c;
    #-> "c_ptr = &r" this should be illegal <-#
    *r_ptr = i;
    
    *i_ptr = i + i * 5 / 2;
    return not b1 and not b2 and not b3 or not b4 ;
end


def _main_():
begin
end