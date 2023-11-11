//index.js
//获取应用实例
const app = getApp()

Page({
  data: {
    imgUrls: [
      {
        link: '/pages/index/index',
        url: 'https://qny.ggaoda.cn/others/images/swiper/1.jpg',
      }, {
        link: '/pages/logs/logs',
        url: 'https://qny.ggaoda.cn/others/images/swiper/2.png',
      }, {
        link: '/pages/index/index',
        url: 'https://qny.ggaoda.cn/others/images/swiper/3.jpg',
      }
    ],
    indicatorDots: true,  //小点
    autoplay: true,  //是否自动轮播
    interval: 3000,  //间隔时间
    duration: 3000,  //滑动时间
    routers: [
      {
        name: '词典',
        url: '/pages/cidian/cidian',
        icon: 'https://qny.ggaoda.cn/others/images/nine/chengyu.jpg'
      },
      {
        name: '天气查询',
        url: '/pages/weather/weather',
        icon:'https://qny.ggaoda.cn/others/images/nine/weather2.png'
      },
      {
        name: '骚扰电话查询',
        url: '/pages/saorao/saorao',
        icon: 'https://qny.ggaoda.cn/others/images/nine/saorao.png'
      },    
      {
        name: '快递查询',
        url: '/pages/express/express',
        icon: 'https://qny.ggaoda.cn/others/images/nine/kuaidi.jpg'
      },

      {
          name : 'AI聊天',
          url : '/pages/xiaoai/xiaoai',
          icon : 'https://qny.ggaoda.cn/others/images/nine/ai.png'
      },

      {
        name : '看猫',
        url : '/pages/catimg/catimg',
        icon : 'https://qny.ggaoda.cn/others/images/nine/cat.png'
    }

    
    ]
  },
  onLoad: function () {
    console.log('onLoad')
    var that = this
  },
  getUserInfo: function(e) {
    console.log(e)
    app.globalData.userInfo = e.detail.userInfo
    this.setData({
      userInfo: e.detail.userInfo,
      hasUserInfo: true
    })
  }
})
