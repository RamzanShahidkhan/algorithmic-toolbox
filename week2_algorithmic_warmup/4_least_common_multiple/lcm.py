# python3


def lcm_naive(a, b):
    assert 1 <= a <= 2 * 10 ** 9 and 1 <= b <= 2 * 10 ** 9

    multiple = max(a, b)
    while multiple % a != 0 or multiple % b != 0:
        multiple += 1

    return multiple


def lcm(a, b):
    # assert 1 <= a <= 2 * 10 ** 9 and 1 <= b <= 2 * 10 ** 9
    return (a*b)//gcd(a, b)


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


if __name__ == '__main__':
    input_a, input_b = map(int, input().split())
    print(lcm(input_a, input_b))
