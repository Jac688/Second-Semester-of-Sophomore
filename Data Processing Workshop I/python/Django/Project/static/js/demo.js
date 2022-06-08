//背景图片效果

var index = 0;
var timer = null;
var $loginbg = $('#login_wrapper div');
timer = setInterval(auto, 8000)
auto()
function auto() {
    index++
    index = index > 2 ? 0 : index;
    $loginbg.eq(index).animate({ "opacity": "1" }, 8000).siblings().animate({ "opacity": "0" }, 8000)
}

//input动画插入
(function () {
    var speed = 1;
    var timer = null
    var $move = $('.move');
    var timerout = null;
    move(4);

    //move函数是一个递归函数
    function move(i) {
        //如果i<0 清除所有定时器 并且return
        if (i < 0) {
            clearTimeout(timerout);
            clearInterval(timer);
            return;
        }
        clearTimeout(timerout);//每一次先清空终止timeout定时器
        timerout = setTimeout(function () {//每过800毫秒就执行一次
            clearInterval(timer); //清空定时器
            var end = 130 + (i * 60);  //设置每个对象的终止位置
            timer = setInterval(function () {
                speed += 3;          //步长
                var T = $move.eq(i).offset().top + speed;  //对象的top值
                if (T > end) {                             //如果对象top值大于对象终止位置高度
                    T = end;                               //终止下落
                    speed *= -1;                           //对象反向运动 ,也就是弹跳
                    speed *= 0.3;                           //摩擦系数,每次触底都会减少动量 直至停止
                }
                $move.eq(i).css('top', T + 'px');
            }, 20);
            i--;
            move(i)     //递归调用自身再来一遍
        }, 800);
    }
})()
