class Solution {
public:
    void adjustHeap(vector<int>& nums, const int& heapSize, int father){
        int leftChild = 2*father + 1;
        int rightChild = 2*father +2;
        int max = father;
        if(leftChild < heapSize && nums[leftChild] > nums[max]) //跟max比较而不是father
            max = leftChild;
        if(rightChild < heapSize && nums[rightChild] > nums[max])
            max = rightChild;
        if(max != father){
            swap(nums[father], nums[max]);
            adjustHeap(nums, heapSize, max); //修改本次调整之后孩子节点的子树
        }
    }

    void buildHeap(vector<int> & nums, const int& heapSize){
        for(int i = heapSize/2; i >= 0; i--){ //二叉树的最后一个非叶子结点为size()/2
            adjustHeap(nums, heapSize, i);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        //solution1 创建一个 priority_queue，维持其大小为k
        // priority_queue<int, vector<int>, greater<int>> q;
        // for(int n: nums){
        //     q.push(n);
        //     if(q.size() > k)
        //         q.pop();
        // }
        // return q.top();

        //solution 2
        int heapSize = nums.size();
        buildHeap(nums, heapSize);

        //删除最大的节点
        for(;k > 1; k--){
            swap(nums[0], nums[heapSize - 1]);
            heapSize--;
            adjustHeap(nums, heapSize, 0);
        }
        return nums[0];
    }
};
