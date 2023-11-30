function ternary_key()
    rand(0:2,27)
end


function print_key(f)
    #key_alph = "O|\u2584"
    key_alph = "O|2"
    for i in eachindex(f)
        #h = rand(100:255)
        #print(rgb(h,h,h))
        print(key_alph[f[i]+1], " ")
    end
    print("\n")
end
