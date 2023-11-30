function location_code(v,p,d,base)
    span = div(d,2)
    L = length(v)
    sum =0
    for ex in 0:d-1
        sum += ( base^(d-1-ex) ) * v[mod1(p - span + ex, L )]
    end
    sum
end

function key(base, diameter)
    rand(0:base-1,base^diameter )
end