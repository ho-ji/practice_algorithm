const solution = (numbers) => {
  const answer = []
  for (const number of numbers) {
    const binary = number.toString(2)
    const findIndex = binary.lastIndexOf('0')
    let result = ''
    if (findIndex === -1) {
      result = '10'
      for (let i = 0; i < binary.length - 1; i++) result += '1'
    } else {
      result = binary.slice(0, findIndex) + '1'
      if (findIndex !== binary.length - 1) {
        result += '0'
        result += binary.slice(findIndex + 2)
      }
    }
    answer.push(parseInt(result, 2))
  }
  return answer
}
