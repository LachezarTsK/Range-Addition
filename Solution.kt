
class Solution {

    fun getModifiedArray(length: Int, updates: Array<IntArray>): IntArray {
        val valuesAfterAllUpdates = IntArray(length)

        for ((startIndex, endIndex, value) in updates) {
            valuesAfterAllUpdates[startIndex] += value
            if (endIndex + 1 < length) {
                valuesAfterAllUpdates[endIndex + 1] -= value
            }
        }

        for (i in 1..<length) {
            valuesAfterAllUpdates[i] += valuesAfterAllUpdates[i - 1]
        }

        return valuesAfterAllUpdates
    }
}
