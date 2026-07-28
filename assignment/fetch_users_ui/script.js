const usersDiv = document.getElementById("users");

const worker = new Worker("./worker.js");

worker.postMessage("fetchUsers");

worker.onmessage = function (event) {
    const { users, error } = event.data;

    if (error || !users || users.length === 0) {
        usersDiv.textContent = "No users found";
        return;
    }

    usersDiv.innerHTML = "";

    users.forEach(user => {
        const p = document.createElement("p");

        p.textContent =
            `${user.name} - ${user.active ? "Active" : "Inactive"}`;

        usersDiv.appendChild(p);
    });
};

worker.onerror = function (event) {
    console.error("Worker Error:", event.message);
    usersDiv.textContent = "No users found";
};