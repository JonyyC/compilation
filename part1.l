

%%

bool {yylval.node=mknode("BOOL",0); return BOOL_TOK;} // true or false
TRUE|FALSE {yylval.node=mknode(yytext,0); return BOOL;}

char { yylval.node=mknode("CHAR",0);  return CHAR_TOK;} // only  have '[a-z|A-Z]'
\'[a-zA-Z0-9]' {yylval.node=mknode(yytext,0); return CHAR; }  // matches e.g. 'x' or 'A'

par[0-9]+  {printf("cought par: %s\n", yytext);yylval.node=mknode(yytext,0); return PAR; }

int {yylval.node=mknode("INT",0);  return INT_TOK;} // decimal (cant start with zero like 010 but 0 valid) or hex (start with 0x or 0X and digits(0-9, A-F))
0|0[xX][0-9A-F]{4}|-?[1-9][0-9]* {yylval.node=mknode(yytext,0); printf("caught int: %s\n", yytext); return INT;}

real {yylval.node=mknode("REAL",0);  return REAL_TOK;} // similar to double in C. (e.g 3.14, -34.9988, 45.3E-23, -4E+2101, +.2E4, 4.e-67)
-?[0-9]+\.[0-9]*|(0|[1-9][0-9]*)\.[0-9]*[eE][-+]?[0-9]+|[-+]?[0-9]*[eE][-+]?[0-9]+|[-+]\.[0-9]*([eE][-+][0-9]*|[eE][0-9]*)|[0-9]+\. {yylval.node=mknode(yytext,0); printf("caught real: %s\n", yytext);return REAL;}

string {yylval.node=mknode("STRING",0);  return STRING_TOK;} // needs "" 
\"([^\"\\]|\\.)*\" {yylval.node=mknode(yytext,0); printf("String: %s\n", yytext); return STRING; }

int\* {yylval.node=mknode("INT_PTR",0);  return INT_PTR; }
char\* {yylval.node=mknode("CHAR_PTR",0); printf("cought char*: %s\n", yytext); return CHAR_PTR; }
real\* {yylval.node=mknode("REAL_PTR",0);  return REAL_PTR; }

if { return IF; }
elif { return ELIF; }
else { return ELSE; }
while { return WHILE; }
for { return FOR; }
var { return VAR; }
return { return RETURN; }
null { return NULL_TOK;} 
do { return DO; }
returns { return RETURNS; }
begin { return BEG; }
end { return END; }
def { return DEF; }
call { return CALL; }
and {yylval.node=mknode(yytext,0); return AND; }
not {yylval.node=mknode(yytext,0); return NOT; }
or {yylval.node=mknode(yytext,0); return OR; }
\== yylval.node=mknode(yytext,0); { return EQ; }
\>= {yylval.node=mknode(yytext,0); return GE; }
\<= {yylval.node=mknode(yytext,0); return LE; }
\!= {yylval.node=mknode(yytext,0); return NE; }
type {return type; }
[a-zA-Z_][a-zA-Z0-9_]* {printf("retured ID: %s\n", yytext); yylval.node=mknode(yytext,0); return ID; }
[ \t] ;
[\n] {yylineno++;};
. {printf("found non-declared token %s\n", yytext); return yytext[0];}

%%