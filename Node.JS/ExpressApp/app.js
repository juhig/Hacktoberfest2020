const Express = require("express");
const App = Express();


App.get("/", (req, res) => {
    res.sendFile(__dirname + "/markups/index.html");
});




App.listen(3000, () => {
    console.log("Server running at http://localhost:3000");
})