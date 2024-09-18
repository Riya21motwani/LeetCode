class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Sort the numbers using Quick Sort
        quickSort(nums, 0, nums.size() - 1);
        // Concatenate sorted numbers to form the largest number
        string largestNum;
        for (int num : nums) {
            largestNum += to_string(num);
        }
        // Handle the case where the largest number is zero
        return largestNum[0] == '0' ? "0" : largestNum;
    }

private:
    void quickSort(vector<int>& nums, int left, int right) {
      
        if (left >= right) return;
        
        int pivotIndex = partition(nums, left, right);
        
        quickSort(nums, left, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int lowIndex = left;
       
        for (int i = left; i < right; ++i) {
            if (compare(nums[i], pivot)) {
                swap(nums[i], nums[lowIndex]);
                ++lowIndex;
            }
        }
        
        swap(nums[lowIndex], nums[right]);
        return lowIndex;
    }

    bool compare(int firstNum, int secondNum) {
        
        return to_string(firstNum) + to_string(secondNum) >
               to_string(secondNum) + to_string(firstNum);
    }
};