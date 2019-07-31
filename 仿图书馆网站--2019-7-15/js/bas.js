$(document).ready(function(){
/*
	var dllen=$("#list dl").length;
	for(var i=0;i<dllen;i++){		
		$("#list dl:eq("+i+")").mousemove(function(){
			for(var j=0;j<dllen;j++){
				$("#list dl").eq(j).removeClass("hov");
			}
			$(this).addClass("hov");

		});
	}
	$(document).click(function(){
		for(var j=0;j<dllen;j++){
				$("#list dl").eq(j).removeClass("hov");
			}
	});
	*/
	$('#user').click(function(){
		if($('#user').val()=='借书证号'){
			$('#user').attr('value','');
		}
		
	});
	$('#user').focusout(function(){
		if($('#user').val()==''){
			$('#user').attr('value','借书证号');
		}
		
	});
	
	$('#pw').click(function(){
		$('#war_pass').html('');
		
		
	});
	$('#pw').focusout(function(){
		if($('#pw').val()==''){
		$('#war_pass').html('密码');
		}
		
		
	});
	$('#tj a').click(function(){
	$(this).attr('href','###');
	$(this).attr('target','');
	});
	
	
//通过学号和姓名查询档案去向
	$('#find_name , #find_xh').click(function(){
		$('#find_war').html('');
		$('#find_war').css('color','green');
	});
	$('#find_btn').click(function(){
		if($.trim($('#find_name').val())!='' && $.trim($('#find_xh').val())!=''){		
			var name=$.trim($('#find_name').val());
			var xh=$.trim($('#find_xh').val());
			ajax(name,xh);
		}
		else{
			$('#find_war').html('请输入姓名和学号！');
			$('#find_war').css('color','red');
		}
	});
 //ajax
function ajax(name,xh){
$.ajax({
        url: 'http://tsg.wuhues.com/my_find/',
        type: "POST",
        dataType: "json",
        data:{name: name, xh: xh},
        success: function (data) {
          //如果返回結果是1那麼正確
         if(data){
			$('#find table').css('display','block');
			$('#find .xm').html(data['name']);
			$('#find .xh').html(data['title']);
			$('#find .zy').html(data['zy']);
			$('#find .daqx').html(data['daqx']);
			$('#find .fdsj').html(data['fdsj']);
			
		 }
		 else{
			$('#find_war').html('没有查到相关信息');
			$('#find_war').css('color','red');
			$('#find table').css('display','none');
		 }

        }
    });
}
	
});