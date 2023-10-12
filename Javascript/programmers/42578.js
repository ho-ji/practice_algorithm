function solution(clothes) {
  let answer = 1
  const closet = {}
  for (const [_, category] of clothes) closet[category] = closet[category] ? closet[category] + 1 : 1

  for (const category in closet) answer *= closet[category] + 1

  return answer - 1
}
