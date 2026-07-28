console.log("Worker started");

self.onmessage = async function () {
    console.log("Worker received message");

    try {
        const response = await fetch("https://dummyapi.com/users");

        if (!response.ok) {
            throw new Error(`HTTP Error: ${response.status}`);
        }

        const data = await response.json();

        const users = Array.isArray(data)
            ? data
            : data.users;

        if (!users || users.length === 0) {
            self.postMessage({
                error: "No users found"
            });
            return;
        }

        self.postMessage({
            users: users
        });

    } catch (error) {
        self.postMessage({
            error: "API Error: " + error.message
        });
    }
};