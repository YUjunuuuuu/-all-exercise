<?php
$data=array(
    array(
        'id'=>1,
        'name'=>'张三',
        'age'=>18
    ),
    array(
        'id'=>2,
        'name'=>'李斯',
        'age'=>20
    ),
    array(
        'id'=>3,
        'name'=>'二傻子',
        'age'=>18
    ),
    array(
        'id'=>4,
        'name'=>'三棱锥',
        'age'=>19
    )
    );
    if(empty($_GET['id'])){
//没有ID获取全部
//因为http协议中约定，豹纹的内容就是字符串，而我们需要传递给客户端的信息是一个有结构的数据
//这种情况下，我们一般采用JSON作为数据格式
$json=json_encode($data);
echo $json;
    }else{
//传递了ID只获取一条
foreach($data as $item){
    if($item['id']!=$_GET['id']) continue;
    $json=json_encode($item);
    echo $json;
}
    }
    