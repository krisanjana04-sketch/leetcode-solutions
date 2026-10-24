class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[] = {0,31,59,90,120,151,181,212,243,273,304,334};
        int a = days[stoi(arriveAlice.substr(0,2))-1] + stoi(arriveAlice.substr(3));
        int b = days[stoi(leaveAlice.substr(0,2))-1] + stoi(leaveAlice.substr(3));
        int c = days[stoi(arriveBob.substr(0,2))-1] + stoi(arriveBob.substr(3));
        int d = days[stoi(leaveBob.substr(0,2))-1] + stoi(leaveBob.substr(3));
        return max(0, min(b,d) - max(a,c) + 1);
    }
};