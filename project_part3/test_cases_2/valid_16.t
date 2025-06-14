def confilct_1(par1 int:x; par2 int:y; par3 int:z):
begin
    if x == y: if y == z: z = x; elif x <= y: if x == z: x = y; else: y = z; elif y >= z: if x == y: y = z; else: z = x; else: if x == y: x = z; elif y == z: y = x; else: z = y;
    elif x != y: if y != z: if x != z: x = y; elif y == z: y = x; else: z = y; elif x == z: if x == y: x = z; else: z = x; else: if x == y: x = z; elif y == z: y = x; else: z = y;

end 

def _main_():
begin
end