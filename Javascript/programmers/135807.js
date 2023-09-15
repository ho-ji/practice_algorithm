const gcd = (v1, v2) => {
  let a = v1 > v2 ? v1 : v2
  let b = v1 <= v2 ? v1 : v2
  while (b > 0) {
    ;[a, b] = [b, a % b]
  }
  return a
}

function solution(arrayA, arrayB) {
  if (arrayA.length === 1) {
    if (arrayA[0] === arrayB[0]) return 0
    return arrayA[0] > arrayB[0] ? arrayA[0] : arrayB[0]
  }
  let gcdA = gcd(arrayA[0], arrayA[1])
  let gcdB = gcd(arrayB[0], arrayB[1])
  for (let i = 2; i < arrayA.length - 1; i++) {
    gcdA = gcd(gcdA, arrayA[i])
    gcdB = gcd(gcdB, arrayB[i])
  }
  for (let i = 0; i < arrayA.length; i++) {
    if (gcdA) {
      if (arrayB[i] % gcdA === 0) {
        gcdA = false
      }
    }
    if (gcdB) {
      if (arrayA[i] % gcdB === 0) {
        gcdB = false
      }
    }
  }
  if (gcdA) {
    if (gcdA > gcdB) return gcdA
  }
  if (gcdB) return gcdB
  return 0
}
