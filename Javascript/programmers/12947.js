function solution(x) {
  let str = x.toString()
  let num = 0
  for (let i = 0; i < str.length; i++) {
    num += parseInt(str[i])
  }
  return !(x % num)
}
