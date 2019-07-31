$.ajax({
    type: "get",
    url: "http://127.0.0.1:8888",
    async: true,
    data: {},
    dataType: "json",
    success: function(msg) {
        var obj = msg;
        alert(JSON.stringify(msg));
    },
    error: function {

    }
})