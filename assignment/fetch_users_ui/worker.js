self.onmessage = async function () {
    try {
        const response = await fetch("https://dummyapi.com/users");

        if (!response.ok) {
            throw new Error("Failed to fetch users");
        }

        const data = await response.json();

        // Handle either [users...] or { users: [users...] }
        const users = Array.isArray(data) ? data : data.users;

        if (!users || users.length === 0) {
            self.postMessage({ error: "No users found" });
            return;
        }

        self.postMessage({ users: users });

    } catch (error) {
        self.postMessage({ error: error.message });
    }
};