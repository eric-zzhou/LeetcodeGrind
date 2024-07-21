def getMinOperation(change, arr):
    cansub = 0
    check = set((i + 1) for i in range(len(arr)))

    for i, val in enumerate(change):
        if val == 0:
            cansub += 1
        else:
            curr = arr[val - 1]
            if curr in check:
                if curr <= cansub:
                    cansub -= curr
                    arr[val - 1] = 0
                    check.remove(val)
                    continue
        if not check:
            return i

    tot = sum(arr)
    while check and tot < len(change):
        curr = change[tot]
        if curr in check:
            check.remove(curr)
        tot += 1

    if check:
        return -1
    return tot


# change = [1, 0, 1, 3, 2, 1, 0, 3, 1, 1]
# arr = [2, 1, 2]
change = [0, 0, 0, 2, 1, 3, 2]
arr = [1, 3, 2]
print(getMinOperation(change, arr))
