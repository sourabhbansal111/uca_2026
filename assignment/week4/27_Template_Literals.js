const users = [
    { name: "Alice", age: 53 },
    { name: "Tim", age: 74 }
];

function generateTable() {
    return `
<table>
${users.map(user => `
  <tr>
    <td>${user.name}</td>
    <td>${user.age}</td>
  </tr>`).join("")}
</table>`;
}

console.log(generateTable());