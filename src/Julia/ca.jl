function ternary_code(v,i)
    s =0
    for x in 0:2
        s += 3^(2-x) * v[mod1(i - 1 + x, 27 )]
    end
    s
end

function next(p,f)
    c = zeros(Int64, length(p))
    for i in eachindex(c)
        c[i] = f[ternary_code(p,i)+1]
        #@printf("found %2d at %2d wrote %2d\n",ternary_code(p,i),i, f[ternary_code(p,i)+1] )
    end
    c
end

function square(f)
    for i in eachindex(f)
        print_key(f)
        print("\n")
        f = encode(f,f)
    end
end




function triangle(f)
    for i in 0:15
        f = next(f,f)
    end 
    f[14]
end

function rectangle_wide(f)
    A = "O|2"
    cls()
    for i in 0:15  
        for j in 0:26
            cursor_to( 15 - i, 5 + 2*j)
            if j + 1 == 14 start_reverse_text() end
            print(A[f[j+1]+1]," ")
            if j + 1 == 14 stop_reverse_text() end
        end
        if i < 15 
            f = encode(f,f)
        end  
    end
    cursor_to(17,0)
    f[14]
end