class Solution {
public:
    double average(vector<int>& salary) {
        double maxValue = *max_element(salary.begin(), salary.end());
        double minValue = *min_element(salary.begin(), salary.end());
        double sum = accumulate(salary.begin(), salary.end(), - maxValue - minValue);
        return sum / int(salary.size() - 2);
    }
};