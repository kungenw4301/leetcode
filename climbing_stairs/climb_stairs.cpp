class Climb_Stairs
{
public:
    int climb_stairs(int n){
        int prev = 0, cur = 1, tmp;
        for (int i = 1; i <= n; ++i) //i要从1开始，因为没有0阶的楼梯
        {
            tmp = cur;
            cur += prev;
            prev = tmp; //要记住这个循环，顺序可以有变化
        }
        return cur;
    }
};
