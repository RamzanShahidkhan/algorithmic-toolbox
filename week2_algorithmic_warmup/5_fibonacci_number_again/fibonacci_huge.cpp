#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


long long pisano_period(long long m){
	long long current = 0, next = 1;
	long long period = current + next;
	long long i = 0;
	while (i < m*m){
		period = (current + next) % m;
		current = next;
		next = period;
		if (current == 0 && next == 1){
			//break;
			return i + 1;
		}
		i++;
	}
	return 0;
}


long long get_fibonacci_huge_fast(long long n, long long m) {
	long long remainder = n % pisano_period(m);
	long long first = 0;
	long long second = 1;

	long long res = remainder;

	for (int i = 1; i < remainder; i++) {
		res = (first + second) % m;
		first = second;
		second = res;
	}

	return res % m;
	
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout <<get_fibonacci_huge_fast(n, m) << '\n';
}
