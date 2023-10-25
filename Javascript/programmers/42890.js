function solution(relation) {
  const list = []
  const combi = []
  combi.push([Array(relation[0].length).fill(false), 0])
  while (combi.length !== 0) {
    const [arr, pos] = combi.shift()
    const check = new Set()
    for (let i = 0; i < relation.length; i++) {
      check.add(relation[i].map((v, i) => (arr[i] ? v : '')).join(' '))
    }
    if (check.size === relation.length) {
      if (
        !list.find((item) => {
          const v1 = parseInt(item.map((v) => (v ? 1 : 0)).join(''), 2)
          const v2 = parseInt(arr.map((v) => (v ? 1 : 0)).join(''), 2)
          return (v1 & v2) === v1
        })
      )
        list.push(arr)
    }
    for (let i = pos; i < relation[0].length; i++) {
      arr[i] = true
      combi.push([[...arr], i + 1])
      arr[i] = false
    }
  }
  return list.length
}
