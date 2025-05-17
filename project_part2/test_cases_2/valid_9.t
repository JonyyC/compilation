def ret_int(par1 int:i): returns int
begin
    return i * i;
end
def state_placement_ptr():  #-> *= <-#
var
    type char:c;
    type char*:c_ptr;
    type int:i;
    type int*:i_ptr;

begin
    call ret_int(i);
    *i_ptr = call ret_int(i);
end

def _main_():
begin
end