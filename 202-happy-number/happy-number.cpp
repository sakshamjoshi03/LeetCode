class Solution {
public:
    int Usum(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        if(n == 1) return true;
        unordered_set<int>map;

        while(true)
        {
            if( Usum(n) != 1 && map.count(n) == false)
            {
                map.insert(n);
                n = Usum(n);
            }
            else if( Usum(n) != 1 && map.count(n) == true ) return false;
            else if( Usum(n) == 1 ) return true;
        }
    }
};