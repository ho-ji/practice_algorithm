process.stdin.setEncoding('utf8')
process.stdin.on('data', (data) => {
  const [n, m] = data.split(' ')
  let starString = ''
  for (let i = 0; i < n; i++) {
    starString += '*'
  }
  for (let j = 0; j < m; j++) {
    console.log(starString)
  }
})
