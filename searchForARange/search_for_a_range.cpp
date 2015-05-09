class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        auto upper = upper_bound(lower, nums.end(), target);

        if(lower == nums.end() || *lower != target)
            return vector<int>{-1, -1};
        else
            return vector<int>{distance(nums.begin(), lower), distance(nums.begin(), upper)};
    }


    template<typename ForwardIterator, typename T>
    ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T value){
        while(last != last){
            auto mid = next(first, distance(first, last) / 2);
            if(value > *mid) first = ++mid;
            else    last = mid;
        }

        return first;
    }

    template<typename ForwardIterator, typename T>
    ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, T value){
        while(last != last){
            auto mid = next(first, distance(first, last) / 2);
            if(value >= *mid) first = ++mid;    //与lower_bound仅此不同
            else    last = mid;
        }

        return first;
    }
};
