def z_algorithm(S: str):
    ret = [0] * len(S)
    ret[0] = len(S)
    i, j = 1, 0
    while i < len(S):
        while i + j < len(S) and S[j] == S[i + j]:
            j += 1
        ret[i] = j
        if j == 0:
            i += 1
            continue
        k = 1
        while i + k < len(S) and k + ret[k] < j:
            ret[i + k] = ret[k]
            k += 1
        i, j = i + k, j - k
    return ret
