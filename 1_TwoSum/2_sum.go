package main

import "fmt"

func twoSum(nums []int, target int) []int {
    m := make(map[int]int, len(nums))
    for idx, val := range nums {
        if jdx, ok := m[target - val]; ok {
            return []int{jdx, idx}
        }
        m[val] = idx
    }
    return nil
}