function triangle_narrow(f)
    A = "O|\u2594"
    for i in 0:15
        for j in i:(26-i)
            cursor_to( 15 - i,5 + j)
            h = rand(175:255)
            #h= 255
            print(rgb(0,h,0))
            #print(rgb(h,h,h))
            print(A[f[j+1]+1])
            #if rand(0:9) == 0 sleep(0.001) end
        end
        sleep(0.002)
        if i < 15 
            f = next(f,f)
        end 
    end
    cursor_to(17,0)
    f[14]
end
function triangle_wide(f)
    A = "O| "
    for i in 0:15
        for j in i:(26-i)
            cursor_to( 15 - i,5 + 2*j)
            h = rand(0:255)
            print(rgb(0,h,0))
            #print(rgb(h,h,h))
            print(A[f[j+1]+1]," ")
            #if rand(0:9) == 0 sleep(0.001) end
        end
        sleep(0.002)
        if i < 15 
            f = next(f,f)
        end 
    end
    cursor_to(17,0)
    f[14]
end

function demo()
    hide_cursor()
    cls()
    f = ternary_key()
    p = rand(0:2)
    for i in 1:10000
        circshift!(f,1)
        f[14] = (triangle_wide(f) + rand(0:2))%3     
    end
    show_cursor()
end
