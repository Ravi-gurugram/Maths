class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        // Sort points: by x, then y
        sort(trees.begin(), trees.end(), [](auto &a, auto &b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });

        // Cross product helper
        auto cross = [](vector<int>& o, vector<int>& a, vector<int>& b) {
            return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0]);
        };

        vector<vector<int>> hull;

        // Build lower hull
        for (auto& p : trees) {
            while (hull.size() >= 2 && cross(hull[hull.size()-2], hull.back(), p) < 0) {
                hull.pop_back();
            }
            hull.push_back(p);
        }

        // Build upper hull
        int lower_size = hull.size();
        for (int i = (int)trees.size() - 2; i >= 0; i--) {
            auto p = trees[i];
            while (hull.size() > lower_size && cross(hull[hull.size()-2], hull.back(), p) < 0) {
                hull.pop_back();
            }
            hull.push_back(p);
        }

        // Remove duplicates
        sort(hull.begin(), hull.end());
        hull.erase(unique(hull.begin(), hull.end()), hull.end());

        return hull;
    }
};
