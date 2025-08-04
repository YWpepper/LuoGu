#include"Solution.h"


int main() {

    Solution2 solu;
    vector<int> nums =  {0,1,0,3,12};
    // vector<int> nums =  {0};
    solu.moveZeroes(nums);
    cout << "result:" << endl;
    display(nums);
}