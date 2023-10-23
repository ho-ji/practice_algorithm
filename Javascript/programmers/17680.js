function solution(cacheSize, cities) {
  const cache = []
  let time = 0
  for (const city of cities) {
    const newCity = city.toLowerCase()
    let pos = cache.indexOf(newCity)
    if (pos !== -1) {
      time += 1
      cache.splice(pos, 1)
      cache.push(newCity)
    } else {
      cache.push(newCity)
      time += 5
      if (cache.length > cacheSize) cache.shift()
    }
  }
  return time
}
