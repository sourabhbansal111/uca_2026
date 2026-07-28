const usersDiv = document.getElementById("users");

const worker = new Worker("worker.js");

worker.postMessage("fetchUsers");

worker.onmessage = function (event) {
    const data = event.data;

    if (data.error) {
        usersDiv.textContent = "No users found";
        return;
    }

    const users = data.users;

    if (!users || users.length === 0) {
        usersDiv.textContent = "No users found";
        return;
    }

    users.forEach(user => {
        const div = document.createElement("div");

        div.textContent =
            `${user.name} - ${user.active ? "Active" : "Inactive"}`;

        usersDiv.appendChild(div);
    });
};

worker.onerror = function () {
    usersDiv.textContent = "No users found";
};