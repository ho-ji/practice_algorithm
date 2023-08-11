function solution(nums) {
  var answer = 0
  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      for (let k = j + 1; k < nums.length; k++) {
        let num = nums[i] + nums[j] + nums[k]
        let n = 0
        for (n = 2; n * n <= num; n++) {
          if (num % n === 0) {
            break
          }
        }
        if (n * n > num) answer++
      }
    }
  }
  return answer
}
