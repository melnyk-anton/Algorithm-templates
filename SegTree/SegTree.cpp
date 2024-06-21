int N = 0;
vector<int> sgt;
NumArray(vector<int>& nums) {
    N = nums.size();
    sgt.resize(2 * N + 1);
    
    for (int i = 0; i < N; i++)
    {
        sgt[N + i] = nums[i];
    }

    for (int i = N - 1; i > 0; i--)
    {
        sgt[i] = sgt[2 * i] + sgt[2 * i + 1];
    }
}

void update(int index, int val) {
    index += N;
    sgt[index] = val;

    while (index > 1)
    {
        index /= 2;

        sgt[index] = sgt[2 * index] + sgt[2 * index + 1];
    }
}

int sumRange(int left, int right) {
    left += N;
    right += N;

    int sum = 0;
    while (left <= right)
    {
        if (left & 1)
        {
            sum += sgt[left];
            left++;
        }
        if (!(right & 1))
        {
            sum += sgt[right];
            right--;
        }

        left = left >> 1;
        right = right >> 1;
    }

    return sum;
}