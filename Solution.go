
func getModifiedArray(length int, updates [][]int) []int {
    valuesAfterAllUpdates := make([]int, length)

    for i := range updates {
        startIndex := updates[i][0]
        endIndex := updates[i][1]
        value := updates[i][2]

        valuesAfterAllUpdates[startIndex] += value
        if endIndex + 1 < length {
                valuesAfterAllUpdates[endIndex + 1] -= value
        }
    }

    for i := 1; i < length; i++ {
        valuesAfterAllUpdates[i] += valuesAfterAllUpdates[i - 1]
    }

    return valuesAfterAllUpdates
}
