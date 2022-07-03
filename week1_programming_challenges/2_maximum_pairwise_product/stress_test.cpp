#include<cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product, ((long long)numbers[first])* numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
	
	int max_index1 = -1;
    for (int first = 0; first < n; ++first) {
    	if ( (max_index1 == -1) || (numbers[first] > numbers[max_index1])){
    		max_index1 = first;
		}
    }
    
    int max_index2 = -1;
    for ( int j=0; j< n; ++j){
    	if((j != max_index1) && ((max_index2 == -1) || (numbers[j] >numbers[max_index2]) ))
    		max_index2 = j;
	}
	cout<< max_index1 <<' '<< max_index2 << "\n";
	max_product = ((long long)(numbers[max_index1])) * numbers[max_index2];
    return max_product;
}

int main() {
	while (true){
		int n = rand() % 100 + 2;
		cout << n <<"\n";
		vector<int> a;
		for (int i=0; i<n; ++i){
			a.push_back(rand() % 100000);
		}
		for (int i = 0; i < n; ++i){
			cout<<a[i]<<' ';
		}
		cout<< "\n";
		long long res1 = MaxPairwiseProduct(a);
		long long res2 = MaxPairwiseProductFast(a);
		if(res1 != res2){
			cout<<"Wrong Answer: "<<res1 <<' '<<res2<< "\n";
			break;
		}
		else{
			cout<<"OK\n";
		}
	}
	
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    //std::cout << MaxPairwiseProduct(numbers) << "\n";
    long long result = MaxPairwiseProduct(numbers) ;
    std::cout << result << "\n";
    return 0;
}
