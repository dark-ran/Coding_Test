const fs = require("fs");
const file = process.platform === "linux" ? "dev/stdin" : "./text.txt";
const input = fs.readFileSync(file).toString().trim().split("\n");

const t = parseInt(input[0]);
let n = 0;

const arr = input[1].split(" ").map(Number);

const max = Math.max(...arr);
const min = Math.min(...arr);

n = min * max;

console.log(n);