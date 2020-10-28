class Solution {
public:
    int cc[366];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        cc[0] = 0;
        int n = days[days.size() - 1 ];
        int j = 0;

        for (int i  = 1;  i <= n; i++) {
            if (i == days[j]) {
                j++;
                int one = cc[max(0, i - 1)] + costs[0];
                int week = cc[max(0, i - 7)] + costs[1];
                int month = cc[max(0, i - 30)] + costs[2];
                cc[i] = min({one, week, month});
            }
            else
                cc[i] = cc[i - 1];
        }
        return cc[n];
    }
};
