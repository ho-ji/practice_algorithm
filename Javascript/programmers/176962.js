function getTime(time) {
  return +time.slice(0, 2) * 60 + +time.slice(3, 5)
}

function solution(plans) {
  let answer = []
  let waitingList = []

  plans.sort((a, b) => (b[1] < a[1] ? 1 : -1))

  for (let i = 0; i < plans.length - 1; i++) {
    let playtime = getTime(plans[i][1]) + +plans[i][2]
    let nextStartTime = getTime(plans[i + 1][1])
    if (playtime > nextStartTime) {
      waitingList.push([plans[i][0], playtime - nextStartTime])
    } else if (playtime === nextStartTime) {
      answer.push(plans[i][0])
    } else {
      answer.push(plans[i][0])
      let leftTime = nextStartTime - playtime
      while (leftTime > 0 && waitingList.length !== 0) {
        let [name, time] = waitingList.pop()
        if (time <= leftTime) {
          answer.push(name)
        } else {
          waitingList.push([name, time - leftTime])
        }
        leftTime -= time
      }
    }
  }
  answer.push(plans[plans.length - 1][0])

  for (let i = waitingList.length - 1; i >= 0; i--) {
    answer.push(waitingList[i][0])
  }
  return answer
}
