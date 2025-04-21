(CODE 
    (FUNC 
        foo 
        (PARS 
            (par1 INT x) 
            (par2 INT y) 
            (par3 INT z) 
            (par4 REAL f) 
        ) 
        (RET NONE) 
        (BODY  
            (IF-ELSE 
                (> x y)  
                (BLOCK  
                    (= x  
                        (+ x y 
                    ) 
                ) 
                (BLOCK  
                    (= y  
                        (+  
                            (+ x y)  
                            z 
                        ) 
                    ) 
                    ( 
                        (= z  
                            (* y 2) 
                        ) 
                        (= f z) 
                    ) 
                ) 
            ) 
        ) 
    ) 
    (FUNC 
        goo 
        (PARS NONE) 
        (RET CHAR) 
        (BODY 
            (RET 'a') 
        ) 
    ) 
    )
)