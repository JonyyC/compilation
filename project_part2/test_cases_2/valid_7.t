def index_int(): returns char*
var 
    type int:index;
    type char*:x;
    type char:z;
    type string: str[50]:"hello world";
begin
    index = 5;
    str = "foobar";
    x = &str[index]; #-> this has to be string, and return char* <-#
    str[index] = z; #-> expect char <-#
    z = *(x - 5);
    str = "barfoo";
    return &str[index];
end


def _main_():
begin
end