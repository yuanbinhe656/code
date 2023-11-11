var app = getApp()
var page = {
  data: {
    phoneNumber: '',
    message: ''
  },
  onLoad: function () {

  },
  
  // 监听手机号输入
  listenPhoneInput: function(e) {
      this.data.phoneNumber = e.detail.value
  },
 
  // 查询手机号归属地
  queryHome4Phone: function() {
    var page = this
    console.log("手机号是"+ this.data.phoneNumber)
    wx.request({
      url: 'https://zj.v.api.aa1.cn/api/saorao/',
      data: {
        phone: this.data.phoneNumber,
      },
      header: {
        'Content-Type': 'application/json',
      },
      success: function(res) {
        var result = res.data
        console.log(res.data)

          page.setData({
            message: "该号码的归属地是 : "+result.info.province + " " + result.info.city + " " + result.info.operator ,
            msg1 : "该号码经 " + result.data[0].name +" 查询为 "+result.data[0].msg,
            msg2 : "该号码经 " + result.data[1].name +" 查询为 "+result.data[1].msg,
            msg3 : "该号码经 " + result.data[2].name +" 查询为 "+result.data[2].msg
        
          })
        
      }
    })
  },
}
Page(page)