#include <iostream>
#include <vector>
#include <algorithm>


long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
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

    return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    //std::cout << MaxPairwiseProduct(numbers) << "\n";
    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
