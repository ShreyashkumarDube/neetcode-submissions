class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int dif = 0;

        for(int i=0; i<seats.size(); i++){
            dif += abs(seats[i]-students[i]);
        }
        return dif;
    }
};