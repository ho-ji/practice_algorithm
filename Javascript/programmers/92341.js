const solution = (fees, records) => {
  const answer = []
  let index = -1
  let time = []
  const cars = []

  for (const record of records) {
    const r = record.split(' ')
    cars.push(r)
  }
  cars.sort((v1, v2) => v1[1] - v2[1])

  let carNumber
  for (let i = 0; i < cars.length; i++) {
    if (carNumber !== cars[i][1]) {
      index++
      carNumber = cars[i][1]
    }
    let h1, m1, h2, m2
    ;[h1, m1] = cars[i][0].split(':')
    if (i + 1 !== cars.length && cars[i + 1][1] === carNumber) {
      ;[h2, m2] = cars[i + 1][0].split(':')
      i += 1
    } else {
      ;[h2, m2] = [23, 59]
    }
    const currentTime = parseInt(h2) * 60 + parseInt(m2) - (parseInt(h1) * 60 + parseInt(m1))
    time[index] = time[index] ? time[index] + currentTime : currentTime
  }

  for (let i = 0; i < time.length; i++) {
    let fee = fees[1]
    time[i] -= fees[0]
    if (time[i] > 0) {
      fee += Math.ceil(time[i] / fees[2]) * fees[3]
    }
    answer.push(fee)
  }

  return answer
}
