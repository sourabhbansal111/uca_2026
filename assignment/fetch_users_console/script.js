console.log("Main script started");

const worker = new Worker("./worker.js");

console.log("Worker created");

worker.postMessage("fetchUsers");

worker.onmessage = function (event) {
    console.log("Worker response:", event.data);

    const { users, error } = event.data;

    if (error) {
        console.error(error);
        return;
    }

    if (!users || users.length === 0) {
        console.log("No users found");
        return;
    }

    users.forEach(user => {
        console.log(
            `${user.name} - ${user.active ? "Active" : "Inactive"}`
        );
    });
};

worker.onerror = function (event) {
    console.error("WORKER ERROR:", event.message);
};