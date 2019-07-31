var express = require('express'); 
var path = require('path');
var http = require("http");
var URL = require('url');
var HttpServer = function() {
    var _this = this;
    this.app = express();
    this.app.use(express.static('webapp')); //设置静态文件路径	
}; 
HttpServer.prototype.init = function() {
    this.app.listen(8888, function() {
        var host = this.address().address
        var port = this.address().port
        console.log("应用实例，访问地址为 http://%s:%s", host, port)
    });
};
HttpServer.prototype.start = function() {
    var _this = this;
    this.app.get('/', function(request, response) { _this.getIndex(request, response, _this) });
    this.app.get('/ISAPI', function(request, response) { _this.getISAPI(request, response, _this) });
    this.init();
}
HttpServer.prototype.getIndex = function(request, response, _this) {
    request.sendFile(__dirname + "/webapp/" + "ajax-basic.html");
};
HttpServer.prototype.getISAPI = function(request, response, _this) {
    console.log(request.query);
    if (request.method == "GET") {
        console.log("GET");
        http.get(' http://127.0.0.1' + request.url, function(req, res) { 
            var html = ''; 
            req.on('data', function(data) { 
                html += data; 
            }); 
            req.on('end', function() {  
                console.log(html);
                response.send(html); 
            }); 
        }); 
    } else if (request.method == "POST") {
        console.log("GET");
    } else if (request.method == "DELETE") {
        console.log("GET");
    } else if (request.method == "PUT") {
        console.log("GET");
    }


};
module.exports = HttpServer; 