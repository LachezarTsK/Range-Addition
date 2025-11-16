
using System;

public class Solution
{
    public int[] GetModifiedArray(int length, int[][] updates)
    {
        int[] valuesAfterAllUpdates = new int[length];

        foreach (int[] update in updates)
        {
            int startIndex = update[0];
            int endIndex = update[1];
            int value = update[2];

            valuesAfterAllUpdates[startIndex] += value;
            if (endIndex + 1 < length)
            {
                valuesAfterAllUpdates[endIndex + 1] -= value;
            }
        }

        for (int i = 1; i < length; ++i)
        {
            valuesAfterAllUpdates[i] += valuesAfterAllUpdates[i - 1];
        }

        return valuesAfterAllUpdates;
    }
}
