function solution(nums) {
  const list = [...new Set(nums)]
  return list.length > nums.length / 2 ? nums.length / 2 : list.length
}
