function courseMenu(){
	var is_first_click=1
	$("#sub-menu").toggle(
		function(){
			if(is_first_click){
				$("#move-course-menu").html($(".course-left").html());
				$(".course-left").remove();
				is_first_click=0
			}
			$("#move-course-menu").show();
		},
		function(){
			$("#move-course-menu").hide();
		}
	);
} 
function scroolFix(){
	if($("#outer-ad-right-sticky").length>0){
		var top=$("#outer-ad-right-sticky").offset().top;
		var scrollT = document.documentElement.scrollTop || document.body.scrollTop; 
		if((scrollT+10)<top){
			$("#ads_tutorial_right").css({"position":"static"});
		}else if((window.innerHeight + window.pageYOffset) >= (document.body.offsetHeight - 700 )){
			$("#ads_tutorial_right").css({"position":"fixed","top":"-700px"});
		}else{
			$("#ads_tutorial_right").css({"position":"fixed","top":"10px"});
		}
	}
	if($("#outer-ad-right-sticky-article").length>0){
		var top=$("#outer-ad-right-sticky-article").offset().top;
		var scrollT = document.documentElement.scrollTop || document.body.scrollTop; 
		if((scrollT+10)<top){
			$("#article_right_bottom").css({"position":"static"});
		}else if((window.innerHeight + window.pageYOffset) >= (document.body.offsetHeight - 700 )){
			$("#article_right_bottom").css({"position":"fixed","top":"-700px"});
		}
		else{
			$("#article_right_bottom").css({"position":"fixed","top":"0px"});
		}
	}
}
function scroolFixc(){
	if($("#outer_float_course").length>0){
		var top=$("#outer_float_course").offset().top;
		var scrollT = document.documentElement.scrollTop || document.body.scrollTop; 
		if((scrollT+10)<top){
			$("#outer_float_course").css({"position":"static"});
		}else{
			$("#outer_float_course").css({"position":"fixed","top":"0px"});
		}
	}
}
$(document).ready(function(){
	courseMenu();
	$(".lanrenzhijia .index_tab a").mouseover(function(){
		$(this).addClass('on').siblings().removeClass('on');
		var index = $(this).index();
		number = index;
		$('.lanrenzhijia .content div').hide();
		$('.lanrenzhijia .content div:eq('+index+')').show();
	});
    if($(window).width() > 767){
        $(window).scroll(function(){
            scroolFix();
        });
    }
    if($(window).width() > 1199){
        $(window).scroll(function(){
            scroolFixc();
        });
    }
})