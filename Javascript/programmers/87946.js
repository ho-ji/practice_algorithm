function solution(k, dungeons) {
  let answer = -1
  let check = []
  const findMax = (fatigue, count) => {
    if (count > answer) answer = count
    for (let i = 0; i < dungeons.length; i++) {
      if (!check[i]) {
        if (dungeons[i][0] <= fatigue) {
          if (fatigue - dungeons[i][1] >= 0) {
            check[i] = true
            findMax(fatigue - dungeons[i][1], count + 1)
            check[i] = false
          }
        }
      }
    }
  }
  findMax(k, 0)
  return answer
}
