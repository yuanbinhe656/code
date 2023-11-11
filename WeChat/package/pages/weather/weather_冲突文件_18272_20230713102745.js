// pages/weather/weather.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    selectCode:["110000", "110100", "110101"],
    selectvaule:["北京市", "北京市", "东城区"],
    weeklist:[],
    todayWeather:{}

  },
  selectchange(e){
    
    this.setData({selectCode:e.detail.code})
    this.setData({selectvaule:e.detail.value})
   
    this.getWeekWeatherList()
  },
  //获得未来七天的天气预报
  getWeekWeatherList(){
    let that = this
    //请求网站
    let url = "https://v0.yiketianqi.com/free/week"
    //请求APPID
    let appid = "48922728"
    //请求APP秘钥
    let appsecret = "uu6A3eeO"
    let unescape = 1
    let city = that.data.selectvaule[2].replace("区","").replace("市","")
    
    wx.request({
      url: url,
      method:"GET",
      data:{
        'appid':appid,
        "appsecret":appsecret,
        "unescape":unescape,
        "city":city
      },
      success(res){
        console.log(res)
        if(res.data.data!=undefined&& res.data.data.length>0){
          that.setData({
            weeklist:res.data.data,
            todayWeather:res.data.data[0]
          })
          
        }
      }

    })
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad(options) {
    this.getWeekWeatherList()

   
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady() {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow() {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide() {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload() {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh() {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom() {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage() {

  }
})