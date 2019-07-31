<?php
$name=isset($_POST['name'])?htmlspecialchars($_POST['name']):'';
$city=isset($_POST['city'])?htmlspecialchars($_POST['city']):'';
echo 'Dear '.$name;
echo 'Hope you live well in'.$city;
?>