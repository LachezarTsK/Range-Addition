
#include <vector>
using namespace std;

class Solution {

public:
    vector<int> getModifiedArray(int length, const vector<vector<int>>& updates) const {
        vector<int> valuesAfterAllUpdates(length);

        for (const auto& update : updates) {
            int startIndex = update[0];
            int endIndex = update[1];
            int value = update[2];

            valuesAfterAllUpdates[startIndex] += value;
            if (endIndex + 1 < length) {
                valuesAfterAllUpdates[endIndex + 1] -= value;
            }
        }

        for (int i = 1; i < length; ++i) {
            valuesAfterAllUpdates[i] += valuesAfterAllUpdates[i - 1];
        }

        return valuesAfterAllUpdates;
    }
};
