var express = require('express');
var app = express();

//  主页输出 "Hello World"
app.get('/', function(req, res) {
    console.log("主页 GET 请求");
    res.send('Hello GET');
})


//  POST 请求
app.post('/', function(req, res) {
    console.log("主页 POST 请求");
    res.send('Hello POST');
})

//  /del_user 页面响应
app.get('/del_user', function(req, res, next) {
    // console.log("/del_user 响应 DELETE 请求");
    // res.send('删除页面');
    console.log(req.body);
    var book = {
        "title": "Professional Javascript",
        "authors": [
            "Nicholas C. Zakas"
        ],
        edition: 3,
        year: 2011,
        releaseDate: new Date(2011, 11, 1)
    };

    // var jsonText = JSON.stringify(book, function(key, value) {
    //     // switch (key) {
    //     //     case "authors":
    //     //         return value.join(",");
    //     //     case "year":
    //     //         return 5000;
    //     //     case "edition":
    //     //         return undefined;
    //     //     default:
    //     //         return value;
    //     // }
    // });
    var jsonText = JSON.stringify(book);
    var bookCopy = JSON.parse(jsonText, function(key, value) {
        if (key == "releaseDate") {
            return new Date(value);
        } else {
            return value;
        }
    });
    res.send(bookCopy.releaseDate.getFullYear());

    next();
})

//  /list_user 页面 GET 请求
app.get('/list_user', function(req, res) {
    console.log("/list_user GET 请求");
    res.send('用户列表页面');
})

// 对页面 abcd, abxcd, ab123cd, 等响应 GET 请求
app.get('/ab*cd', function(req, res) {
    console.log("/ab*cd GET 请求");
    res.send('正则匹配');
})


var server = app.listen(8082, function() {

    var host = server.address().address
    var port = server.address().port

    console.log("应用实例，访问地址为 http://%s:%s", host, port)

})