#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class solution {
public:
    std::vector<int> countSmaller(const std::vector<int> & nums) {
	std::vector<int> count;
	std::vector<int> sorted;
	for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
	    auto lb = std::lower_bound(sorted.begin(), sorted.end(), *it);
	    count.push_back(std::distance(sorted.begin(), lb));
	    sorted.insert(lb, *it);
	}
	std::vector<int> result;
	std::reverse_copy(count.begin(), count.end(), std::inserter(result, result.end()));
	return result;
    }
};

int main() {
    std::vector<int> nums{5,2,6,1};

    solution soln;
    auto count = soln.countSmaller(nums);
    std::copy(count.begin(), count.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}
