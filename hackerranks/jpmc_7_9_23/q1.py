# Complete the function countNumbers, countNUmbers has the following parameters:
# int arr[q][2], Integer pairs representing inclusive lower and upper range limits.
# print. for each pair arr[i], print the number of integers in the inclusive range qualify.

# Input:
# [[1,20], [9,19]]
# Output:
# 19
# 10


def countNumbers(arr):
    maxNum = 0
    for pair in arr:
        if pair[1] > maxNum:
            maxNum = pair[1]
    map = {0: 1}
    for i in range(1, maxNum + 1):
        if len(set(str(i))) == len(str(i)):
            map[i] = map[i - 1] + 1
        else:
            map[i] = map[i - 1]
    for pair in arr:
        print(map[pair[1]] - map[pair[0] - 1])


countNumbers([[7, 8], [52, 80], [34, 84], [57, 64], [74, 78]])
