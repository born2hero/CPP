#include <iostream>
#include <vector>
#include <unordered_set>

bool twoSum_Onsquare(std::vector<int>& arr, int target){
    // Write your code here.
    for (int i = 0; i < arr.size() - 1; i++){
        for (int j = i + 1; j < arr.size(); j++){
            if (arr[i] + arr[j] == target){
                return true;
            }
        }
    }
    return false;
}

bool twoSum_On(std::vector<int>& arr, int target){
    std::unordered_set<int> nums;
    for (int i = 0; i < arr.size(); i++){
        int complement = target - arr[i];
        if(nums.find(complement) != nums.end()){
            return true;
        }
        nums.insert(arr[i]);
    }
    return false;
}

int main(){
    std::vector<int> arr = {3, 5, -4, 8, 11, 1, -1, 6};
    int target = 10;
    std::cout << twoSum_Onsquare(arr, target) << std::endl;
    std::cout << twoSum_On(arr, target) << std::endl;
}