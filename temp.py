a = 315
b = 840
while b > 0:
    a %= b
    a, b = b, a
print(a)
