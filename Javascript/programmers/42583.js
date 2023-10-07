function solution(bridge_length, weight, truck_weights) {
  let timer = 0
  const bridge = []
  let pos = 0
  let sum = 0

  while (pos < truck_weights.length || bridge.length !== 0) {
    if (truck_weights[pos] + sum <= weight && bridge.length < bridge_length) {
      bridge.push([truck_weights[pos], timer + bridge_length])
      sum += truck_weights[pos++]
      timer++
    } else {
      const [truck, left] = bridge.shift()
      if (timer < left) timer = left
      sum -= truck
    }
  }
  return timer + 1
}
