function encode(p,f)
    c = zeros(Int64, length(p))
    for i in eachindex(p)
        c[i] = (p[i] + triangle(f))%3
        f[14] = (f[14] + p[i])%3
        circshift!(f, p[i] + 1)
    end
    c
end

function decode(c,f)
    p = zeros(Int64, length(c))
    for i in eachindex(c)
        p[i] = (3 + c[i] - triangle(f))%3
        f[14] = (f[14] + p[i])%3
        circshift!(f, p[i] + 1)
    end
    p
end

function encrypt(p,q)
    for i in 0:26
        f = deepcopy(q)
        circshift!(f, i)
        p = encode(p,f)
        reverse!(p)
    end
    p
end

function decrypt(c,q)
    for i in 0:26
        f = deepcopy(q)
        circshift!(f, 26 - i)
        reverse!(c)
        c = decode(c,f)   
    end
    c
end

function test()
    f = ternary_key()
    print("f = ");print_key(f)
    p = ternary_key()
    print("p = ");print_key(p)
    c = encrypt(p,f)
    print("c = ");print_key(c)
    d = decrypt(c,f)
    print("d = ");print_key(d)
    print("? = ");print_key(p .== d)
end

