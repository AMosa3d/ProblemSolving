# Problem Link : https://codeforces.com/problemset/problem/1268/a

def increment_string_integer(pattern):
    pattern_list = list(pattern)

    for i in range(len(pattern)-1,-1,-1):
        if ord(pattern_list[i]) == 57:
            pattern_list[i] = '0'
            continue
        pattern_list[i] = chr(ord(pattern_list[i]) + 1)
        break

    return "".join(pattern_list)


if __name__ == "__main__":

    n, k = [int(x) for x in input().split()]
    s = input()
    pattern = s[:k]
    for i in range(n):
        current_pattern_char = pattern[i%k]
        current_string_char = s[i]
        if current_pattern_char == current_string_char:
            continue

        if ord(current_pattern_char) > ord(current_string_char):
            break
        else:
            pattern = increment_string_integer(pattern)
            break
    number_of_patterns = n//k
    number_of_patterns += 1 if n % k != 0 else 0
    res = pattern * number_of_patterns
    res = res[:n]
    print(n)
    print(res)
