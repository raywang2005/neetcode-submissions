class Solution {
public:
    int helper(vector<int>& coins, int amount, vector<int>& seen){
        if(amount == 0){
            return 0;
        }

        if (amount < 0){
            return -1;
        }

        if(seen[amount] != -2){
            return seen[amount];
        }

        set<int> ways;

        for(int i = 0; i < coins.size(); i++){
            int way = helper(coins, amount - coins[i], seen);
            if(way != -1){
                ways.insert(way + 1);
            }
        }

        if (ways.empty()){
            seen[amount] = -1;
            return -1;
        }

        seen[amount] = (*ways.begin());

        return (*ways.begin());
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> seen (amount + 1, -2); 
        return helper(coins, amount, seen);
    }
};
