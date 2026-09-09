class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long total_projects = 0;
        long long milestones_max = milestones[0];

        for (int i = 0; i < milestones.size(); i++) {
            total_projects += milestones[i];
            milestones_max = max(milestones_max, (long long)milestones[i]);
        }

        long long rest = total_projects - milestones_max;
        if (milestones_max <= rest) return total_projects;
        else return rest * 2 + 1;
    }
};
