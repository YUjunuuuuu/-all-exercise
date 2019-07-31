<?php
//接受用户提交的应户名和密码
if(empty($_POST['username'])||empty($_POST['password'])){
   exit('请输入用户名和密码') ;


}
$username=$_POST['username'];
$password=$_POST['password'];
if($username=='admin' && $password=='123'){
    exit('恭喜你');
}
exit('用户名或密码错误');