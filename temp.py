def func(k, end):
    i = 0
    while k > 0:
        i += 1
        l3 = ((i % 1000) * (i % 1000)) % 1000
        l3 = (l3 * (i % 1000)) % 1000
        if l3 == end:
            k -= 1
    return i


func(1, 4)
