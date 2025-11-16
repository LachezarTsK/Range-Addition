
/**
 * @param {number} length
 * @param {number[][]} updates
 * @return {number[]}
 */
var getModifiedArray = function (length, updates) {
    const valuesAfterAllUpdates = new Array(length).fill(0);
    
    for (let [startIndex, endIndex, value] of updates) {
        valuesAfterAllUpdates[startIndex] += value;
        if (endIndex + 1 < length) {
            valuesAfterAllUpdates[endIndex + 1] -= value;
        }
    }

    for (let i = 1; i < length; ++i) {
        valuesAfterAllUpdates[i] += valuesAfterAllUpdates[i - 1];
    }

    return valuesAfterAllUpdates;
};
